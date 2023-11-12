#ifndef SERVER_HPP_
#define SERVER_HPP_

#include <vector>

#include "Udata.hpp"
#include "ServerBlock.hpp"
#include "config/ServerConfig.hpp"
#include "Socket/ListeningSocket.hpp"

class Server : public Udata {
 public:
  Server(uint32_t addr, unsigned short port);
  ~Server();
  ListeningSocket& GetListenSocket();
  void AddServerBlock(ServerConfig& server_config);

 private:
  ListeningSocket socket_;
  std::vector<ServerBlock> server_blocks_;
};

#endif