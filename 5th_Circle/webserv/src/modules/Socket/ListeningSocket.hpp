#ifndef LISTENING_SOCKET_HPP_
#define LISTENING_SOCKET_HPP_

#include "Socket.hpp"

class ListeningSocket : public Socket {
  public:
    ListeningSocket(uint32_t addr, unsigned short port);
   ~ListeningSocket();
  private:
    static const int	backlog_ = 100;

    void	CreateSocket(int domain, int type);
    void	BindSocket() const;
    void	ListenSocket() const;
};

#endif