// This is the main file of the project.

#include <iostream>
#include <string>

#include "Server.hpp"

int main(int argc, char **argv) {
  // check argc
  if (argc != 3) {
    std::cout << "Usage: " << argv[0] << " <port> <password>" << std::endl;
    return 1;
  }
  // check port and password
  int port;
  std::string password;
  try {
    port = Server::CheckPort(argv[1]);
    password = Server::CheckPassword(argv[2]);
  } catch (MyExceptions &e) {
    std::cout << e.What() << std::endl;
    return 1;
  }
  Server irc_server(port, password);
  try {
    irc_server.Set();
  } catch (MyExceptions &e) {
    std::cout << e.What() << std::endl;
    std::cout << "Server setting failed" << std::endl;
    return 1;
  }
  try {
    irc_server.Run();
  } catch (MyExceptions &e) {
    std::cout << e.What() << std::endl;
    std::cout << "Fatal error occurred while running server" << std::endl;
    return 1;
  }
  return 0;
}