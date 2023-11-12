#ifndef WEBSERV_CONFIG_HPP
#define WEBSERV_CONFIG_HPP

#include "Block.cpp"

class Config {
public:
	enum METHODS {
		GET,
		POST,
		PUT,
		DELETE
	};

	template<typename T>
	T getMember(std::string memberName) {

	}

	Config(char* argv);
	~Config();

	std::vector<Block> blocks;

private:
	Config();
};

#endif
