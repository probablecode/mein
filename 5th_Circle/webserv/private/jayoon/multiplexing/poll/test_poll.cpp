#include <stdio.h>
#include <cstring>
#include <unistd.h>
#include <poll.h>

int	main()
{
	char name[256];
	int counter = 0;
	struct pollfd mypoll;
	int timeout = 1000;

	memset(&mypoll, 0, sizeof(mypoll));
	mypoll.fd = STDIN_FILENO;
	mypoll.events = POLLIN;

	printf("Enter your name: ");

	while (1)
	{
		//if (poll(&mypoll, 1, timeout) == 1)
		poll(&mypoll, 1, timeout);
		// 직접 해당 fd를 확인하는 것이 아니라, poll 함수가 해당 fd를 확인하고, 그 결과를 mypoll에 저장한다.
		if (mypoll.revents & POLLIN) // 특정 fd 에 대한 mypoll 의 revents 를 확인한다.
		{
			read(0, name, sizeof(name));
			printf("Hello %s\n", name);
			break;
		}
		else
		{
			counter++;
		}
	}

	//printf("It took you %d ms to type in your name.\n", counter * timeout);
	printf("It took you %d s to type in your name.\n", counter);

	return 0;
}