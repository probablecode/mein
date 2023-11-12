#include "LocationConfig.hpp"
#include "utils/CheckValidity.hpp"

// public **********************************************************************

//  constructors & destructor --------------------------------------------------

//  Default constructor
LocationConfig::LocationConfig() {}

LocationConfig::LocationConfig(std::ifstream &file, size_t &line_cnt,
							   std::string &path) {
  ParseLocationConfig(file, line_cnt, path);
}

//  Copy constructor
LocationConfig::LocationConfig(const LocationConfig &src) { *this = src; }

//  destructor
LocationConfig::~LocationConfig() {
  // TODO
}

//  operators ------------------------------------------------------------------

//  = operator overloading
LocationConfig &LocationConfig::operator=(const LocationConfig &rhs) {
  if (this == &rhs) return *this;
  path_ = rhs.path_;
  root_ = rhs.root_;
  index_ = rhs.index_;
  error_page_ = rhs.error_page_;
  client_max_body_size_ = rhs.client_max_body_size_;
  autoindex_ = rhs.autoindex_;
  allow_ = rhs.allow_;
  cgi_pass_ = rhs.cgi_pass_;
  cgi_index_ = rhs.cgi_index_;
  cgi_extention_ = rhs.cgi_extention_;
  return *this;
}

void LocationConfig::ParseLocationConfig(std::ifstream &file, size_t &line_cnt,
										 std::string &path) {
  path_ = path;
  std::string line;
  std::vector<std::string> tokens;

  while (std::getline(file, line)) {
	line_cnt++;
	if (line.back() == ';') {
	  line.pop_back();
	};
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
		std::vector<std::string> *target = NULL;
		if (tokens.front() == "root") {
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
		} else if (tokens.front() == "cgi_pass") {
		  target = &cgi_pass_;
		} else if (tokens.front() == "cgi_index") {
		  target = &cgi_index_;
		} else if (tokens.front() == "cgi_extention_") {
		  target = &cgi_extention_;
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
		  CheckLocationConfigValidity(target);
		}
	  }
	}
  }
}

void LocationConfig::PrintResult() const {
  std::cout << "\n  Location block < path : [" << path_ << "] >" << std::endl;
  ConfigUtils::PrintStringVector("  root", root_);
  ConfigUtils::PrintStringVector("  index", index_);
  ConfigUtils::PrintStringVector("  error_page", error_page_);
  ConfigUtils::PrintStringVector("  client_max_size",
								 client_max_body_size_);
  ConfigUtils::PrintStringVector("  autoindex", autoindex_);
  ConfigUtils::PrintStringVector("  allow", allow_);
  ConfigUtils::PrintStringVector("  cgi_pass", cgi_pass_);
  ConfigUtils::PrintStringVector("  cgi_index", cgi_index_);
  ConfigUtils::PrintStringVector("  cgi_extention", cgi_extention_);
  std::cout << "  Location block ends" << std::endl;
}

const std::string& LocationConfig::GetPath() const {
  return path_;
}

const std::vector<std::string>& LocationConfig::GetRoot() const {
  return root_;
}

const std::vector<std::string>& LocationConfig::GetIndex() const {
  return index_;
}

const std::vector<std::string> &LocationConfig::GetErrorPage() const {
  return error_page_;
}

const std::vector<std::string> &LocationConfig::GetMaxBodySize() const {
  return client_max_body_size_;
}

const std::vector<std::string> &LocationConfig::GetAutoIndex() const {
  return autoindex_;
}

const std::vector<std::string> &LocationConfig::GetAllow() const {
  return allow_;
}

const std::vector<std::string> &LocationConfig::GetCgiPass() const {
  return cgi_pass_;
}

const std::vector<std::string> &LocationConfig::GetCgiIndex() const {
  return cgi_index_;
}

const std::vector<std::string> &LocationConfig::GetCgiExtension() const {
  return cgi_extention_;
}

void LocationConfig::CreateServerLocationConfig(std::string path,
												std::vector<std::string> root,
												std::vector<std::string> index,
												std::vector<std::string> error_page,
												std::vector<std::string> client_max_body_size,
												std::vector<std::string> autoindex,
												std::vector<std::string> allow) {
  std::vector<std::string> cgi_pass;
  std::vector<std::string> cgi_index;
  std::vector<std::string> cgi_extention;
  SetValues(path, root, index, error_page, client_max_body_size,
			autoindex, allow, cgi_pass, cgi_index, cgi_extention);
}


// private *********************************************************************

void LocationConfig::SetValues(std::string& path,
							   std::vector<std::string>& root,
							   std::vector<std::string>& index,
							   std::vector<std::string>& error_page,
							   std::vector<std::string>& client_max_body_size,
							   std::vector<std::string>& autoindex,
							   std::vector<std::string>& allow,
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

void LocationConfig::CheckLocationConfigValidity(std::vector<std::string>* target) {
  if (target == &error_page_)
	CheckValidity::CheckErrorPage(error_page_);
  if (target == &autoindex_)
	CheckValidity::CheckAutoIndex(autoindex_);
  if (target == &allow_)
	CheckValidity::CheckAllow(allow_);
  if (target == &cgi_pass_ || target == &cgi_index_ || target == &cgi_extention_) {
	CheckValidity::CheckCgiExtension(target);
  }
}