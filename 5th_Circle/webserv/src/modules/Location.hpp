#ifndef LOCATION_HPP_
#define LOCATION_HPP_

#include <map>
#include "config/LocationConfig.hpp"

class Location {
 public:
  Location();
  ~Location();

  void CreateLocation(const LocationConfig& location_config);

 private:
  std::string path_;
  std::vector<std::string> root_;
  std::vector<std::string> index_;
  std::map<std::string, std::vector<unsigned int> > error_page_;
  std::vector<unsigned int> client_max_body_size_;
  std::vector<bool> autoindex_;
  std::vector<HTTPMethod> allow_;
  std::vector<std::string> cgi_pass_;
  std::vector<std::string> cgi_index_;
  std::vector<std::string> cgi_extention_;

  void SetValues(std::string& path, std::vector<std::string>& root,
				 std::vector<std::string>& index,
				 std::map<std::string, std::vector<unsigned int> >& error_page,
				 std::vector<unsigned int>& client_max_body_size,
				 std::vector<bool>& autoindex,
		         std::vector<HTTPMethod>& allow,
				 std::vector<std::string>& cgi_pass,
				 std::vector<std::string>& cgi_index,
				 std::vector<std::string>& cgi_extention);
};

#endif
