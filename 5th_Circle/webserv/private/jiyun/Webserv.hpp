/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Webserv.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoyoo <seoyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 15:36:38 by seoyoo            #+#    #+#             */
/*   Updated: 2023/05/24 14:45:351 by seoyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef WEBSERV_HPP_
#define WEBSERV_HPP_

#include <iostream>
#include <string>
#include <vector>
#include <map>

#include "Server.hpp"
#include "Client.hpp"
#include "Config.hpp"

class Webserv {
 public:
  // constructors & destructor
  Webserv(Config& config);
  ~Webserv();
  // functions
//  void Run(void);

 private:
  std::vector<Server> servers_;
//  std::map<int, Client> clients_;
//  std::vector<struct kevent> change_list_;

  void InitWebserv(Config& config);
  void FillServerField(Config &config, std::map<std::string, Server>& uniq_listen_server);

//  void AddListenSocketEventInChageList();
//
//  void ManageServerReadEvent(struct kevent& current_event);
//  void ManageClientReadEvent(struct kevent& current_event, class Client& client_instance);
//  void ManageClientWriteEvent(struct kevent& current_event, class Client& client_instance);
//
//
//  void AddChangeList(uintptr_t ident, int16_t filter, uint16_t flags, uint32_t fflags, intptr_t data, void* udata);
//  void ClearChangeList();
//
//  bool IsErrorFlags(uint16_t flags) const;
//  bool IsReadEvent(int16_t filter) const;
//  bool IsWriteEvent(int16_t filter) const;
//
//  // tmp
//  void SetServers();
};

#endif