/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   jchoi.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoyoo <seoyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 17:55:25 by seoyoo            #+#    #+#             */
/*   Updated: 2023/05/25 20:49:44 by jchoi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SOCKET_HPP_
#define SOCKET_HPP_

#include <arpa/inet.h>

class Socket {
 public:
  Socket(int port, int backlog);
  //Socket(const Socket &src);
  ~Socket();
  int	GetSocketFD();
  unsigned short	GetPort();
  void	CreateSocket(int domain, int type);
  void	BindSocket();
  void	ListenSocket();
  void	NonBlockSocket();

 private:
    int socket_fd_;
    struct sockaddr_in  server_sin_;
};

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Socket.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoyoo <seoyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 17:55:43 by seoyoo            #+#    #+#             */
/*   Updated: 2023/05/23 17:55:55 by seoyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Socket.hpp"

Socket::Socket(unsigned short port, int backlog)
{
	try	{
		this->CreateSocket(PF_INET, SOCK_STREAM);
		memset(&server_sin_, 0, sizeof(server_addr_));
		server_sin_.sin_family = AF_INET;
		server_sin_.addr.s_addr = htonl(INADDR_ANY);
		server_sin_.sin_port = htons(port);
		this->BindSocket();
		this->ListenSocket();
		this->NonBlockSocket();
		// after this we should register this socket's read event on our kqueue
	}
	catch (std::exception e) {
		cout << e.what();
		throw ConstructSocketException;
	}
}

int	Socket::GetSocketFD() {
	return (socket_fd_);
}

unsigned short	Socket::GetPort() {
	return (server_sin_->sin_port);
}

void	Socket::CreateSocket(int domain, int type) {
	class	CreateSocketException : public ConstructSocketException {
		// here should we write our additional custom error handling
		// especially related with 'errno'
		public const char *what() const throw() {
			const char *ret = "CreateSocketException Occur\n";
			return (ret);
		}
	}
	if (socket_fd_ = socket(domain, type, 0) == -1)
		throw CreateSocketException;
}

void	Socket::BindSocket()
{
	class	BindSocketException : public std::exception {
		// custom error handling with errno
		public const char *what() const throw() {
			const char *ret = "BindSocketException Occur\n";
			return (ret);
		}
	}
	if (bind(socket_fd_, (struct sockaddr *)&server_sin_, sizeof(server_sin_)) == -1);
		throw BindSocketException;
}

void	Socket::ListenSocket()
{
	class	ListenSocketException : public std::exception {
		// custom error handling with errno
		public const char *what() const throw() {
			const char *ret = "ListenSocketException Occur\n";
			return (ret);
		}
	}
	if (listen(socket_fd_, BACKLOG) == -1) // typedef BACKLOG == 100
		throw ListenSocketException;
}

void	Socket::NonBlockSocket()
{
	class	NonBlockSocketException : public std::exception {
		// custom error handling with errno
		public const char *what() const throw() {
			const char *ret = "NonBlockSocket(fcntl)Exception Occur\n";
			return (ret);
		}
	}
	if (fcntl(socket_fd_, F_SETFL, O_NONBLOCK) == -1)
		throw NonBlockSocketException;	
}
