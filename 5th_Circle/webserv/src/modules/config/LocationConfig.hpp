#ifndef LOCATIONCONFIG_HPP_
#define LOCATIONCONFIG_HPP_

#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>
#include <vector>

#include "ConfigDefines.hpp"
#include "ConfigUtils.hpp"
#include "defines.hpp"
#include "utils/CustomException.hpp"
#include "utils/MyString.hpp"

class LocationConfig {
 public:
  // constructors & destructor
  LocationConfig();
  LocationConfig(std::ifstream &file, size_t &line_cnt, std::string &path);
  LocationConfig(const LocationConfig &src);
  ~LocationConfig();

  // operators
  LocationConfig &operator=(const LocationConfig &rhs);

  // functions
  void ParseLocationConfig(std::ifstream &file, size_t &line_cnt,
                           std::string &path);
  void PrintResult() const;

  const std::string& GetPath() const;
  const std::vector<std::string>& GetRoot() const;
  const std::vector<std::string>& GetIndex() const;
  const std::vector<std::string>& GetErrorPage() const;
  const std::vector<std::string>& GetMaxBodySize() const;
  const std::vector<std::string>& GetAutoIndex() const;
  const std::vector<std::string>& GetAllow() const;
  const std::vector<std::string>& GetCgiPass() const;
  const std::vector<std::string>& GetCgiIndex() const;
  const std::vector<std::string>& GetCgiExtension() const;

  void CreateServerLocationConfig(std::string path,
								  std::vector<std::string> root,
								  std::vector<std::string> index,
								  std::vector<std::string> error_page,
								  std::vector<std::string> client_max_body_size,
								  std::vector<std::string> autoindex,
								  std::vector<std::string> allow);

 private:
  // variables
  std::string path_;
  std::vector<std::string> root_;
  std::vector<std::string> index_;
  std::vector<std::string> error_page_;
  std::vector<std::string> client_max_body_size_;
  std::vector<std::string> autoindex_;
  std::vector<std::string> allow_;
  std::vector<std::string> cgi_pass_;
  std::vector<std::string> cgi_index_;
  std::vector<std::string> cgi_extention_;

  void SetValues(std::string& path,
				 std::vector<std::string>& root,
				 std::vector<std::string>& index,
				 std::vector<std::string>& error_page,
				 std::vector<std::string>& client_max_body_size,
				 std::vector<std::string>& autoindex,
				 std::vector<std::string>& allow,
				 std::vector<std::string>& cgi_pass,
				 std::vector<std::string>& cgi_index,
				 std::vector<std::string>& cgi_extention);

  void CheckLocationConfigValidity(std::vector<std::string>* target);
};

#endif