#ifndef CLIENT_HPP_
#define CLIENT_HPP_

#include <map>
#include <string>

#include "Channel.hpp"
#include "MyUtils.hpp"
#include "Server.hpp"

class Channel;
class Server;

class Client {
 public:
  enum Mode {
    kModeI = 1 << 0,  // i - marks a users as invisible;
    kModeS = 1 << 1,  // s - marks a user for receipt of server notices;
    kModeW = 1 << 2,  // w - user receives wallops;
    kModeO = 1 << 3   // o - operator flag.
  };
  // constructors & destructor
  Client(int client_fd, Server &server);
  Client(const Client &src);
  ~Client();
  // operators
  Client &operator=(const Client &rhs);
  // functions
  int GetFd() const { return kFd_; }

 private:
  // constants
  const int kFd_;
  const Server &server_;
  // variables
  std::string nickname_;
  std::string username_;  // TODO : Should it be constant?
  std::map<std::string, Channel *> channels_;  // channel name, channel *
  char mode_;  // mode flag using bitwise operation
};

#endif