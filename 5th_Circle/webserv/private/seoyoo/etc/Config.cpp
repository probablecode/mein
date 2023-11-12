#include "Config.hpp"
#include <fstream>
#include <sstream>

Config::Config(char *argv) {

	(void)argv;
	std::vector<int> ports;
	ports.push_back(8080);
	std::string serverName = "localhost 4242.com";
	std::string root = "/rootdir";
	std::vector<int> allowed;
	allowed.push_back(GET);
	allowed.push_back(DELETE);
	allowed.push_back(PUT);
	std::vector<int> denied;
	denied.push_back(POST);

	std::string loc_root = "/tester";
	bool loc_autoindex = true;
	std::string loc_index = "blah.html";
	std::vector<int> loc_allowed;
	loc_allowed.push_back(GET);
	std::vector<int> loc_denied;
	loc_denied.push_back(POST);
	loc_denied.push_back(DELETE);

	Block block(ports, serverName, root, allowed, denied, loc_root, loc_autoindex, loc_index, loc_allowed, loc_denied);
	blocks.push_back(block);
}

Config::~Config() {}