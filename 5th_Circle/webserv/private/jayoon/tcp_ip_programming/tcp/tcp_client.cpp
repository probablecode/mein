#include <iostream>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <cstring>
#include <unistd.h>

void error_handling(const char* message)
{
	std::cerr << message << std::endl;
	exit(1);
}

int main(int argc, char* argv[])
{
	if (argc != 3)
	{
		std::cout << "Usage : " << argv[0] << " <IP> <port>" << std::endl;
		exit(1);
	}

	int	sock;
	struct sockaddr_in serv_addr;

	sock = socket(AF_INET, SOCK_STREAM, 0);
	if (sock == -1)
		error_handling("socket() error");

	memset(&serv_addr, 0, sizeof(serv_addr));
	serv_addr.sin_family = AF_INET;
	serv_addr.sin_addr.s_addr = inet_addr(argv[1]); 
	serv_addr.sin_port = htons(atoi(argv[2]));

	if (connect(sock, (sockaddr*)&serv_addr, sizeof(serv_addr)) == -1)
		error_handling("connect() error");
	
	char message[42];
	int idx = 0;
	int read_len = 0;
	int	str_len = 0;

	while (1)
	{
		read_len = read(sock, &message[idx], 1);
		if (read_len == 0)
			break;
		if (read_len == -1)
			error_handling("read() error!");
		str_len += read_len;
		idx++;
	}
	std::cout << "Message from server: " << message << std::endl;
	std::cout << "Function read call count: " << str_len << std::endl;
	close(sock);
	return 0;
}
