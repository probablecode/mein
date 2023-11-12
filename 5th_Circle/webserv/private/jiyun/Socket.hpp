#ifndef SOCKET_HPP_
#define SOCKET_HPP_

#include <cstdlib>
#include <iostream>
#include <sys/socket.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <fcntl.h>
#include <unistd.h>


class Socket {
  public:
    Socket();
    virtual ~Socket() = 0;
    int	GetSocketFD() const;
    unsigned short GetPort() const;
  protected:
    static socklen_t	socklen_;
    int	socket_fd_;
    struct sockaddr_in	sa_in_;

    void  NonBlockSocket() const;
    void  SetSocketOption(int level, int option_name, const int* option_value) const;
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