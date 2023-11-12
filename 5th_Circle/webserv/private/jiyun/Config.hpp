#ifndef CONFIG_HPP_
#define CONFIG_HPP_

#include <fstream>
#include <iostream>
#include <map>
#include <string>
#include <vector>

#include "utils/CustomException.hpp"
#include "utils/MyString.hpp"

#include "ServerConfig.hpp"

#define CONFIG_FILE_LOCATION "../config/config.conf"

class Config {
 public:
  // constructors & destructor
  Config();
  Config(int argc, char **argv);
  Config(const Config &src);
  ~Config() {}

  // operators
  Config &operator=(const Config &rhs);

  // functions
  void ParseConfigurationFile(int argc, char **argv);
  void PrintResult() const;

  int GetServerConfigsNum() const;
  const ServerConfig& GetServerConfig(int server_config_idx) const;

 private:
  // variables
  std::vector<ServerConfig> server_configs_;

  // functions
  void CheckBlockValidity(std::ifstream &file, char block_start,
                          char block_end) const;
  void CheckLineEdges(std::ifstream &file) const;
  void CheckTabs(std::ifstream &file) const;
  void TestPrint(std::ifstream &file, bool use_colored_str = true)const;
};

#endif