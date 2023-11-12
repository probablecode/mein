#include <iostream>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <cstring>
#include <unistd.h>

void	error_handling(const char* message)
{
	std::cerr << message << std::endl;
	exit(1);
}

int	main(int argc, char* argv[])
{
	int serv_sock;
	struct sockaddr_in serv_addr;
	/*
	struct sockaddr_in {
		__uint8_t       sin_len;
		sa_family_t     sin_family;
		in_port_t       sin_port;  // typedef __uint16_t              in_port_t;
		struct  in_addr sin_addr;   //typedef __uint32_t   in_addr_t;  base type for internet address 
		char            sin_zero[8];
	};
	*/

	if (argc != 2)
	{
		std::cout << "Usage: " << argv[0] << " <port>" << std::endl;
		exit(1);
	}

	serv_sock = socket(PF_INET, SOCK_STREAM, 0);
	if (serv_sock == -1)
		error_handling("socket() error");

	memset(&serv_addr, 0, sizeof(serv_addr));
	serv_addr.sin_family = AF_INET;	
	serv_addr.sin_addr.s_addr = htonl(INADDR_ANY); // 32 bit long// INADDR_ANY: 서버의 IP주소를 자동으로 찾아서 대입해주는 역할 
	serv_addr.sin_port = htons(atoi(argv[1])); // 16 bit short

	if (bind(serv_sock, (struct sockaddr*)&serv_addr, sizeof(serv_addr)) == -1)
		error_handling("bind() error");

	if (listen(serv_sock, 5) == -1)
		error_handling("listen() error");

	int clnt_sock;
	struct sockaddr_in clnt_addr;
	socklen_t clnt_addr_size;

	const char* message = "Hello World!";

	clnt_addr_size = sizeof(clnt_addr); // accept 함수의 세 번째 인자로 두 번째 인자의 크기를 전달해야 한다. 이후 클라이언트의 주소 정보가 저장 된 주소 정보 길이가 저장된다
	clnt_sock = accept(serv_sock, (struct sockaddr*)&clnt_addr, &clnt_addr_size);
	if (clnt_sock == -1)
		error_handling("accept() error");
	
	write(clnt_sock, message, strlen(message) + 1);
	close(clnt_sock);
	close(serv_sock);
	return (0);
}