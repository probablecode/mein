#include "Socket.hpp"
int	main(void)
{
	char    wdata[32] = "msg from server to client\n";
    char    rdata[32];

	Socket sv_socket(INADDR_ANY, 8080);
	sleep(2);
	Socket cl_socket(sv_socket.GetSocketFD());
	read(cl_socket.GetSocketFD(), rdata, 32);
	std::cout << "msg received from cleint : " << rdata;
	write(cl_socket.GetSocketFD(), wdata, strlen(wdata));
	sleep(3);
	std::cout << "끝!\n";
	return (0);
}
