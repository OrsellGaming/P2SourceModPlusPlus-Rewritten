#include "Hud.hpp"
#include "Command.hpp"
#include "Modules/Client.hpp"
#include "Modules/Console.hpp"
#include "Modules/Engine.hpp"
#include "Modules/FileSystem.hpp"
#include "Modules/Surface.hpp"
#include "Utils/lodepng.hpp"
#include "Utils/json11.hpp"
#include <fstream>

#define MAP_PAD 5
#define PLAYER_SIZE 10

Variable p2sm_minimap_x("p2sm_minimap_x", "-10", "The X position of the minimap.\n", 0);
Variable p2sm_minimap_y("p2sm_minimap_y", "10", "The Y position of the minimap.\n", 0);
Variable p2sm_minimap_max_width("p2sm_minimap_max_width", "500", "The maximum width of the minimap.\n", 0);
Variable p2sm_minimap_max_height("p2sm_minimap_max_height", "1000", "The maximum height of the minimap.\n", 0);
Variable p2sm_minimap_player_color("p2sm_minimap_player_color", "255 0 0 255", "The color of the circle representing the player on the minimap.\n", 0);

static std::map<std::string, std::pair<int, float>> g_textures;

struct Minimap {
	int texture_id;
	float ratio; // width/height
	float top, left, bottom, right;
};

struct MinimapSettings {
	int x, y;
	int max_width, max_height;
};

static bool getTextureId(std::string path, Minimap &out) {
	auto it = g_textures.find(path);
	if (it != g_textures.end()) {
		out.texture_id = it->second.first;
		out.ratio = it->second.second;
		return true;
	}

	std::vector<unsigned char> buf;
	unsigned w, h;

	auto filepath = fileSystem->FindFileSomewhere(path).value_or(path);
	unsigned err = lodepng::decode(buf, w, h, filepath);
	if (err) {
		console->Warning("%s\n", lodepng_error_text(err));
		return false;
	}

	int id = surface->CreateNewTextureID(surface->matsurface->ThisPtr(), true);
	surface->DrawSetTextureRGBA(surface->matsurface->ThisPtr(), id, buf.data(), w, h);

	float ratio = (float)w / (float)h;

	g_textures[path] = {id, ratio};

	out.texture_id = id;
	out.ratio = ratio;
	return true;
}

static bool loadMinimapData(std::string path, Minimap &out, std::string &img_path_out) {
	auto filepath = fileSystem->FindFileSomewhere(path).value_or(path);
	std::ifstream ifs(filepath);
	if (ifs.fail()) {
		console->Print("Failed to open %s\n", path.c_str());
		return false;
	}

	std::string str;
	ifs.seekg(0, std::ios::end);
	str.reserve(ifs.tellg());
	ifs.seekg(0, std::ios::beg);

	str.assign(std::istreambuf_iterator<char>(ifs), std::istreambuf_iterator<char>());
	if (ifs.fail()) {
		console->Print("Failed to read %s\n", path.c_str());
		return false;
	}

	ifs.close();

	std::string err;
	auto json = json11::Json::parse(str, err);
	if (err != "") {
		console->Print("Failed to parse %s\n", path.c_str());
		return false;
	}

#define EXPECT(name, type) if (!json[name].is_##type()) { console->Print("Expected '" name "' of type '" #type "' in %s\n", path.c_str()); return false; }
	EXPECT("image_path", string)
	EXPECT("top", number)
	EXPECT("left", number)
	EXPECT("bottom", number)
	EXPECT("right", number)
#undef EXPECT

	img_path_out = json["image_path"].string_value();

	out.top = json["top"].number_value();
	out.left = json["left"].number_value();
	out.bottom = json["bottom"].number_value();
	out.right = json["right"].number_value();

	return true;
}

static std::optional<Minimap> loadMinimap(std::string name) {
	Minimap m;
	std::string img_path;
	if (!loadMinimapData(name, m, img_path)) {
		console->Print("Failed to load minimap metadata\n");
		return {};
	}

	if (!getTextureId(img_path, m)) {
		console->Print("Failed to load minimap image\n");
		return {};
	}

	return m;
}

static void drawMinimap(Minimap m, MinimapSettings s) {
	int width = s.max_width;
	int height = s.max_width / m.ratio;

	if (width > s.max_height * m.ratio) {
		width = s.max_height * m.ratio;
		height = s.max_height;
	}

	int x = s.x, y = s.y;

	int sw, sh;
	engine->GetScreenSize(nullptr, sw, sh);

	if (x < 0) x += sw - width;
	if (y < 0) y += sh - height;

	surface->DrawRect({0, 0, 0, 192}, x, y, x + width, y + height);

	x += MAP_PAD;
	y += MAP_PAD;
	width -= 2 * MAP_PAD;
	height -= 2 * MAP_PAD;

	surface->DrawSetColor(surface->matsurface->ThisPtr(), 255, 255, 255, 255);
	surface->DrawSetTexture(surface->matsurface->ThisPtr(), m.texture_id);
	surface->DrawTexturedRect(surface->matsurface->ThisPtr(), x, y, x + width, y + height);

	for (int slot = 0; slot < 2; ++slot) {
		void *player = client->GetPlayer(slot + 1);
		if (player) {
			Vector pos = client->GetAbsOrigin(player);

			float from_left = (float)(pos.x - m.left) / (m.right - m.left);
			float from_top = (float)(pos.y - m.top) / (m.bottom - m.top);

			if (from_left >= 0 && from_left <= 1 && from_top >= 0 && from_top <= 1) {
				int pix_x = x + from_left * width;
				int pix_y = y + from_top * height;

				auto col = Utils::GetColor(p2sm_minimap_player_color.GetString(), false);
				if (!col) col = Color{ 255, 0, 0, 255 };

				surface->DrawRect(*col, pix_x - PLAYER_SIZE / 2, pix_y - PLAYER_SIZE / 2, pix_x + PLAYER_SIZE / 2, pix_y + PLAYER_SIZE / 2);
			}
		}
	}
}

static std::optional<Minimap> g_cur_map;

CON_COMMAND(p2sm_minimap_load, "p2sm_minimap_load <filename> - load a minimap from a JSON file.\n") {
	if (args.ArgC() != 2) return console->Print(p2sm_minimap_load.ThisPtr()->m_pszHelpString);

	std::string path = args[1];

	if (path.length() < 5 || path.substr(path.length() - 5, 5) != ".json") path += ".json";

	g_cur_map = loadMinimap(path);
	if (g_cur_map) console->Print("Minimap loaded!\n");
}

class MinimapHud : public Hud {
public:
	MinimapHud() : Hud(HudType_InGame, true) {}
	bool GetCurrentSize(int &w, int &h) { return false; }
	void Paint(int slot) override {
		if (g_cur_map) {
			drawMinimap(
				*g_cur_map, {
					p2sm_minimap_x.GetInt(),
					p2sm_minimap_y.GetInt(),
					p2sm_minimap_max_width.GetInt(),
					p2sm_minimap_max_height.GetInt(),
				}
			);
		}
	}
};

static MinimapHud minimapHud;
