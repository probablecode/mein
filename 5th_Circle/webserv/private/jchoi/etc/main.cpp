#include "Socket.hpp"
int	main(void)
{
	Socket socket(8080, BACKLOG);
	cout << "끝!\n";
	return (0);
}
