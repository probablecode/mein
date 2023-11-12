#include "ServerConfig.hpp"
#include "utils/CheckValidity.hpp"

// public***********************************************************************

//  constructors & destructor --------------------------------------------------

//  Default constructor
ServerConfig::ServerConfig() {}

ServerConfig::ServerConfig(std::ifstream &file, size_t &line_cnt) {
  ParseServerConfig(file, line_cnt);
}

//  Copy constructor
ServerConfig::ServerConfig(const ServerConfig &src) { *this = src; }

//  destructor
ServerConfig::~ServerConfig() {}

//  operators ------------------------------------------------------------------

//  = operator overloading
ServerConfig &ServerConfig::operator=(const ServerConfig &rhs) {
  if (this == &rhs) return *this;
  listen_ = rhs.listen_;
  server_name_ = rhs.server_name_;
  server_location_config_ = rhs.server_location_config_;
  location_configs_ = rhs.location_configs_;
  return *this;
}

//  functions ------------------------------------------------------------------

/**
 * @brief Parse server configuration from right next line of "server {".
 *
 * @param file
 * @return ServerConfig
 */

void ServerConfig::ParseServerConfig(std::ifstream &file, size_t &line_cnt) {
  std::string line;
  std::vector<std::string> tokens;

  while (std::getline(file, line)) {
	line_cnt++;
	if (line.back() == ';') line.pop_back();
	// empty line will be ignored
	if (line.size() > 0) {
	  tokens = MyString::Split(line, ' ');
	  if (tokens.size() == 1) {
		if (tokens.front() == std::string(1, kBlockEnd)) {
		  // Finish parsing server configuration.
		  break;
		} else {
		  // If there is only a word and if it's not '}' -> error case
		  throw CustomException(CustomException::kExceptionConfigParsing,
								ConfigUtils::MakeErrorMessage(line_cnt, line));
		}
	  } else if (tokens.size() > 1) {
		std::vector<std::string>* target = NULL;
		if (tokens.front() == "listen") {
		  target = &listen_;
		} else if (tokens.front() == "server_name") {
		  target = &server_name_;
		} else if (tokens.front() == "root") {
		  target = &root_;
		} else if (tokens.front() == "index") {
		  target = &index_;
		} else if (tokens.front() == "error_page") {
		  target = &error_page_;
		} else if (tokens.front() == "client_max_body_size") {
		  target = &client_max_body_size_;
		} else if (tokens.front() == "autoindex") {
		  target = &autoindex_;
		} else if (tokens.front() == "allow") {
		  target = &allow_;
		} else if (tokens.front() == "location") {
		  if (tokens.size() != 3)
			throw CustomException(
				CustomException::kExceptionConfigParsing,
				ConfigUtils::MakeErrorMessage(line_cnt, line,
											  "There should be \"location\" "
											  "\"path\" and } in this line"));
		  location_configs_.push_back(
			  LocationConfig(file, line_cnt, tokens.at(1)));
		} else {
		  // LINE HERE WILL BE IGNORED
		  std::cout << ConfigUtils::MakeErrorMessage(
			  line_cnt, line,
			  "Undefined argument : This line will be ignored.")
					<< std::endl;
		}
		if (target != NULL) {
		  for (size_t i = 1; i < tokens.size(); i++)
			target->push_back(tokens[i]);
		  CheckServerConfigValidity(target);
		}
	  }
	}
  }
  server_location_config_.CreateServerLocationConfig(path_, root_, index_, error_page_,
													 client_max_body_size_, autoindex_,
													 allow_);
}

void ServerConfig::PrintResult() const {
  std::cout << "\nServer block start" << std::endl;
  ConfigUtils::PrintStringVector("listen", listen_);
  ConfigUtils::PrintStringVector("server_name", server_name_);
  server_location_config_.PrintResult();
  for (size_t i = 0; i < location_configs_.size(); i++) {
	location_configs_[i].PrintResult();
  }
  std::cout << "Server block ends" << std::endl;
}

const std::string& ServerConfig::GetListen() const {
  return *(listen_.begin());
}

const std::vector<std::string>& ServerConfig::GetServerNames() const {
  return server_name_;
}

const LocationConfig& ServerConfig::GetServerLocationConfig() const {
  return server_location_config_;
}

const std::vector<LocationConfig>& ServerConfig::GetLocationConfigs() const {
  return location_configs_;
}

// private *********************************************************************


void ServerConfig::CheckServerConfigValidity(std::vector<std::string>* target) {
  if (target == &listen_)
	CheckValidity::CheckListen(listen_);
  if (target == &error_page_)
	CheckValidity::CheckErrorPage(error_page_);
  if (target == &autoindex_)
	CheckValidity::CheckAutoIndex(autoindex_);
  if (target == &allow_)
	CheckValidity::CheckAllow(allow_);
}