#include "Client.hpp"

// public **********************************************************************

//  constructors & destructor --------------------------------------------------

//  default constructor
Client::Client(int client_fd, Server &server) : kFd_(client_fd), server_(server) {
  // TODO
}

//  copy constructor
Client::Client(const Client &src) : kFd_(src.kFd_), server_(src.server_) {
  *this = src;
  // TODO
}

//  destructor
Client::~Client() {
  // TODO
}

//  operators ------------------------------------------------------------------

//  = operator overloading
Client &Client::operator=(const Client &rhs) {
  if (this == &rhs) {
    return *this;
  }
  // copy variables
  nickname_ = rhs.nickname_;
  username_ = rhs.username_;
  channels_ = rhs.channels_;  // TODO: NEED TO BE CHECKED!!
  mode_ = rhs.mode_;
  // add more when variables are added
  return *this;
}

// private *********************************************************************
