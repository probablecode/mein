#include "Location.hpp"
#include "CheckValidity.hpp"

Location::Location() {}

Location::~Location() {}

void Location::CreateLocation(const LocationConfig& location_config) {
  std::string path;
  std::vector<std::string> root;
  std::vector<std::string> index;
  std::map<std::string, std::vector<unsigned int> > error_page;
  std::vector<unsigned int> client_max_body_size;
  std::vector<bool> autoindex;
  std::vector<HTTPMethod> allow;
  std::vector<std::string> cgi_pass;
  std::vector<std::string> cgi_index;
  std::vector<std::string> cgi_extention;

  std::vector<std::string>::const_iterator iter;

  path = location_config.GetPath();
  for(iter = location_config.GetRoot().begin(); iter != location_config.GetRoot().end(); iter++)
	root.push_back(*iter);
  for(iter = location_config.GetIndex().begin(); iter != location_config.GetIndex().end(); iter++)
	index.push_back(*iter);


  std::string error_page_path;
  std::vector<unsigned int> error_nums;
  for(iter = location_config.GetErrorPage().begin(); iter != location_config.GetErrorPage().end(); iter++) {
	long error_num;
	if (CheckValidity::isNumber(*iter, &error_num)) {
	  error_nums.push_back(error_num);
	} else {
	  error_page_path = *iter;
	}
  }
  if (!error_page_path.empty() && !error_nums.empty())
	error_page.insert(std::make_pair(error_page_path, error_nums));


  for(iter = location_config.GetMaxBodySize().begin(); iter != location_config.GetMaxBodySize().end(); iter++) {
	long size;
	if (!CheckValidity::isNumber(*iter, &size))
	  throw CustomException(CustomException::kExceptionConfigParsing,
							"client max size number is weird.");
	client_max_body_size.push_back(size);
  }

  for(iter = location_config.GetAutoIndex().begin(); iter != location_config.GetAutoIndex().end(); iter++) {
	if (*iter == "on")
	  autoindex.push_back(true);
	else
	  autoindex.push_back(false);
  }

  for(iter = location_config.GetAllow().begin(); iter != location_config.GetAllow().end(); iter++) {
	if (*iter == "GET")
	  allow.push_back(kGet);
	else if (*iter == "POST")
	  allow.push_back(kPost);
	else if (*iter == "PUT")
	  allow.push_back(kPut);
	else if (*iter == "DELETE")
	  allow.push_back(kDelete);
  }

  for(iter = location_config.GetCgiPass().begin(); iter != location_config.GetCgiPass().end(); iter++)
	cgi_pass.push_back(*iter);
  for(iter = location_config.GetCgiIndex().begin(); iter != location_config.GetCgiIndex().end(); iter++)
	cgi_index.push_back(*iter);
  for(iter = location_config.GetCgiExtension().begin(); iter != location_config.GetCgiExtension().end(); iter++)
	cgi_extention.push_back(*iter);

  SetValues(path, root, index, error_page, client_max_body_size,
			autoindex, allow, cgi_pass, cgi_index, cgi_extention);
}

// private *********************************************************************

void Location::SetValues(std::string& path,
						 std::vector<std::string>& root,
						 std::vector<std::string>& index,
						 std::map<std::string, std::vector<unsigned int> >& error_page,
						 std::vector<unsigned int>& client_max_body_size,
						 std::vector<bool>& autoindex,
						 std::vector<HTTPMethod>& allow,
						 std::vector<std::string>& cgi_pass,
						 std::vector<std::string>& cgi_index,
						 std::vector<std::string>& cgi_extention) {
  path_ = path;
  root_ = root;
  index_ = index;
  error_page_ = error_page;
  client_max_body_size_ = client_max_body_size;
  autoindex_ = autoindex;
  allow_ = allow;
  cgi_pass_ = cgi_pass;
  cgi_index_ = cgi_index;
  cgi_extention_ = cgi_extention;
}