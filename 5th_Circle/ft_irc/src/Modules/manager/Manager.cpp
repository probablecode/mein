#include "Manager.hpp"

// public **********************************************************************

//  constructors & destructor --------------------------------------------------

//  default constructor
Manager::Manager(Server &server) : server_(server) {
  // TODO
}

//  copy constructor
Manager::Manager(const Manager &src) : server_(src.server_) {
  *this = src;
  // TODO
}

//  operators ------------------------------------------------------------------

//  = operator overloading
Manager &Manager::operator=(const Manager &rhs) {
  if (this == &rhs) {
    return *this;
  }
  // TODO
  return *this;
}

// private *********************************************************************
