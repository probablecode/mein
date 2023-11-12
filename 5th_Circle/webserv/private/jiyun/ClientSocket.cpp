#include "ClientSocket.hpp"

ClientSocket::ClientSocket(int server_socket_fd) {
  // Client_Socket Constructor
  try {
	  AcceptSocket(server_socket_fd);
	  NonBlockSocket();
  }
  catch (std::exception& e) {
    std::cout << e.what();
//    throw SocketException("Socket Contruction Failure\n");
  }
}

ClientSocket::~ClientSocket() {
//   if (close(socket_fd_)) // maybe we need to close socket fd
//    std::cout << "Socket CloseException Occur (fd : " << socket_fd_ << ")\n";
}

void  ClientSocket::AcceptSocket(int server_socket_fd) {
 
 if ((socket_fd_ = accept(server_socket_fd, (struct sockaddr *)&sa_in_, &socklen_)) == -1)
    std::cout << "AcceptSocketException Occur\n";
//    throw SocketException("ListenSocketException Occur\n");
	std::cout << "[ClientSocket] : server_fd(" << server_socket_fd << ") accept new client_fd : (" << socket_fd_ << ")\n";// temporary echo-print
}
