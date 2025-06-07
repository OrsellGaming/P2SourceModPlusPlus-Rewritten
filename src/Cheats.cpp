#include "Cheats.hpp"

#include "Event.hpp"
#include "Features/Cvars.hpp"
#include "Features/Hud/Hud.hpp"
#include "Features/Listener.hpp"
#include "Features/OverlayRender.hpp"
#include "Features/Timer/Timer.hpp"
#include "Features/WorkshopList.hpp"
#include "Game.hpp"
#include "Modules/Client.hpp"
#include "Modules/Console.hpp"
#include "Modules/Engine.hpp"
#include "Modules/Server.hpp"
#include "Offsets.hpp"

#include <cstring>

Variable p2sm_autorecord("p2sm_autorecord", "0", -1, 1, "Enables or disables automatic demo recording.\n");
Variable p2sm_autojump("p2sm_autojump", "0", "Enables automatic jumping on the server.\n");
Variable p2sm_autostrafe("p2sm_autostrafe", "0", "Automatically strafes in your current wishdir.\n");
Variable p2sm_ensure_slope_boost("p2sm_ensure_slope_boost", "0", "Ensures a successful slope boost.\n");
Variable p2sm_jumpboost("p2sm_jumpboost", "0", 0,
                       "Enables special game movement on the server.\n"
                       "0 = Default,\n"
                       "1 = Orange Box Engine,\n"
                       "2 = Pre-OBE.\n");
Variable p2sm_aircontrol("p2sm_aircontrol", "0", 0, 2, "Enables more air-control on the server.\n");
Variable p2sm_duckjump("p2sm_duckjump", "0", "Allows duck-jumping even when fully crouched, similar to prevent_crouch_jump.\n");
Variable p2sm_disable_challenge_stats_hud("p2sm_disable_challenge_stats_hud", "0", -1, "Disables opening the challenge mode stats HUD. Greater than 1 specifies a custom amount of ticks to leave leaderboard open. -1 closes instantly.\n");
Variable p2sm_disable_challenge_stats_hud_partner("p2sm_disable_challenge_stats_hud_partner", "1", "Closes the challenge mode stats HUD after your coop partner does.\n");
Variable p2sm_disable_steam_pause("p2sm_disable_steam_pause", "0", "Prevents pauses from steam overlay.\n");
Variable p2sm_disable_no_focus_sleep("p2sm_disable_no_focus_sleep", "0", "Does not yield the CPU when game is not focused.\n");
Variable p2sm_disable_progress_bar_update("p2sm_disable_progress_bar_update", "0", 0, 2, "Disables excessive usage of progress bar.\n");
Variable p2sm_prevent_mat_snapshot_recompute("p2sm_prevent_mat_snapshot_recompute", "0", "Shortens loading times by preventing state snapshot recomputation.\n");
Variable p2sm_challenge_autostop("p2sm_challenge_autostop", "0", 0, 3, "Automatically stops recording demos when the leaderboard opens after a CM run. If 2, automatically appends the run time to the demo name.\n");
Variable p2sm_show_entinp("p2sm_show_entinp", "0", "Print all entity inputs to console.\n");
Variable p2sm_force_qc("p2sm_force_qc", "0", 0, 1, "When ducking, forces view offset to always be at standing height. Requires sv_cheats to work.\n");
Variable p2sm_patch_bhop("p2sm_patch_bhop", "0", 0, 1, "Patches bhop by limiting wish direction if your velocity is too high.\n");
Variable p2sm_patch_cfg("p2sm_patch_cfg", "0", 0, 1, "Patches Crouch Flying Glitch.\n");
Variable p2sm_prevent_ehm("p2sm_prevent_ehm", "0", 0, 1, "Prevents Entity Handle Misinterpretation (EHM) from happening.\n");
Variable p2sm_disable_weapon_sway("p2sm_disable_weapon_sway", "0", 0, 1, "Disables the viewmodel lagging behind.\n");
Variable p2sm_disable_viewmodel_shadows("p2sm_disable_viewmodel_shadows", "0", 0, 1, "Disables the shadows on the viewmodel.\n");
Variable p2sm_floor_reportals("p2sm_floor_reportals", "0", "Toggles floor reportals. Requires cheats.\n", FCVAR_CHEAT);

Variable sv_laser_cube_autoaim;
Variable ui_loadingscreen_transition_time;
Variable ui_loadingscreen_fadein_time;
Variable ui_loadingscreen_mintransition_time;
Variable ui_transition_effect;
Variable ui_transition_time;
Variable ui_pvplobby_show_offline;
Variable mm_session_sys_delay_create_host;
Variable hide_gun_when_holding;
Variable r_flashlightbrightness;

// TSP only
void IN_BhopDown(const CCommand& args) {
	if (!client->KeyDown || !client->in_jump) return;
	client->KeyDown(client->in_jump, (args.ArgC() > 1) ? args[1] : nullptr);
}
void IN_BhopUp(const CCommand& args) {
	if (!client->KeyUp || !client->in_jump) return;
	client->KeyUp(client->in_jump, (args.ArgC() > 1) ? args[1] : nullptr);
}

Command startbhop("+bhop", IN_BhopDown, "Client sends a key-down event for the in_jump state.\n");
Command endbhop("-bhop", IN_BhopUp, "Client sends a key-up event for the in_jump state.\n");

CON_COMMAND(p2sm_anti_anti_cheat, "p2sm_anti_anti_cheat - turns on cheats without the Narrator noticing\n") {
	sv_cheats.ThisPtr()->m_nValue = 1;
}

// P2 only
CON_COMMAND(p2sm_togglewait, "p2sm_togglewait - enables or disables \"wait\" for the command buffer\n") {
	auto state = !*engine->m_bWaitEnabled;
	*engine->m_bWaitEnabled = *engine->m_bWaitEnabled2 = state;
	console->Print("%s wait!\n", (state) ? "Enabled" : "Disabled");
}

CON_COMMAND(p2sm_autoaim_point, "p2sm_autoaim_point <x> <y> <z> - automatically aims at a point in space. Requires cheats\n") {
	if (args.ArgC() != 4) {
		return console->Print(p2sm_autoaim_point.ThisPtr()->m_pszHelpString);
	}
	if (!sv_cheats.GetBool()) {
		return console->Print("p2sm_autoaim_point requires sv_cheats 1.\n");
	}

	auto player = client->GetPlayer(GET_SLOT() + 1);
	if (!player) return;
	
	Vector cam = client->GetAbsOrigin(player) + client->GetViewOffset(player) + client->GetPortalLocal(player).m_vEyeOffset;
	Vector target = Vector(atof(args[1]), atof(args[2]), atof(args[3]));
	Vector forward = target - cam;

	float pitch = -atan2f(forward.z, forward.Length2D());
	float yaw = atan2f(forward.y, forward.x);
	pitch *= 180.0f / M_PI;
	yaw *= 180.0f / M_PI;

	engine->ExecuteCommand(Utils::ssprintf("setang %f %f\n", pitch, yaw).c_str());
}

CON_COMMAND(p2sm_delete_alias_cmds, "p2sm_delete_alias_cmds - deletes all alias commands\n") {
	using _Cmd_Shutdown = int (*)();
	static _Cmd_Shutdown Cmd_Shutdown = nullptr;

	if (!Cmd_Shutdown) {
		auto result = Memory::MultiScan(engine->Name(), Offsets::Cmd_ShutdownSig, Offsets::Cmd_ShutdownOff);
		if (!result.empty()) {
			for (auto const &addr : result) {
				if (!std::strcmp(*reinterpret_cast<char **>(addr), "Cmd_Shutdown()")) {
					Cmd_Shutdown = Memory::Read<_Cmd_Shutdown>(addr + Offsets::Cmd_ShutdownOff2);
					break;
				}
			}
		}
	}

	if (Cmd_Shutdown) {
		Cmd_Shutdown();
	} else {
		console->Print("Unable to find Cmd_Shutdown() function!\n");
	}
}

DECL_AUTO_COMMAND_COMPLETION(p2sm_fast_load_preset, ({"none", "sla", "normal", "full"}))
CON_COMMAND_F_COMPLETION(p2sm_fast_load_preset, "p2sm_fast_load_preset <preset> - sets all loading fixes to preset values\n", FCVAR_DONTRECORD, AUTOCOMPLETION_FUNCTION(p2sm_fast_load_preset)) {
	if (args.ArgC() != 2) {
		console->Print(p2sm_fast_load_preset.ThisPtr()->m_pszHelpString);
		return;
	}

	const char *preset = args.Arg(1);

#define CMD(x) engine->ExecuteCommand(x)
	if (!strcmp(preset, "none")) {
		if (!Game::IsSpeedrunMod() && ui_loadingscreen_transition_time.ThisPtr()) {
			CMD("ui_loadingscreen_transition_time 1.0");
			CMD("ui_loadingscreen_fadein_time 1.0");
			CMD("ui_loadingscreen_mintransition_time 0.5");
		}
		CMD("p2sm_disable_progress_bar_update 0");
		CMD("p2sm_prevent_mat_snapshot_recompute 0");
		CMD("p2sm_loads_uncap 0");
		CMD("p2sm_loads_norender 0");
	} else if (!strcmp(preset, "sla")) {
		if (!Game::IsSpeedrunMod() && ui_loadingscreen_transition_time.ThisPtr()) {
			CMD("ui_loadingscreen_transition_time 0.0");
			CMD("ui_loadingscreen_fadein_time 0.0");
			CMD("ui_loadingscreen_mintransition_time 0.0");
		}
		CMD("p2sm_disable_progress_bar_update 1");
		CMD("p2sm_prevent_mat_snapshot_recompute 1");
		CMD("p2sm_loads_uncap 0");
		CMD("p2sm_loads_norender 0");
	} else if (!strcmp(preset, "normal")) {
		if (!Game::IsSpeedrunMod() && ui_loadingscreen_transition_time.ThisPtr()) {
			CMD("ui_loadingscreen_transition_time 0.0");
			CMD("ui_loadingscreen_fadein_time 0.0");
			CMD("ui_loadingscreen_mintransition_time 0.0");
		}
		CMD("p2sm_disable_progress_bar_update 1");
		CMD("p2sm_prevent_mat_snapshot_recompute 1");
		CMD("p2sm_loads_uncap 1");
		CMD("p2sm_loads_norender 0");
	} else if (!strcmp(preset, "full")) {
		if (!Game::IsSpeedrunMod() && ui_loadingscreen_transition_time.ThisPtr()) {
			CMD("ui_loadingscreen_transition_time 0.0");
			CMD("ui_loadingscreen_fadein_time 0.0");
			CMD("ui_loadingscreen_mintransition_time 0.0");
		}
		CMD("p2sm_disable_progress_bar_update 2");
		CMD("p2sm_prevent_mat_snapshot_recompute 1");
		CMD("p2sm_loads_uncap 1");
		CMD("p2sm_loads_norender 1");
	} else {
		console->Print("Unknown preset %s!\n", preset);
		console->Print(p2sm_fast_load_preset.ThisPtr()->m_pszHelpString);
	}
#undef CMD
}

CON_COMMAND(p2sm_clear_lines, "p2sm_clear_lines - clears all active drawline overlays\n") {
	// So, hooking this would be really annoying, however Valve's code
	// is dumb and bad and only allows 20 lines (after which it'll start
	// overwriting old ones), so let's just draw 20 zero-length lines!
	for (int i = 0; i < 20; ++i) {
		engine->ExecuteCommand("drawline 0 0 0 0 0 0", true);
	}
}

struct DrawLineInfo {
	Vector start, end;
	Color col;
};
static std::vector<DrawLineInfo> g_drawlines;

CON_COMMAND(p2sm_drawline, "p2sm_drawline <x> <y> <z> <x> <y> <z> [r] [g] [b] - overlay a line in the world\n") {
	if (args.ArgC() != 7 && args.ArgC() != 10) {
		return console->Print(p2sm_drawline.ThisPtr()->m_pszHelpString);
	}

	float x0 = atof(args[1]);
	float y0 = atof(args[2]);
	float z0 = atof(args[3]);
	float x1 = atof(args[4]);
	float y1 = atof(args[5]);
	float z1 = atof(args[6]);

	uint8_t r = 255;
	uint8_t g = 255;
	uint8_t b = 255;

	if (args.ArgC() == 10) {
		r = (uint8_t)atoi(args[7]);
		g = (uint8_t)atoi(args[8]);
		b = (uint8_t)atoi(args[9]);
	}

	g_drawlines.push_back({
		{x0, y0, z0},
		{x1, y1, z1},
		{r, g, b},
	});
}


CON_COMMAND(p2sm_drawline_clear, "p2sm_drawline_clear - clear all active p2sm_drawlines\n") {
	g_drawlines.clear();
}

ON_EVENT(RENDER) {
	if (!sv_cheats.GetBool()) return;

	std::map<int, MeshId> meshes;

	for (auto l : g_drawlines) {
		int col_int = *(int *)&l.col;
		if (meshes.count(col_int) == 0) {
			meshes[col_int] = OverlayRender::createMesh(RenderCallback::none, RenderCallback::constant(l.col, true));
		}
		OverlayRender::addLine(meshes[col_int], l.start, l.end);
	}
}

CON_COMMAND(p2sm_getpos, "p2sm_getpos [slot] [server|client] - get the absolute origin and angles of a particular player from either the server or client. Defaults to slot 0 and server.\n") {
	if (args.ArgC() > 3) {
		return console->Print(p2sm_getpos.ThisPtr()->m_pszHelpString);
	}

	bool use_serv = true;

	if (args.ArgC() == 3) {
		if (!strcmp(args[2], "client")) {
			use_serv = false;
		} else if (strcmp(args[2], "server")) {
			return console->Print(p2sm_getpos.ThisPtr()->m_pszHelpString);
		}
	}

	int slot = args.ArgC() >= 2 ? atoi(args[1]) : 0;

	if (slot >= engine->GetMaxClients()) return console->Print("Could not get player at slot %d\n", slot);

	Vector origin;
	QAngle angles;

	if (use_serv) {
		void *player = server->GetPlayer(slot + 1);
		if (!player) return console->Print("Could not get player at slot %d\n", slot);
		origin = server->GetAbsOrigin(player);
		angles = server->GetAbsAngles(player);
	} else {
		void *player = client->GetPlayer(slot + 1);
		if (!player) return console->Print("Could not get player at slot %d\n", slot);
		origin = client->GetAbsOrigin(player);
		angles = client->GetAbsAngles(player);
	}

	console->Print("origin: %.6f %.6f %.6f\n", origin.x, origin.y, origin.z);
	console->Print("angles: %.6f %.6f %.6f\n", angles.x, angles.y, angles.z);
}

CON_COMMAND(p2sm_geteyepos, "p2sm_geteyepos [slot] - get the view position (portal shooting origin) and view angles of a certain player.\n") {
	if (args.ArgC() > 2) {
		return console->Print(p2sm_geteyepos.ThisPtr()->m_pszHelpString);
	}

	int slot = args.ArgC() >= 2 ? atoi(args[1]) : 0;

	if (slot >= engine->GetMaxClients()) return console->Print("Could not get player at slot %d\n", slot);

	Vector eye;
	QAngle angles;

	void *player = server->GetPlayer(slot + 1);
	if (!player) return console->Print("Could not get player at slot %d\n", slot);
	eye = server->GetAbsOrigin(player) + server->GetViewOffset(player) + server->GetPortalLocal(player).m_vEyeOffset;
	angles = engine->GetAngles(slot);

	console->Print("eye: %.6f %.6f %.6f\n", eye.x, eye.y, eye.z);
	console->Print("angles: %.6f %.6f %.6f\n", angles.x, angles.y, angles.z);
}

CON_COMMAND_F(p2sm_challenge_autosubmit_reload_api_key, "p2sm_challenge_autosubmit_reload_api_key - reload the boards API key from its file.\n", FCVAR_DONTRECORD) {
	if (args.ArgC() != 1) {
		return console->Print(p2sm_challenge_autosubmit_reload_api_key.ThisPtr()->m_pszHelpString);
	}

	AutoSubmit::LoadApiKey(true);
}

Memory::Patch *g_floorReportalPatch;

void Cheats::Init() {
	sv_laser_cube_autoaim = Variable("sv_laser_cube_autoaim");
	ui_loadingscreen_transition_time = Variable("ui_loadingscreen_transition_time");
	ui_loadingscreen_fadein_time = Variable("ui_loadingscreen_fadein_time");
	ui_loadingscreen_mintransition_time = Variable("ui_loadingscreen_mintransition_time");
	ui_transition_effect = Variable("ui_transition_effect");
	ui_transition_time = Variable("ui_transition_time");
	ui_pvplobby_show_offline = Variable("ui_pvplobby_show_offline");
	mm_session_sys_delay_create_host = Variable("mm_session_sys_delay_create_host");
	hide_gun_when_holding = Variable("hide_gun_when_holding");
	r_flashlightbrightness = Variable("r_flashlightbrightness");

	p2sm_disable_challenge_stats_hud.UniqueFor(SourceGame_Portal2);
	p2sm_disable_challenge_stats_hud_partner.UniqueFor(SourceGame_Portal2);

	p2sm_disable_weapon_sway.UniqueFor(SourceGame_Portal2);
	p2sm_disable_viewmodel_shadows.UniqueFor(SourceGame_Portal2 | SourceGame_PortalStoriesMel | SourceGame_PortalReloaded);

	startbhop.UniqueFor(SourceGame_StanleyParable);
	endbhop.UniqueFor(SourceGame_StanleyParable);
	p2sm_anti_anti_cheat.UniqueFor(SourceGame_StanleyParable);

	// Thinking with Time Machine also has workshop support, but we don't support it yet
	// | SourceGame_ThinkingWithTimeMachine
	p2sm_workshop.UniqueFor(SourceGame_Portal2 | SourceGame_ApertureTag);
	p2sm_workshop_update.UniqueFor(SourceGame_Portal2 | SourceGame_ApertureTag);
	p2sm_workshop_list.UniqueFor(SourceGame_Portal2 | SourceGame_ApertureTag);
	p2sm_workshop_skip.UniqueFor(SourceGame_Portal2 | SourceGame_ApertureTag);

	p2sm_fix_reloaded_cheats.UniqueFor(SourceGame_PortalReloaded);

	cvars->Unlock();

	if (p2sm.game->Is(SourceGame_PortalStoriesMel)) {
		Variable("give_portalgun").RemoveFlag(FCVAR_CHEAT);
		Variable("setmodel").RemoveFlag(FCVAR_CHEAT);
		Variable("upgrade_portalgun").RemoveFlag(FCVAR_CHEAT);
	}

	g_floorReportalPatch = new Memory::Patch();
	auto floorReportalBranch = Memory::Scan(MODULE("server"), Offsets::FloorReportalBranch);
	if (floorReportalBranch) {
		unsigned char floorReportalBranchByte = 0x70;
		g_floorReportalPatch->Execute(floorReportalBranch, &floorReportalBranchByte, 1);
		g_floorReportalPatch->Restore();
	}

	Variable::RegisterAll();
	Command::RegisterAll();
}
void Cheats::Shutdown() {
	if (cvars) cvars->Lock();

	if (p2sm.game && p2sm.game->Is(SourceGame_PortalStoriesMel)) {
		Variable("give_portalgun").AddFlag(FCVAR_CHEAT);
		Variable("setmodel").AddFlag(FCVAR_CHEAT);
		Variable("upgrade_portalgun").AddFlag(FCVAR_CHEAT);
	}

	Variable::UnregisterAll();
	Command::UnregisterAll();
	
	g_floorReportalPatch->Restore();
	SAFE_DELETE(g_floorReportalPatch);
}


// FUN PATCHES :))))))

void Cheats::PatchBhop(int slot, void *player, CUserCmd *cmd) {
	if (!server->AllowsMovementChanges() || !p2sm_patch_bhop.GetBool()) return;

	TasPlayerInfo info = tasPlayer->GetPlayerInfo(slot, player, cmd);

	float currVel = info.velocity.Length2D();
	float predictVel = autoStrafeTool[info.slot].GetVelocityAfterMove(info, cmd->forwardmove, cmd->sidemove).Length2D();

	float maxSpeed = autoStrafeTool[info.slot].GetMaxSpeed(info, Vector(0, 1));
	if (maxSpeed == 0) return;

	// player surpassed max speed through its own movement - limit wishdir
	if (predictVel > maxSpeed && predictVel > currVel) {
		float mult = (maxSpeed - currVel) / (predictVel - currVel);
		mult = fminf(fmaxf(mult, 0.0f), 1.0f);
		cmd->forwardmove *= mult;
		cmd->sidemove *= mult;
	}
}

ON_EVENT(PROCESS_MOVEMENT) {
	if (!server->AllowsMovementChanges() || !p2sm_patch_cfg.GetBool()) return;

	auto player = server->GetPlayer(event.slot + 1);
	if (player == nullptr) return;

	auto portalLocal = server->GetPortalLocal(player);

	void *tbeamHandle = reinterpret_cast<void *>(portalLocal.m_hTractorBeam);

	if (!tbeamHandle || (uint32_t)tbeamHandle == (unsigned)Offsets::INVALID_EHANDLE_INDEX) return;

	for (int i = 0; i < 2; i++) {
		int hitboxOffset = i == 0 ? Offsets::m_pShadowCrouch : Offsets::m_pShadowStand;
		auto shadow = *reinterpret_cast<void **>((uintptr_t)player + hitboxOffset);

		// WAKE UP YOU MORON YOU'RE RUINING MY FUNNELS ARGGHHH
		Memory::VMT<void(__rescall *)(void *)>(shadow, Offsets::Wake)(shadow);
	}
}

void Cheats::AutoStrafe(int slot, void *player, CUserCmd *cmd) {
	if (!server->AllowsMovementChanges() || !p2sm_autostrafe.GetBool()) return;

	if (cmd->forwardmove == 0 && cmd->sidemove == 0) return;

	auto m_MoveType = SE(player)->field<char>("m_MoveType");

	if (m_MoveType == MOVETYPE_NOCLIP) return;

	TasPlayerInfo info = tasPlayer->GetPlayerInfo(slot, player, cmd);

	float angle = Math::AngleNormalize(RAD2DEG(DEG2RAD(info.angles.y) + atan2(-cmd->sidemove, cmd->forwardmove)));

	TasFramebulk fb;
	tasPlayer->playbackInfo.slots[slot].header.version = MAX_SCRIPT_VERSION;
	autoJumpTool[info.slot].SetParams(autoJumpTool[info.slot].ParseParams(std::vector<std::string>{p2sm_autojump.GetBool() && (cmd->buttons & IN_JUMP) ? "on" : "off"}));
	autoStrafeTool[info.slot].SetParams(autoStrafeTool[info.slot].ParseParams(std::vector<std::string> {"vec", "max", std::to_string(angle) + "deg"}));
	autoStrafeTool[info.slot].Apply(fb, info);
	if (p2sm.game->Is(SourceGame_INFRA)) {
		fb.moveAnalog.y *= 2;
	}
	tasPlayer->ApplyMoveAnalog(fb.moveAnalog, cmd);
}

void Cheats::EnsureSlopeBoost(const CHLMoveData *move, void *player, CGameTrace **tr) {
	if ((*tr) == NULL) {
		return;
	}
	
	if (!server->AllowsMovementChanges() || !p2sm_ensure_slope_boost.GetBool()) {
		return;
	}

	Vector velocity = move->m_vecVelocity;
	Vector hitNormal = (*tr)->plane.normal; 
	
	bool goingDown = velocity.z < 0;
	bool isntAlreadyGrounded = !(SE(player)->ground_entity());
	bool landedOnSlope = hitNormal.z < 1.0f;
	bool wantsToSnapToGround = (*tr)->fraction >= 0.000001f;
	bool boostingTowardsVelocity = hitNormal.x * velocity.x + hitNormal.y * velocity.y >= 0;

	if (goingDown && isntAlreadyGrounded && landedOnSlope && wantsToSnapToGround && boostingTowardsVelocity) {
		// Nulling out pointer by reference, so that it's passed in CGameMovement::SetGroundEntity, 
		// preventing being grounded on this call, letting the player to boost off slope
		*tr = NULL;
	}

}

void Cheats::CheckFloorReportals() {
	bool enabled = p2sm_floor_reportals.GetBool();
	if (enabled && (!g_floorReportalPatch || !g_floorReportalPatch->IsInit())) {
		console->Print("p2sm_floor_reportals is not available.\n");
		p2sm_floor_reportals.SetValue(0);
		return;
	}
	if (!sv_cheats.GetBool() && enabled) {
		console->Print("p2sm_floor_reportals requires sv_cheats 1.\n");
		p2sm_floor_reportals.SetValue(0);
		enabled = false;
	}
	if (enabled == g_floorReportalPatch->IsPatched()) {
		return;
	}

	if (enabled) {
		g_floorReportalPatch->Execute();
	} else {
		g_floorReportalPatch->Restore();
	}
}
