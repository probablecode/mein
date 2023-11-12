#include "Udata.hpp"

// public **********************************************************************

//  constructors & destructor --------------------------------------------------

Udata::Udata() {
  ;
}

//  destructor constructor
Udata::~Udata() {
  ;
}

bool Udata::IsServer() {
	return (is_server_ && !is_client_);
}
bool Udata::IsClient() {
	return (is_client_ && !is_server_);
}

// private *********************************************************************
