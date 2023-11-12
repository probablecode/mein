#include "ListeningSocket.hpp"

ListeningSocket::ListeningSocket(uint32_t addr, unsigned short port){
  const int option_value = static_cast<int>(true);

  try  {
    CreateSocket(PF_INET, SOCK_STREAM);
    SetSocketOption(SOL_SOCKET, SO_REUSEADDR, &option_value);
    memset(&sa_in_, 0, sizeof(sa_in_));
    sa_in_.sin_family = AF_INET;
    sa_in_.sin_addr.s_addr = htonl(addr);
    sa_in_.sin_port = htons(port);
    BindSocket();
    ListenSocket();
    NonBlockSocket();
  //  socket_type_ = kServerSocket;
    // after this we should register this socket's read event on our kqueue
  }
  catch (std::exception& e) {
    std::cout << e.what();
//    throw SocketException("Socket Contruction Failure\n");
  }
}

ListeningSocket::~ListeningSocket() {
//   if (close(socket_fd_)) // maybe we need to close socket fd
//    std::cout << "Socket CloseException Occur (fd : " << socket_fd_ << ")\n";
}

void  ListeningSocket::CreateSocket(int domain, int type) {  
  if ((socket_fd_ = socket(domain, type, 0)) == -1)
    std::cout << "CreateSocketException Occur\n";
//    throw SocketException("CreateSocketException Occur\n");
}

void  ListeningSocket::BindSocket() const {
  if (bind(socket_fd_, (struct sockaddr *)&sa_in_, socklen_) == -1) {
	perror("bind error: ");
	std::cout << errno << " << errno\n";
	std::cout << "BindSocketException Occur\n";
  }
//    throw SocketException("BindSocketException Occur\n");
}

void  ListeningSocket::ListenSocket() const {
  if (listen(socket_fd_, backlog_) == -1) // define kBackLog == 100
    std::cout << "ListenSocketException Occur\n";
//    throw SocketException("ListenSocketException Occur\n");
}
