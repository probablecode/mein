/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Socket.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoyoo <seoyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 17:55:43 by seoyoo            #+#    #+#             */
/*   Updated: 2023/05/28 00:25:48 by jchoi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Socket.hpp"

//public ConstructSocketException {
		// here should we write our additional custom error handling
		// especially related with 'errno'

socklen_t Socket::socklen_ = sizeof(struct sockaddr_in);

Socket::Socket(uint32_t addr, unsigned short port) {
	// Server_Socket Constructor
	try	{
		CreateSocket(PF_INET, SOCK_STREAM);
		memset(&sa_in_, 0, sizeof(sa_in_));
		sa_in_.sin_family = AF_INET;
		sa_in_.sin_addr.s_addr = htonl(addr);
		sa_in_.sin_port = htons(port);
		BindSocket();
		ListenSocket();
		NonBlockSocket();
		socket_type_ = kServerSocket;
		// after this we should register this socket's read event on our kqueue
	}
	catch (std::exception& e) {
		std::cout << e.what();
//		throw SocketException("Socket Contruction Failure\n");
	}
}

Socket::Socket(int server_socket_fd) {
	// Client_Socket Constructor
	try {
		AcceptSocket(server_socket_fd);
		NonBlockSocket();
		socket_type_ = kClientSocket;
	}
	catch (std::exception& e) {
		std::cout << e.what();
//		throw SocketException("Socket Contruction Failure\n");
	}
}

Socket::~Socket() {
	if (close(socket_fd_)) // maybe we need to close socket fd
		std::cout << "Socket CloseException Occur (fd : " << socket_fd_ << ")\n";
}

int	Socket::GetSocketFD() {
	return (socket_fd_);
}

unsigned short	Socket::GetPort() {
	return (sa_in_.sin_port);
}

void	Socket::AcceptSocket(int server_socket_fd) {
	if ((socket_fd_ = accept(server_socket_fd, (struct sockaddr *)&sa_in_, &socklen_)) == -1)
	{
		std::cout << errno << "\n";
		std::cout << "AcceptSocketException Occur\n";
	}
	//		throw SocketException("AcceptSocketException Occur\n");
}


void	Socket::CreateSocket(int domain, int type) {	
	if ((socket_fd_ = socket(domain, type, 0)) == -1)
		std::cout << "CreateSocketException Occur\n";
//		throw SocketException("CreateSocketException Occur\n");
}

void	Socket::BindSocket()
{
	if (bind(socket_fd_, (struct sockaddr *)&sa_in_, socklen_) == -1)
		std::cout << "BindSocketException Occur\n";
//		throw SocketException("BindSocketException Occur\n");
}

void	Socket::ListenSocket()
{
	if (listen(socket_fd_, backlog_) == -1) // define kBackLog == 100
		std::cout << "ListenSocketException Occur\n";
//		throw SocketException("ListenSocketException Occur\n");
}

void	Socket::NonBlockSocket()
{
	if (fcntl(socket_fd_, F_SETFL, O_NONBLOCK) == -1)
		std::cout << "NonBlockSocket(fcntl)Exception Occur\n";
//		throw SocketException("NonBlockSocket(fcntl)Exception Occur\n");
}
