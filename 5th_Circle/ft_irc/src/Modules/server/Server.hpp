#ifndef SERVER_HPP_
#define SERVER_HPP_

#include <iostream>
#include <map>
#include <sstream>
#include <string>
#include <vector>

#include "Channel.hpp"
#include "Client.hpp"
#include "MyUtils.hpp"
#include "Socket.hpp"

class Client;
class Channel;

class Server {
 public:
  // constructors & destructor
  Server(int port, const std::string& password);
  ~Server();
  // static functions
  static int CheckPort(const char* port);
  static std::string CheckPassword(const char* password);
  // functions
  void Set();
  void Run();
  // getters & setters
  const std::map<std::string, Channel*>& GetChannels() const {
    return channels_;
  }
  const std::map<int, Client*>& GetClients() const { return clients_; }
  Channel* GetChannel(const std::string& channel_name) const;
  Client* GetClient(int client_fd) const;

 private:
  // constants
  const static int kPortMin = 0;
  const static int kPortMax = 65535;
  const static int kPasswordMinLength = 4;
  const static int kPasswordMaxLength = 32;
  const static int kEventMax = 100;
  const static int kBufferSize = 1024;
  const static int kMaxClients = 100;
  // variables
  static int server_count_;
  int port_;
  std::string password_;
  int server_socket_;
  sockaddr_in server_addr_;
  std::map<std::string, Channel*> channels_;  // channel name, channel pointer
  std::map<int, Client*> clients_;            // client fd, Client pointer
};

#endif