#pragma once
#include "Utils.hpp"

#define P2SM_PLUGIN_SIGNATURE "SourceAutoRecord v" P2SM_VERSION

// CServerPlugin
#define CServerPlugin_m_Size 16
#define CServerPlugin_m_Plugins 4

class Plugin {
public:
	CPlugin *ptr;
	int index;

public:
	Plugin();
};
