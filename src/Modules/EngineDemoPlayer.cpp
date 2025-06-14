#include "EngineDemoPlayer.hpp"

#include "Checksum.hpp"
#include "Client.hpp"
#include "Console.hpp"
#include "Engine.hpp"
#include "Event.hpp"
#include "Features/Camera.hpp"
#include "Features/Demo/Demo.hpp"
#include "Features/Demo/DemoParser.hpp"
#include "Features/Renderer.hpp"
#include "Hook.hpp"
#include "Interface.hpp"
#include "Modules/FileSystem.hpp"
#include "Offsets.hpp"
#include "SAR.hpp"
#include "Server.hpp"
#include "Utils.hpp"

#include <filesystem>
#include <vector>

REDECL(EngineDemoPlayer::StartPlayback);
REDECL(EngineDemoPlayer::StopPlayback);
REDECL(EngineDemoPlayer::stopdemo_callback);

static std::vector<std::string> g_demoBlacklist;

Variable p2sm_demo_blacklist("p2sm_demo_blacklist", "0", "Stop a set of commands from being run by demo playback.\n");
Variable p2sm_demo_blacklist_all("p2sm_demo_blacklist_all", "0", "Stop all commands from being run by demo playback.\n");
CON_COMMAND(p2sm_demo_blacklist_addcmd, "p2sm_demo_blacklist_addcmd <command> - add a command to the demo blacklist\n") {
	if (args.ArgC() == 1) {
		console->Print(p2sm_demo_blacklist_addcmd.ThisPtr()->m_pszHelpString);
	} else {
		g_demoBlacklist.push_back({args.m_pArgSBuffer + args.m_nArgv0Size});
	}
}

static bool startsWith(const char *pre, const char *str) {
	while (*pre && *str) {
		if (*pre != *str) {
			return false;
		}
		++pre, ++str;
	}

	return !*pre;
}

bool EngineDemoPlayer::ShouldBlacklistCommand(const char *cmd) {
	if (startsWith("p2sm_demo_blacklist", cmd)) {
		return true;
	}

	if (!engine->demoplayer->IsPlaybackFixReady()) {
		// Blacklist all commands while in playback fix
		return true;
	}

	// SPECIAL CASE: these commands override p2sm_demo_blacklist_all, since
	// without them coop timing doesn't work
	if (startsWith("playvideo_end_level_transition", cmd)) return false;
	if (startsWith("stop_transition_videos_fadeout", cmd)) return false;
	if (startsWith("ss_force_primary_fullscreen", cmd)) return false;

	if (p2sm_demo_blacklist_all.GetBool()) return true;

	if (p2sm_demo_blacklist.GetBool()) {
		for (auto &s : g_demoBlacklist) {
			if (startsWith(s.c_str(), cmd)) {
				return true;
			}
		}
	}

	return false;
}

static Variable p2sm_demo_remove_broken("p2sm_demo_remove_broken", "1", "Whether to remove broken frames from demo playback\n");

static bool g_waitingForSession = false;
ON_EVENT(SESSION_START) { g_waitingForSession = false; }

static bool g_demoFixing = false;
static int g_demoStart;
void EngineDemoPlayer::HandlePlaybackFix() {
	if (!g_demoFixing) return;

	// 0 = not done anything
	// 1 = queued skip
	// 2 = in skip
	static int state = 0;

	int tick = GetTick();

	if (state == 0) {
		if (tick > g_demoStart + 2) {
			console->Print("Beginning playback; skipping\n");
			g_waitingForSession = true;
			engine->ExecuteCommand("demo_resume; demo_gototick 1");
			state = 1;
		}
	} else if (state == 1) {
		auto hoststate_run = HS_RUN;
		if (p2sm.game->Is(SourceGame_INFRA)) hoststate_run = INFRA_HS_RUN;
		if (engine->hoststate->m_currentState == hoststate_run && !g_waitingForSession) {
			state = 2;
		}
	} else if (state == 2) {
		if (!IsSkipping()) {
			if (tick % 2 == g_demoStart % 2) {
				console->Print("Correcting start tick\n");
				engine->SendToCommandBuffer("sv_alternateticks 0", 0);
			}
			state = 3;
		}
	} else if (state == 3) {
		if (tick % 2 != g_demoStart % 2) {
			engine->SendToCommandBuffer("sv_alternateticks 1", 0);
			console->Print("Successful start\n");
			Event::Trigger<Event::DEMO_START>({});
			state = 0;
			g_demoFixing = false;
		}
	}
}
bool EngineDemoPlayer::IsPlaybackFixReady() {
	return !g_demoFixing;
}

int EngineDemoPlayer::GetTick() {
	return this->GetPlaybackTick(this->s_ClientDemoPlayer->ThisPtr());
}
bool EngineDemoPlayer::IsPlaying() {
	return this->IsPlayingBack(this->s_ClientDemoPlayer->ThisPtr());
}
bool EngineDemoPlayer::IsPaused() {
	return this->IsPlaybackPaused(this->s_ClientDemoPlayer->ThisPtr());
}
bool EngineDemoPlayer::IsSkipping() {
	return this->IsSkipping_(this->s_ClientDemoPlayer->ThisPtr());
}

void EngineDemoPlayer::SkipTo(int tick, bool relative, bool pause) {
	this->SkipToTick(this->s_ClientDemoPlayer->ThisPtr(), tick, relative, pause);
}

void EngineDemoPlayer::ClearDemoQueue() {
	engine->demoplayer->demoQueue.clear();
	engine->demoplayer->demoQueueSize = 0;
	engine->demoplayer->currentDemoID = -1;
}

std::string EngineDemoPlayer::GetLevelName() {
	return this->levelName;
}

// 0x01: timescale detection
// 0x02: initial cvar
// 0x03: entity input
// 0x04: entity input triggered by slot
// 0x05: portal placement
// 0x06: hit cm flags
// 0x07: got crouchfly
// 0x08: pause duration
// 0x09: 'wait' run
// 0x0A: speedrun finish
// 0x0B: timestamp (UTC)
// 0x0C: file checksum
// 0x0D: 'hwait' run
// 0x0E: entity slot serial changed
// 0x0F: frametime cap detection
// 0x10: queued commands
void EngineDemoPlayer::CustomDemoData(char *data, size_t length) {
	if (data[0] == 0x03 || data[0] == 0x04) {  // Entity input data
		std::optional<int> slot;
		if (data[0] == 0x04) {
			slot = data[1];
			++data;
		}
		char *targetname = data + 1;
		size_t targetnameLen = strlen(targetname);
		char *classname = data + 2 + targetnameLen;
		size_t classnameLen = strlen(classname);
		char *inputname = data + 3 + targetnameLen + classnameLen;
		size_t inputnameLen = strlen(inputname);
		char *parameter = data + 4 + targetnameLen + classnameLen + inputnameLen;

		if (p2sm_show_entinp.GetBool() && sv_cheats.GetBool()) {
			console->Print("%.4d %s.%s(%s)\n", this->GetTick(), targetname, inputname, parameter);
		}

		SpeedrunTimer::TestInputRules(targetname, classname, inputname, parameter, slot);

		return;
	}

	if (data[0] == 0x05) {  // Portal placement
		int slot = data[1];
		PortalColor portal = data[2] ? PortalColor::ORANGE : PortalColor::BLUE;
		Vector pos;
		pos.x = *(float *)(data + 3);
		pos.y = *(float *)(data + 7);
		pos.z = *(float *)(data + 11);

		SpeedrunTimer::TestPortalRules(pos, slot, portal);

		return;
	}

	if (data[0] == 0x06) {  // CM flags
		int slot = data[1];

		SpeedrunTimer::TestFlagRules(slot);

		return;
	}

	if (data[0] == 0x07) {  // Crouch fly
		int slot = data[1];

		SpeedrunTimer::TestFlyRules(slot);

		return;
	}
}

DETOUR_COMMAND(EngineDemoPlayer::stopdemo) {
	engine->demoplayer->ClearDemoQueue();
	EngineDemoPlayer::stopdemo_callback(args);
}

// CDemoPlayer::StartPlayback
DETOUR(EngineDemoPlayer::StartPlayback, const char *filename, bool bAsTimeDemo) {
	auto path = std::string(filename);
	path = fileSystem->FindFileSomewhere(path).value_or(path);
	auto newFilename = path.c_str();
	auto result = EngineDemoPlayer::StartPlayback(thisptr, newFilename, bAsTimeDemo);

	if (result) {
		DemoParser parser;
		Demo demo;
		auto dir = std::string(engine->demoplayer->DemoName);
		if (dir.length() == 0) {
			console->Print("Could not open \"%s\"!\n", newFilename);
		} else if (parser.Parse(dir, &demo)) {
			parser.Adjust(&demo);
			console->Print("Client:   %s\n", demo.clientName);
			console->Print("Map:      %s\n", demo.mapName);
			console->Print("Ticks:    %i\n", demo.playbackTicks);
			console->Print("Time:     %.3f\n", demo.playbackTime);
			console->Print("Tickrate: %.3f\n", demo.Tickrate());
			engine->demoplayer->levelName = demo.mapName;
			g_demoStart = demo.firstPositivePacketTick;
			Renderer::segmentEndTick = demo.segmentTicks;
			if (!p2sm_demo_remove_broken.GetBool()) Event::Trigger<Event::DEMO_START>({});
			g_demoFixing = p2sm_demo_remove_broken.GetBool();
		} else {
			console->Print("Could not parse \"%s\"!\n", engine->demoplayer->DemoName);
		}
	}

	camera->RequestTimeOffsetRefresh();

	Renderer::isDemoLoading = true;

	engine->demoplayer->replayName = newFilename;
	size_t namelen = strlen(newFilename);
	if (Utils::EndsWith(newFilename, ".dem")) {
		engine->demoplayer->replayName = engine->demoplayer->replayName.substr(0, namelen - 4);
	}

	return result;
}

// CDemoPlayer::StopPlayback
DETOUR(EngineDemoPlayer::StopPlayback) {
	if (engine->demoplayer->IsPlaying() && !g_demoFixing) {
		Event::Trigger<Event::DEMO_STOP>({});
	}
	return EngineDemoPlayer::StopPlayback(thisptr);
}

Variable p2sm_demo_portal_interp_fix("p2sm_demo_portal_interp_fix", "1", "Fix eye interpolation through portals in demo playback.\n");

static inline void matrixAngleTransform(VMatrix mat, QAngle *ang) {
	Vector forward, up;
	Math::AngleVectors(*ang, &forward, nullptr, &up);
	forward = mat.VectorTransform(forward);
	up = mat.VectorTransform(up);
	Math::VectorAngles(forward, up, ang);
}

static struct {
	bool in_portal;
	Vector pos;
	Vector norm;
	VMatrix mat;
	bool set_limits;
	float saved_interplimit;
	float saved_avellimit;
} g_portal_interp_state[2];

void EngineDemoPlayer::OverrideView(ViewSetup *view) {
	if (!this->IsPlaying()) return;
	if (!p2sm_demo_portal_interp_fix.GetBool()) return;

	int slot = GET_SLOT();

	if (g_portal_interp_state[slot].in_portal) {
		Vector portal_to_cam = view->origin - g_portal_interp_state[slot].pos;
		if (g_portal_interp_state[slot].norm.Dot(portal_to_cam) < 0.0f) {
			// behind portal - translate view
			VMatrix mat = g_portal_interp_state[slot].mat;
			view->origin = mat.PointTransform(view->origin);
			matrixAngleTransform(mat, &view->angles);
		}

		// invalidate state (until recalculated by the hook below) to avoid
		// this being accidentally set persistently somehow
		g_portal_interp_state[slot].in_portal = false;
	}

	if (g_portal_interp_state[slot].set_limits) {
		// now we're here, restore interplimit and avellimit
		Variable("demo_interplimit").SetValue(g_portal_interp_state[slot].saved_interplimit);
		Variable("demo_avellimit").SetValue(g_portal_interp_state[slot].saved_avellimit);
		g_portal_interp_state[slot].set_limits = false;
	}
}

static void (__rescall *InterpolateDemoCommand)(void *thisptr, int slot, int target_tick, DemoCommandQueue &prev, DemoCommandQueue &next);

#ifdef _WIN32
void __fastcall InterpolateDemoCommand_Detour(void *thisptr, void *unused, int slot, int target_tick, DemoCommandQueue &prev, DemoCommandQueue &next);
#else
void InterpolateDemoCommand_Detour(void *thisptr, int slot, int target_tick, DemoCommandQueue &prev, DemoCommandQueue &next);
#endif

static Hook InterpolateDemoCommand_Hook(&InterpolateDemoCommand_Detour);

#ifdef _WIN32
void __fastcall InterpolateDemoCommand_Detour(void *thisptr, void *unused, int slot, int target_tick, DemoCommandQueue &prev, DemoCommandQueue &next)
#else
void InterpolateDemoCommand_Detour(void *thisptr, int slot, int target_tick, DemoCommandQueue &prev, DemoCommandQueue &next)
#endif
{
	InterpolateDemoCommand_Hook.Disable();
	InterpolateDemoCommand(thisptr, slot, target_tick, prev, next);
	InterpolateDemoCommand_Hook.Enable();

	if (p2sm_demo_portal_interp_fix.GetBool()) {
		if (!g_portal_interp_state[slot].set_limits) {
			g_portal_interp_state[slot].saved_interplimit = Variable("demo_interplimit").GetFloat();
			g_portal_interp_state[slot].saved_avellimit = Variable("demo_avellimit").GetFloat();
		} else {
			// a frame was somehow missed by OverrideView??
			// we want the limits to be normal for now, we'll make them high again
			// later if we need to
			Variable("demo_interplimit").SetValue(g_portal_interp_state[slot].saved_interplimit);
			Variable("demo_avellimit").SetValue(g_portal_interp_state[slot].saved_avellimit);
		}

		g_portal_interp_state[slot].in_portal = false; // we'll set this later
		g_portal_interp_state[slot].set_limits = false;

		// are we currently in a portal bubble?
		ClientEnt *player = client->GetPlayer(slot + 1);
		if (!player) return;
		CBaseHandle portal_handle = player->field<CBaseHandle>("m_hPortalEnvironment");
		ClientEnt *portal_ent = client->GetPlayer(portal_handle.GetEntryIndex());
		if (!portal_ent) return;

		// we'll also need the linked portal later
		CBaseHandle linked_handle = portal_ent->field<CBaseHandle>("m_hLinkedPortal");
		ClientEnt *linked = client->GetPlayer(linked_handle.GetEntryIndex());
		if (!linked) return;


		// this fix currently only works for wall portals, since we're just
		// translating the player origin rather than their camera. for any portal
		// that's not mostly on a wall, just give up
		Vector portal_norm, linked_norm;
		Math::AngleVectors(portal_ent->abs_angles(), &portal_norm);
		Math::AngleVectors(linked->abs_angles(), &linked_norm);
		if (fabsf(portal_norm.Dot(Vector{0,0,1})) > 0.15f) return;
		if (fabsf(linked_norm.Dot(Vector{0,0,1})) > 0.15f) return;

		// set stupid high interplimit and avellimit so it interps properly, since
		// portal passthroughs are a thing that sorta might happen
		// we'll correct these later
		Variable("demo_interplimit").SetValue(1e10f);
		Variable("demo_avellimit").SetValue(1e10f);
		g_portal_interp_state[slot].set_limits = true;

		// we are in a portal bubble for one we can lerp through! so, does the next
		// command seem to move our view very far away? if it does, this probably
		// indicates a portal passthrough.
		Vector prev_cam = prev.info.u[slot].viewOrigin;
		Vector next_cam = next.info.u[slot].viewOrigin;
		float dist_sq = (next_cam - prev_cam).SquaredLength();
		if (dist_sq < 10000) return;

		// okay yeah, we're moving over 100 units this tick, that's pretty
		// suspicious. let's try and figure out what's going on.

		// allowing for a bit of desync between portal env and camera
		// position, there are 2 possibilities: we might be in the source or
		// the destination environment. find which portal we're closest to
		// in 'prev', and treat that one as the entry portal.
		{
			Vector main_pos = portal_ent->abs_origin();
			Vector linked_pos = linked->abs_origin();
			float main_dist = (main_pos - prev_cam).SquaredLength();
			float linked_dist = (linked_pos - prev_cam).SquaredLength();
			if (linked_dist < main_dist) {
				// we're closer to the linked portal - swap them
				ClientEnt *tmp = linked;
				linked = portal_ent;
				portal_ent = tmp;
			}
		}

		ClientEnt *entry = portal_ent;
		ClientEnt *exit = linked;

		// get a bunch of info we need
		Vector entry_pos = entry->abs_origin();
		//Vector exit_pos = exit->abs_origin();
		Vector entry_norm = entry == portal_ent ? portal_norm : linked_norm;
		//Vector exit_norm = exit == portal_ent ? portal_norm : linked_norm;
		VMatrix forward_matrix = entry->field<VMatrix>("m_matrixThisToLinked");
		VMatrix backward_matrix = exit->field<VMatrix>("m_matrixThisToLinked");

		// we're pretty sure we're transitioning from entry to exit. as a
		// sanity check, ensure that we start in front of entry and finish
		// in front of exit. XXX: okay let's not, this doesn't necessarily work for
		// slightly-slanted portals since this is the player origin rather than the
		// camera
		/*
		if (entry_norm.Dot(prev_cam - entry_pos) < 0.0f) return; // starting behind entry portal
		if (exit_norm.Dot(next_cam - exit_pos) < 0.0f) return; // finishing behind exit portal
		*/

		// okay yeah, we're good. now, adjust the next position and angles
		// to act as if we didn't actually pass through the portal (so we
		// finish behind the entry portal)
		next.info.u[slot].viewOrigin = backward_matrix.PointTransform(next.info.u[slot].viewOrigin);
		next.info.u[slot].viewOrigin2 = backward_matrix.PointTransform(next.info.u[slot].viewOrigin2);
		matrixAngleTransform(backward_matrix, &next.info.u[slot].viewAngles);
		matrixAngleTransform(backward_matrix, &next.info.u[slot].viewAngles2);
		matrixAngleTransform(backward_matrix, &next.info.u[slot].localViewAngles);
		matrixAngleTransform(backward_matrix, &next.info.u[slot].localViewAngles2);

		// lastly, set our state so that we can correctly translate the
		// camera through the portal plane.
		g_portal_interp_state[slot].in_portal = true;
		g_portal_interp_state[slot].pos = entry_pos;
		g_portal_interp_state[slot].norm = entry_norm;
		g_portal_interp_state[slot].mat = forward_matrix;
	}
}

bool EngineDemoPlayer::Init() {
	auto disconnect = engine->cl->Original(Offsets::Disconnect);
	auto demoplayer = Memory::DerefDeref<void *>(disconnect + Offsets::demoplayer);
	if (this->s_ClientDemoPlayer = Interface::Create(demoplayer)) {
		this->s_ClientDemoPlayer->Hook(EngineDemoPlayer::StartPlayback_Hook, EngineDemoPlayer::StartPlayback, Offsets::StartPlayback);
		this->s_ClientDemoPlayer->Hook(EngineDemoPlayer::StopPlayback_Hook, EngineDemoPlayer::StopPlayback, Offsets::StopPlayback);

		this->GetPlaybackTick = s_ClientDemoPlayer->Original<_GetPlaybackTick>(Offsets::GetPlaybackTick);
		this->IsPlayingBack = s_ClientDemoPlayer->Original<_IsPlayingBack>(Offsets::IsPlayingBack);
		this->IsPlaybackPaused = s_ClientDemoPlayer->Original<_IsPlaybackPaused>(Offsets::IsPlaybackPaused);
		this->IsSkipping_ = s_ClientDemoPlayer->Original<_IsSkipping>(Offsets::IsSkipping);
		this->SkipToTick = s_ClientDemoPlayer->Original<_SkipToTick>(Offsets::SkipToTick);
		this->DemoName = reinterpret_cast<char *>((uintptr_t)demoplayer + Offsets::m_szFileName);
	}

	InterpolateDemoCommand = (decltype(InterpolateDemoCommand))Memory::Scan(this->Name(), Offsets::InterpolateDemoCommand);

	InterpolateDemoCommand_Hook.SetFunc(InterpolateDemoCommand);

	Command::Hook("stopdemo", EngineDemoPlayer::stopdemo_callback_hook, EngineDemoPlayer::stopdemo_callback);

	this->currentDemoID = -1;
	this->demoQueueSize = 0;

	return this->hasLoaded = this->s_ClientDemoPlayer;
}
void EngineDemoPlayer::Shutdown() {
	Interface::Delete(this->s_ClientDemoPlayer);
	Command::Unhook("stopdemo", EngineDemoPlayer::stopdemo_callback);
}

// Commands

DECL_COMMAND_FILE_COMPLETION(p2sm_startdemos, ".dem", "", 1)
DECL_COMMAND_FILE_COMPLETION(p2sm_startdemosfolder, "/", "", 1)

CON_COMMAND_F_COMPLETION(p2sm_startdemos, "p2sm_startdemos <demoname> - improved version of startdemos. Use 'stopdemo' to stop playing demos\n", 0, AUTOCOMPLETION_FUNCTION(p2sm_startdemos)) {
	// Always print a useful message for the user if not used correctly
	if (args.ArgC() != 2) {
		return console->Print(p2sm_startdemos.ThisPtr()->m_pszHelpString);
	}

	engine->demoplayer->demoQueue.clear();

	std::string name = args[1];

	std::string dirPath = fileSystem->FindFileSomewhere(name).value_or(name);
	if (std::filesystem::is_directory(dirPath)) {
		console->Print("%s is a directory. Using p2sm_startdemosfolder\n", dirPath.c_str());
		engine->ExecuteCommand(Utils::ssprintf("p2sm_startdemosfolder \"%s\"", dirPath.c_str()).c_str());
		return;
	}

	if (name.length() > 4) {
		if (name.substr(name.length() - 4, 4) == ".dem")
			name.resize(name.length() - 4);
	}

	Demo demo;
	DemoParser parser;
	bool ok = parser.Parse(name, &demo);

	if (!ok) {
		return console->Print("Could not parse \"%s\"!\n", args[1]);
	}

	engine->demoplayer->demoQueue.push_back(name);

	int counter = 2;

	{
		size_t idx = name.rfind('_');
		if (idx != std::string::npos) {
			auto part = name.substr(idx + 1, name.size() - idx - 1);
			char *endptr;
			long num = strtol(part.c_str(), &endptr, 10);
			if (!*endptr) {
				// The thing is a number!
				name = name.substr(0, idx);
				counter = num + 1;
			}
		}
	}

	while (ok) {
		auto tmp_dir = name + "_" + std::to_string(counter);
		ok = parser.Parse(tmp_dir, &demo);
		if (ok) {
			engine->demoplayer->demoQueue.push_back(name + "_" + std::to_string(counter));
		}
		++counter;
	}

	engine->demoplayer->demoQueueSize = engine->demoplayer->demoQueue.size();
	engine->demoplayer->currentDemoID = 0;

	EngineDemoPlayer::stopdemo_callback(args);

	//Demos are played in Engine::Frame
}
CON_COMMAND_F_COMPLETION(p2sm_startdemosfolder, "p2sm_startdemosfolder <folder name> - plays all the demos in the specified folder by alphabetic order\n", 0, AUTOCOMPLETION_FUNCTION(p2sm_startdemosfolder)) {
	if (args.ArgC() < 2) {
		return console->Print(p2sm_startdemosfolder.ThisPtr()->m_pszHelpString);
	}

	engine->demoplayer->demoQueue.clear();

	auto dir = fileSystem->FindFileSomewhere(args[1]).value_or(args[1]);
	if (!std::filesystem::is_directory(dir)) {
		return console->Print("Invalid folder \"%s\"\n", args[1]);
	}
	std::string filepath;
	Demo demo;
	DemoParser parser;

	for (const auto &file : std::filesystem::directory_iterator(dir)) {
		try {
			if (file.path().extension() != ".dem")
				continue;

			filepath = args[1];
			if (filepath[filepath.size() - 1] != '/') filepath += "/";
			filepath += file.path().filename().string();
			console->Print("%s\n", filepath.c_str());
			if (parser.Parse(filepath, &demo)) {
				engine->demoplayer->demoQueue.push_back(filepath);
			}
		} catch (std::system_error &e) {
			(void)e;
		}
	}

	std::sort(engine->demoplayer->demoQueue.begin(), engine->demoplayer->demoQueue.end(),
	[](const std::string &a, const std::string &b) {
		auto extractNumber = [](const std::string &str) -> int {
			size_t underscorePos = str.find_last_of('_');
			if (underscorePos != std::string::npos) {
				try {
					return std::stoi(str.substr(underscorePos + 1));
				} catch (std::invalid_argument &) {
					return 0;
				}
			}
			return 0;
		};

		std::string aName = a, bName = b;
		aName.erase(aName.size() - 4);
		bName.erase(bName.size() - 4);
		size_t aSlash = aName.find_last_of('/'), bSlash = bName.find_last_of('/');
		if (aSlash != std::string::npos) aName = aName.substr(aSlash + 1);
		if (bSlash != std::string::npos) bName = bName.substr(bSlash + 1);
		size_t aUnder = aName.find_last_of('_'), bUnder = bName.find_last_of('_');
		std::string aBase = (aUnder != std::string::npos) ? aName.substr(0, aUnder) : aName;
		std::string bBase = (bUnder != std::string::npos) ? bName.substr(0, bUnder) : bName;
		if (aBase == bBase) {
			int aNum = extractNumber(aName), bNum = extractNumber(bName);
			if (aNum != 0 && bNum != 0) return aNum < bNum;
			return aNum == 0;
		}
		return aBase < bBase;
	});	

	engine->demoplayer->demoQueueSize = engine->demoplayer->demoQueue.size();
	engine->demoplayer->currentDemoID = 0;

	EngineDemoPlayer::stopdemo_callback(args);
}
CON_COMMAND_COMPLETION(p2sm_skiptodemo, "p2sm_skiptodemo <demoname> - skip demos in demo queue to this demo\n", ({engine->demoplayer->demoQueue})) {
	if (args.ArgC() < 2) {
		return console->Print(p2sm_skiptodemo.ThisPtr()->m_pszHelpString);
	}

	auto it = std::find(engine->demoplayer->demoQueue.begin(), engine->demoplayer->demoQueue.end(), args[1]);
	if (it == engine->demoplayer->demoQueue.end())
		return;

	engine->demoplayer->currentDemoID = std::distance(engine->demoplayer->demoQueue.begin(), it);

	EngineDemoPlayer::stopdemo_callback(args);
}
CON_COMMAND(p2sm_nextdemo, "p2sm_nextdemo - plays the next demo in demo queue\n") {
	if (++engine->demoplayer->currentDemoID >= engine->demoplayer->demoQueueSize) {
		return engine->demoplayer->ClearDemoQueue();
	}

	EngineDemoPlayer::stopdemo_callback(args);
}
CON_COMMAND(p2sm_demo_replay, "p2sm_demo_replay - play the last recorded or played demo\n") {
	if (engine->demoplayer->replayName.size() == 0) {
		return console->Print("No demo to replay\n");
	}

	console->Print("Replaying \"%s\"\n", engine->demoplayer->replayName.c_str());
	engine->ExecuteCommand(Utils::ssprintf("playdemo \"%s\"", engine->demoplayer->replayName.c_str()).c_str());
}
