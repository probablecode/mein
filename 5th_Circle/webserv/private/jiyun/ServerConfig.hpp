#ifndef SERVERCONFIG_HPP_
#define SERVERCONFIG_HPP_

#include <fstream>
#include <iostream>
#include <map>
#include <string>
#include <vector>

#include "ConfigDefines.hpp"
#include "ConfigUtils.hpp"
#include "LocationConfig.hpp"
//#include "defines.hpp"
#include "utils/CustomException.hpp"
#include "utils/MyString.hpp"

// Element of Config class
class ServerConfig {
 public:
  // constructors & destructor
  ServerConfig();
  ServerConfig(std::ifstream &file, size_t &line_cnt);
  ServerConfig(const ServerConfig &src);
  ~ServerConfig();

  // operators
  ServerConfig &operator=(const ServerConfig &rhs);

  // functions
  void ParseServerConfig(std::ifstream &file, size_t &line_cnt);
  void PrintResult() const;

  const std::string& GetListen() const;
  const std::vector<std::string>& GetServerNames() const;

  const LocationConfig& GetServerLocationConfig() const;
  const std::vector<LocationConfig>& GetLocationConfigs() const;

 private:
  // variables
  std::vector<std::string> listen_;
  std::vector<std::string> server_name_;

  std::string path_;
  std::vector<std::string> root_;
  std::vector<std::string> index_;
  std::vector<std::string> error_page_;
  std::vector<std::string> client_max_body_size_;
  std::vector<std::string> autoindex_;
  std::vector<std::string> allow_;

  LocationConfig server_location_config_;
  std::vector<LocationConfig> location_configs_;

  void CheckServerConfigValidity(std::vector<std::string>* target);

};

#endif
