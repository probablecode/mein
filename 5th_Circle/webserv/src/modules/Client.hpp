#ifndef CLIENT_HPP_
#define CLIENT_HPP_

#include <string>

#include "Udata.hpp"
#include "./Socket/ClientSocket.hpp"
#include "Server.hpp"
//#include "Request.hpp"
//#include "Response.hpp"

class Client : protected Udata {
 public:
  Client(Server& server, int server_socket_fd);
  ~Client();
  ClientSocket& GetClientSocket();

 private:
  ClientSocket socket_;
  std::string url_;

  Server& server_;
//  ServerBlock* server_block_;
//  Request request_;
//  Response response_;
};

#endif