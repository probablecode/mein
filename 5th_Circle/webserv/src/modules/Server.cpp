/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Server.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwolee <jiwolee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 17:52:38 by seoyoo            #+#    #+#             */
/*   Updated: 2023/05/29 21:41:55 by jchoi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "Server.hpp"
// public **********************************************************************

//  constructors & destructor --------------------------------------------------

//  constructor
Server::Server(uint32_t addr, unsigned short port) : socket_(addr, port) {
  is_server_ = true;
  is_client_ = false;
  std::cout << "Server socket is properly constructed \n";
  std::cout << "Server socket fd: " << socket_.GetSocketFD() << '\n';
  std::cout << "Server socket port: " << ntohs(socket_.GetPort()) << '\n';
}


//  destructor constructor
Server::~Server() {
  std::cout << "Client class is properly destructed\n";
}


ListeningSocket& Server::GetListenSocket() {
  return (socket_);
}

void Server::AddServerBlock(ServerConfig &server_config) {
  ServerBlock new_server_block(server_config.GetServerNames());
  new_server_block.SetServerLocation(server_config.GetServerLocationConfig());

  const std::vector<LocationConfig>& location_configs = server_config.GetLocationConfigs();
  std::vector<LocationConfig>::const_iterator iter = location_configs.begin();
  for(;iter != location_configs.end(); iter++) {
	new_server_block.AddLocations(*iter);
  }
  server_blocks_.push_back(new_server_block);
}

// private *********************************************************************

