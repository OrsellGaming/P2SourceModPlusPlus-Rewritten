#pragma once
#include "Command.hpp"
#include "Feature.hpp"
#include "Utils/SDK.hpp"

#include <fstream>
#include <string>

class ClassDumper : public Feature {
private:
	std::string serverClassesFile;
	std::string clientClassesFile;

public:
	ClassDumper();
	void Dump(bool dumpServer = true);

private:
	void DumpSendTable(std::ofstream &file, SendTable *table);
	void DumpRecvTable(std::ofstream &file, RecvTable *table);
};

extern ClassDumper *classDumper;

extern Command p2sm_dump_server_classes;
extern Command p2sm_dump_client_classes;
extern Command p2sm_list_server_classes;
extern Command p2sm_list_client_classes;
extern Command p2sm_find_server_class;
extern Command p2sm_find_client_class;
