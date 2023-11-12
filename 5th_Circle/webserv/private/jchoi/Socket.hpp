/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Socket.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoyoo <seoyoo@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 17:55:25 by seoyoo            #+#    #+#             */
/*   Updated: 2023/05/28 00:22:43 by jchoi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SOCKET_HPP_
#define SOCKET_HPP_
////////////////////////////////////
#include <cstdlib>
#include <iostream>
#include <sys/socket.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>

#include <arpa/inet.h>
#define kBackLog 100

///////////////////////////////
class Socket {
	enum SocketType { kServerSocket, kClientSocket};
	public:
		Socket(uint32_t addr, unsigned short port); //Server_Socket Constructor
		Socket(int server_socket_fd); // Client_Socket Constructor
		//Socket(const Socket &src);
		~Socket();
		int	GetSocketFD();
		unsigned short	GetPort();
	private:
		static socklen_t	socklen_;
		static const int	backlog_ = 100;
		
		int	socket_fd_;    
		struct sockaddr_in	sa_in_;
		enum SocketType socket_type_;
		
		void	CreateSocket(int domain, int type);
		void	BindSocket();
		void	ListenSocket();
		void	NonBlockSocket();
		void	AcceptSocket(int server_socket_fd);
/*		class SocketException : public std::exception {
		//	private :
		//		static const char* std::string	error_msg_;
//			public : 
///				SocketException(std::string msg) : error_msg_(msg) {}
						//return (error_msg_.c_str());
				}
		};*/
};
#endif
