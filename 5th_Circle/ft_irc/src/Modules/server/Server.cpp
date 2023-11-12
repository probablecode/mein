#include "Server.hpp"

// public **********************************************************************

//  constructors & destructor --------------------------------------------------

//  default constructor
Server::Server(int port, const std::string& password)
    : port_(port), password_(password) {
  // print server created! -> erase it if you want!!
  std::stringstream ss;
  ss << "Server created!!\n port: " << port_ << "\n password: " << password_
     << std::endl;
  std::cout << MyString::ColorString(ss.str(), MyString::kCyan,
                                     MyString::kPreset)
            << std::endl;
}

//  destructor
Server::~Server() {
  // TODO
}

//  static functions -----------------------------------------------------------

// check port : return port if valid, throw exception if invalid
int Server::CheckPort(const char* port) {
  std::string port_str(port);
  // check port_str length
  if (port_str.length() > 5)
    throw MyExceptions(MyExceptions::kServer, "Invalid port");
  // check port_str characters : allows only digits
  int port_int;
  try {
    port_int = std::stoi(port);
  } catch (std::exception& e) {
    throw MyExceptions(MyExceptions::kServer, "Invalid port");
  }
  // check port_int range
  if (port_int < kPortMin || port_int > kPortMax)
    throw MyExceptions(MyExceptions::kServer, "Invalid port");
  return port_int;
}

// check password : return password if valid, throw exception if invalid
std::string Server::CheckPassword(const char* password) {
  std::string password_str(password);
  // check password length
  if (password_str.length() < kPasswordMinLength)
    throw MyExceptions(MyExceptions::kServer, "Password too short");
  if (password_str.length() > kPasswordMaxLength)
    throw MyExceptions(MyExceptions::kServer, "Password too long");
  // check password characters : allows alphanumeric characters, underscore and
  // !@#$%^&*()-+ characters
  for (int i = 0; i < password_str.length(); ++i) {
    if (!std::isalnum(password_str[i]) && password_str[i] != '_' &&
        password_str[i] != '!' && password_str[i] != '@' &&
        password_str[i] != '#' && password_str[i] != '$' &&
        password_str[i] != '%' && password_str[i] != '^' &&
        password_str[i] != '&' && password_str[i] != '*' &&
        password_str[i] != '(' && password_str[i] != ')' &&
        password_str[i] != '-' && password_str[i] != '+')
      throw MyExceptions(MyExceptions::kServer, "Invalid password");
  }
  return password_str;
}

//  functions ------------------------------------------------------------------

// set server
void Server::Set() {
  // // create server socket
  // server_socket_ = Socket::CreateSocket();
  // // set server socket to non-blocking
  // Socket::SetNonBlocking(server_socket_);
  // // set server address
  // server_addr_.sin_addr.s_addr = INADDR_ANY;
  // server_addr_.sin_family = AF_INET;
  // server_addr_.sin_port = htons(port_);
  // // bind server socket
  // Socket::Bind(port_, server_socket_, server_addr_);
  // // listen server socket
  // Socket::Listen(server_socket_);
  // // create kqueue
  // //  TODO
  // // add server socket to kqueue
}

// run server
void Server::Run() {
  // TODO
}

// private *********************************************************************
