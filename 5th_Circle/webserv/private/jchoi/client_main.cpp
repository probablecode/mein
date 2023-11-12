#include "Socket.hpp"
int	main(void)
{
	int sock;
	struct sockaddr_in sa_;
	char	wdata[32] = "msg from client to server\n";
	char	rdata[32];

	sock = socket(PF_INET, SOCK_STREAM, 0);
	if (sock == -1)
	{
		std::cout << "socket error\n";
		return (1);
	}
	memset(&sa_, 0, sizeof(sa_));
	sa_.sin_family=AF_INET;
	sa_.sin_addr.s_addr = inet_addr("127.0.0.1");
	sa_.sin_port=htons(8080);
	
	printf("sin_port : %hu\n", sa_.sin_port);
	printf("sin_address : %u\n", sa_.sin_addr.s_addr);
	
	if (connect(sock, (struct sockaddr *)&sa_, sizeof(sa_)) == -1)
	{
		std::cout << "connect() error\n";
		return (1);
	}

	std::cout << "client send to server\n";
	write(sock, wdata, strlen(wdata));
	read(sock, rdata, 32);
	std::cout << "msg received from server : " << rdata;

	sleep(5);

	close(sock);
	std::cout << "클라이언트 끝!\n";
	return (0);
}
