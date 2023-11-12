#include "ClientSocket.hpp"

// public **********************************************************************

//  constructors & destructor --------------------------------------------------

ClientSocket::ClientSocket() {} //  default constructor
ClientSocket::ClientSocket(const ClientSocket &src) {*this = src;} //  copy constructor
ClientSocket::~ClientSocket() {} //  destructor

//  operators ------------------------------------------------------------------
//  = operator overloading
ClientSocket &ClientSocket::operator=(const ClientSocket &rhs) {
  if (this == &rhs) {return *this;}
  Socket::operator=(rhs);
  return *this;
}
// Initiation
void ClientSocket::InitClientSocket(int server_socket_fd) {
	AcceptSocket(int server_socket_fd);
	NonBlockSocket();
}

// private *********************************************************************
// functions
void AcceptSocket(int server_socket_fd) {
 if ((socket_fd_ = accept(server_socket_fd, (struct sockaddr *)&sa_in_, &socket_len_)) == -1)
	throw MyExceptions(MyExceptions::kSocket, "accept() fail");
}
