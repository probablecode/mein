#ifndef MANAGER_HPP_
#define MANAGER_HPP_

#include "Server.hpp"
#include "MyUtils.hpp"

class Manager {
 public:
  // constructors & destructor
  Manager(Server &server);
  Manager(const Manager& src);
  ~Manager();
  // operators
  Manager& operator=(const Manager& rhs);

 protected:
 private:
  // constants
  const Server& server_;
  // functions  TODO: Need overloading!!
  Channel* CreateChannel(const std::string& channel_name);
  void DeleteChannel(Channel* channel);
  Client* CreateClient(int client_fd);
  void DeleteClient(Client* Client);
  void AddClientToChannel(Client* client, Channel* channel);
  void RemoveClientFromChannel(Client* client, Channel* channel);
};

#endif