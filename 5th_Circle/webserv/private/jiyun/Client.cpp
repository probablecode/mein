#include "Client.hpp"
#include  <iostream>

// public **********************************************************************

Client::Client(Server& server, int server_socket_fd) : server_(server), socket_(server_socket_fd) {
  is_server_ = false;
  is_client_ = true;
  std::cout << "Client class is properly constructed\n";
}

Client::~Client() {
  std::cout << "Client class is properly destructed\n";
}

ClientSocket& Client::GetClientSocket() {
  return socket_;
}
// private *********************************************************************

