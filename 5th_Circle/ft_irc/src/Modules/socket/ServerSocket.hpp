#ifndef SERVERSOCKET_HPP_
#define SERVERSOCKET_HPP_

#include "Socket.hpp"

class ServerSocket : public Socket {
 public:
  // constructors & destructor : no meaning in this class
  ServerSocket();
  ServerSocket(const ServerSocket &src);
  ~ServerSocket();
  // operators
  ServerSocket &operator=(const ServerSocket &rhs);
  // Initiation
  InitServerSocket(uint32_t addr, unsigned short port);
 protected:
 private:
  // constant
  static const int kBacklog = 10;
  // functions
  void CreateSocket(int domain, int type);
  void BindSocket() const;
  void ListenSocket() const;
};

#endif
