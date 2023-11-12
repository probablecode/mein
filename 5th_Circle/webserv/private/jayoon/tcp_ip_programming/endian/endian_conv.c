#include <arpa/inet.h>
#include <stdio.h>

int	main(int argc, char* argv[])
{
	unsigned short	host_port = 0x1234;
	unsigned short	net_port;

	net_port = htons(host_port);
	printf("order of host bytes: %x\n", host_port);
	printf("order of network bytes: %x\n", net_port);


}