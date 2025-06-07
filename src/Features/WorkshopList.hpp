#pragma once
#include "Command.hpp"
#include "Feature.hpp"

#include <string>
#include <vector>

class WorkshopList : public Feature {
public:
	std::vector<std::string> maps;

public:
	WorkshopList();
	int Update();
};

extern WorkshopList *workshop;

extern Command p2sm_workshop;
extern Command p2sm_workshop_update;
extern Command p2sm_workshop_list;
