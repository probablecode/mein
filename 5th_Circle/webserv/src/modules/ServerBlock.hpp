#ifndef SERVERBLOCK_HPP_
#define SERVERBLOCK_HPP_

#include <vector>
#include "Location.hpp"
#include "config/LocationConfig.hpp"

class ServerBlock {
 public:
  explicit ServerBlock(std::vector<std::string> server_name);
  ~ServerBlock();

  void SetServerLocation(const LocationConfig& server_location_config);
  void AddLocations(const LocationConfig& location_config);
  Location CreateAndSetLocation(const LocationConfig& location_config);

 private:
  std::vector<std::string> server_name_;
  Location server_location_;
  std::vector<Location> locations_;
};

#endif
