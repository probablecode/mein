#include "Channel.hpp"

// public **********************************************************************

//  constructors & destructor --------------------------------------------------

//  default constructor
Channel::Channel(Server &server) : server_(server) {
  // TODO
}

//  copy constructor
Channel::Channel(const Channel &src) : server_(src.server_) {
  *this = src;
  // TODO
}

//  destructor
Channel::~Channel() {
  // TODO
}

//  operators ------------------------------------------------------------------

//  = operator overloading
Channel &Channel::operator=(const Channel &rhs) {
  if (this == &rhs) {
    return *this;
  }
  // TODO
  return *this;
}

// private *********************************************************************

