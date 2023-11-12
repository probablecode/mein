#include "ServerBlock.hpp"

ServerBlock::ServerBlock(std::vector<std::string> server_name) {
  std::vector<std::string>::iterator iter = server_name.begin();
  if (iter == server_name.end()) // 추가할 것 없는데
	if (server_name_.empty()) // 필드도 비어있으면
	  throw CustomException(CustomException::kExceptionConstructorFail,
						  "ServerBlock construct process fail.");
  for(;iter != server_name.end(); iter++) {
	server_name_.push_back(*iter);
  }
}

ServerBlock::~ServerBlock() {}

void ServerBlock::SetServerLocation(const LocationConfig &server_location_config) {
  server_location_ = CreateAndSetLocation(server_location_config);
}

void ServerBlock::AddLocations(const LocationConfig& location_config) {
  locations_.push_back(CreateAndSetLocation(location_config));
}

Location ServerBlock::CreateAndSetLocation(const LocationConfig& location_config) {
  Location new_location;
  new_location.CreateLocation(location_config);
  return new_location;
}

// private *********************************************************************
