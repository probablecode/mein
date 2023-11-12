#ifndef CLIENTSOCKET_HPP_
#define CLIENTSOCKET_HPP_

#include "Socket.hpp"

class ClientSocket : public Socket {
  public:
    ClientSocket(int server_socket_fd); // Client_Socket Constructor
    ~ClientSocket();
    
    void  AcceptSocket(int server_socket_fd);
};

#endif
