#include <unistd.h>
#include <stdio.h>

int	main(void)
{
	int pid = -42;
	int pidd = -42;

	printf("[%d] my pid : %d\n",getpid(), pid);
	pid = fork();
	printf("[%d] my pid : %d\n",getpid(), pid);
pidd = fork();
printf("[%d] my pidd : %d\n",getpid(), pidd);
	return (0);
}

/*
int	main(void)
{
	int pid = -42;
	int pidd = -42;

	pid = fork();
	pidd = fork();
	printf("[%d] my pid : %d\tmy pidd : %d\n", getpid(), pid, pidd);
	return (0);
}
*/
