#include "Socket.hpp"

// static variables ------------------------------------------------------------

socklen_t Socket::socket_len_ = sizeof (struct sockaddr_in);

// public **********************************************************************

//  constructors & destructor --------------------------------------------------
Socket::Socket() {} //  default constructor
Socket::Socket(const Socket &src) {*this = src;} //  copy constructor
Socket::~Socket() {} //  destructor

//  operators ------------------------------------------------------------------
//  = operator overloading
Socket &Socket::operator=(const Socket &rhs) {
  if (this == &rhs) {return *this;}
  this->socket_fd_ = rhs.socket_fd_;
  this->sa_in_ = rhs.sa_in_;
  return *this;
}

// getters & setters
int Socket::GetSocketFD() const {return socket_fd_;}

unsigned short Socket::GetPort() const {return sa_in_.sin_port;}

// protected *********************************************************************
// functions
void Socket::NonBlockSocket() const {
	if (fctnl(socket_fd_, F_SETFL, O_NONBLOCK) == -1)
	  throw MyExceptions(MyExceptions::kSocket, "fctnl() fail");
}

void Socket::SetSocketOption(int level, int option_name, const int* option_value) const {
  socklen_t option_len = sizeof(*option_value);
  if (setsockopt(socket_fd_, level, option_name, option_value, option_len) == -1)
	  throw MyExceptions(MyExceptions::kSocket, "setsockopt() fail");
}
