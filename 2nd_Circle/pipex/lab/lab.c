#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
int	main(void)
{
	int pid;
	printf("I am %d\nmy parent is %d\n", getpid(),getppid());
	pid = fork();
	sleep(1);
	if (!pid)
	{
		printf("I am %d\nmy parent is %d\n", getpid(),getppid());
		sleep(5);
		printf("I am %d\nmy parent is %d\n", getpid(),getppid());
	}
	return (0);
}
