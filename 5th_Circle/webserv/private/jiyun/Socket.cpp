#include "Socket.hpp"

//public ConstructSocketException {
    // here should we write our additional custom error handling
    // especially related with 'errno'

socklen_t Socket::socklen_ = sizeof(struct sockaddr_in);

Socket::Socket() {
  ;
}

Socket::~Socket() {
  ;
}

int  Socket::GetSocketFD() const {
  return (socket_fd_);
}

unsigned short  Socket::GetPort() const {
  return (sa_in_.sin_port);
}

void  Socket::NonBlockSocket() const
{
  if (fcntl(socket_fd_, F_SETFL, O_NONBLOCK) == -1)
    std::cout << "NonBlockSocket(fcntl)Exception Occur\n";
//    throw SocketException("NonBlockSocket(fcntl)Exception Occur\n");
}

void  Socket::SetSocketOption(int level, int option_name, const int* option_value) const {
  socklen_t option_len = sizeof(*option_value);

  if (setsockopt(socket_fd_, level, option_name, option_value, option_len) == -1)
    std::cout << "SetSocketOptionException Occur\n";
    // throw SocketException("SetSocketOptionException Occur\n");
}
