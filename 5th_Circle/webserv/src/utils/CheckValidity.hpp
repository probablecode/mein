#ifndef CHECKVALIDITY_HPP_
#define CHECKVALIDITY_HPP_

#include <iostream>
#include "CustomException.hpp"
#include "MyString.hpp"

class CheckValidity {
 public:
  static bool isNumber(std::string str, long* ret) {
	char* end_ptr;
	*ret = std::strtol(str.c_str(), &end_ptr, 10);
	// If endPtr points to the same location as the beginning of the string, it means no conversion was performed
	// or the string was empty. In both cases, it is not an integer.
	if (end_ptr == str.c_str() || *end_ptr != '\0') // string일 때
	  return false;
	return true;
  }

  static void checkIP(std::string ip) {
	std::stringstream ss(ip);
	std::string octet;
	long value;
	int cnt = 0;
	while (std::getline(ss, octet, '.')) {
	  cnt++;
	  if (isNumber(octet, &value))
		if (value < 0 || value > 255)
		  throw CustomException(CustomException::kExceptionConfigParsing,
								"ip number is weird.");
	}
	if (cnt > 4)
	  throw CustomException(CustomException::kExceptionConfigParsing,
							"ip number is weird.");
  }

  static void checkPort(std::string port) {
	long value;
	if(isNumber(port, &value))
	  if (value < 0 || value > UINT32_MAX)
		throw CustomException(CustomException::kExceptionConfigParsing,
							  "port number is weird.");
  }

  static std::string addDefaultWithColon(std::string str) {
	std::string new_str;

	if (str.find('.') != std::string::npos) { //ip일 때
	  checkIP(str);
	  new_str = str + ":80";
	} else {
	  checkPort(str);
	  new_str = "0.0.0.0:" + str;
	}
	return new_str;
  }

  static void CheckListen(std::vector<std::string>& listen) {
	if (listen.size() > 1)
	  throw CustomException(CustomException::kExceptionConfigParsing,
							"port number must be one.");
	std::vector<std::string>::iterator iter = listen.begin();
	if ((*iter).find(':') == std::string::npos) {
	  listen.clear();
	  listen.push_back(addDefaultWithColon(*iter));
	} else {
	  size_t colon_pos = (*iter).find(':');
	  std::string ip = (*iter).substr(0, colon_pos);
	  std::string port = (*iter).substr(colon_pos + 1);
	  checkIP(ip);
	  checkPort(port);
	}
  }

  static void CheckErrorPage(std::vector<std::string>& error_page) {
	bool page_flag = false;
	bool error_num_flag = false;

	std::string error_page_path;
	long error_num;
	for(std::vector<std::string>::iterator iter = error_page.begin();iter != error_page.end(); iter++) {
	  if (isNumber(*iter, &error_num)) {
		if (error_num < 0 || error_num > UINT32_MAX) // 숫자인데 범위 밖일 때
		  throw CustomException(CustomException::kExceptionConfigParsing,
								"error_page's number is weird.");
		error_num_flag = true;
	  } else {page_flag = true;}
	}
	if (page_flag == false || error_num_flag == false)
	  throw CustomException(CustomException::kExceptionConfigParsing,
							"error_page directive is weird.");
  }
  static void CheckAutoIndex(std::vector<std::string>& autoindex) {
	std::vector<std::string>::iterator iter = autoindex.begin();
	for(;iter != autoindex.end(); iter++) {
	  if (*iter != "on" && *iter != "off")
		throw CustomException(CustomException::kExceptionConfigParsing,
							  "autoindex directive is weird.");
	}
  }
  static void CheckAllow(std::vector<std::string>& allow) {
	std::vector<std::string>::iterator iter = allow.begin();
	for(;iter != allow.end(); iter++) {
	  if (*iter != "GET" && *iter != "PUT" && *iter != "POST" && *iter != "DELETE")
		throw CustomException(CustomException::kExceptionConfigParsing,
							  "allow directive is weird.");
	}
  }
  static void CheckCgiExtension(std::vector<std::string>* cgi_) {
	std::vector<std::string>::iterator iter = cgi_->begin();
	for(;iter != cgi_->end();iter++) {
	  if ((*iter)[0] != '.')
		throw CustomException(CustomException::kExceptionConfigParsing,
							  "cgi_ is out of a extension format");
	}
  }
};

#endif
