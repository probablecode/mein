#ifndef CHANNEL_HPP_
#define CHANNEL_HPP_

#include <iostream>
#include <map>
#include <string>

#include "Client.hpp"
#include "MyUtils.hpp"
#include "Server.hpp"
#include "Socket.hpp"

class Client;

class Channel {
 public:
  // enums
  enum Type { kPublic, kPrivate, kSecret };  // TODO: NEED TO BE CHECKED!!
  enum Mode {
    kModeI = 1 << 0,  // i: Set/remove Invite-only channel
    kModeT = 1 << 1,  // t: Set/remove the restrictions of the TOPIC command to
                      // channel operators
    kModeK = 1 << 2,  // k: Set/remove the channel key (password)
    kModeO = 1 << 3,  // o: Give/take channel operator privilege
    kModeL = 1 << 4   // l: Set/remove the user limit to channel
  };
  // constructors & destructor
  Channel(Server &server);
  Channel(const Channel &src);
  ~Channel();
  // operators
  Channel &operator=(const Channel &rhs);

 private:
  // constants
  const Server &server_;
  static const int kMaxClientsPerChannel = 100;
  // variables
  Type type_;
  char mode_;  // mode flag using bitwise operation
  std::string name_;
  std::string topic_;
  std::map<int, Client *> clients_;  // client fd, clients *
};
#endif