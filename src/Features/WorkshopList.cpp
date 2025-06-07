#include "WorkshopList.hpp"

#include "Command.hpp"
#include "Modules/Engine.hpp"
#include "Modules/FileSystem.hpp"
#include "Utils.hpp"

#include <cstring>
#include <filesystem>
#include <string>

WorkshopList *workshop;

WorkshopList::WorkshopList()
	: maps() {
	this->hasLoaded = true;
}
int WorkshopList::Update() {
	auto before = this->maps.size();
	this->maps.clear();

	// Scan through all directories and find the map file
	for (auto gamedir : fileSystem->GetSearchPaths()) {
		auto path = gamedir + std::string("/maps/workshop");
		auto index = path.length() + 1;
		if (std::filesystem::is_directory(path)) {
			for (auto &dir : std::filesystem::recursive_directory_iterator(path)) {
				try {
					if (dir.status().type() == std::filesystem::file_type::directory) {
						auto curdir = dir.path().string();
						for (auto &dirdir : std::filesystem::directory_iterator(curdir)) {
							auto file = dirdir.path().string();
							if (Utils::EndsWith(file, std::string(".bsp"))) {
								auto map = file.substr(index);
								map = map.substr(0, map.length() - 4);
								this->maps.push_back(map);
								break;
							}
						}
					}
				} catch (std::system_error &e) {
				}
			}
		}
	}

	return std::abs((int)before - (int)this->maps.size());
}

// Completion Function

DECL_COMMAND_COMPLETION(p2sm_workshop) {
	if (workshop->maps.empty()) {
		workshop->Update();
	}

	for (auto &map : workshop->maps) {
		if (items.size() == COMMAND_COMPLETION_MAXITEMS) {
			break;
		}

		if (std::strlen(match) != std::strlen(cmd)) {
			if (std::strstr(map.c_str(), match)) {
				items.push_back(map);
			}
		} else {
			items.push_back(map);
		}
	}

	FINISH_COMMAND_COMPLETION();
}

// Commands

CON_COMMAND_F_COMPLETION(p2sm_workshop, "p2sm_workshop <file> [ss/changelevel] - same as \"map\" command but lists workshop maps\n", 0, AUTOCOMPLETION_FUNCTION(p2sm_workshop)) {
	if (args.ArgC() < 2) {
		return console->Print(p2sm_workshop.ThisPtr()->m_pszHelpString);
	}

	auto command = std::string("map");

	if (args.ArgC() > 2) {
		if (!std::strcmp(args[2], "ss")) {
			command = std::string("ss_map");
		} else if (!std::strcmp(args[2], "changelevel")) {
			command = std::string("changelevel");
		}
	}

	engine->ExecuteCommand((command + std::string(" workshop/") + std::string(args[1])).c_str());
}
CON_COMMAND(p2sm_workshop_update, "p2sm_workshop_update - updates the workshop map list\n") {
	console->Print("Added or removed %i map(s) to or from the list.\n", workshop->Update());
}
CON_COMMAND(p2sm_workshop_list, "p2sm_workshop_list - prints all workshop maps\n") {
	if (workshop->maps.empty()) {
		workshop->Update();
	}

	for (const auto &map : workshop->maps) {
		console->Print("%s\n", map.c_str());
	}
}
