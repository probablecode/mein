// This class is static class for socket manipulation. Therefore, instances will
// not be created. Also, there will be only static functions in this class. So,
// we can make this class static class.
// MUST!! All socket management in this project will be done by this class.
#ifndef SOCKET_HPP_
#define SOCKET_HPP_

#include <arpa/inet.h>
#include <fcntl.h>
#include <sys/event.h>
#include <sys/socket.h>
#include <sys/stat.h>
#include <sys/time.h>
#include <sys/types.h>
#include <unistd.h>

#include <iostream>
#include <string>

#include "MyUtils.hpp"

class Socket {
 public:
  // functions
  static int CreateSocket();
  static void Bind(int port, const char *ip, int server_fd,
                   struct sockaddr_in &server_addr);
  static void Bind(int port, int server_fd, struct sockaddr_in &server_addr);
  static void Listen(int server_fd);
  static int Accept(int server_fd);
  static void SetNonBlocking(int fd);
  static void SetBlocking(int fd);
  static void Connect(int fd, int port, const char *ip);
  static void Send(int fd, const char *message);
  static void Send(int fd, const std::string &message);
  static std::string Receive(int fd);
  static void Close(int fd);

 private:
  Socket() {}  // to prevent creating instances
  // constants
  static const int kBufferSize = 1024;
  static const int kBacklog = 10;
  static const int kTimeout = 5;
};

#endif