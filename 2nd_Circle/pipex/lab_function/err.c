#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/errno.h>

int	main(void)
{
	int n;
	printf("%d\n", n);
	n = system("mv /Users/sjo /Users/sjoooo");
	printf("This is return of system (permission denied) : %d\n", n);
	printf("This is errno : %d\n", errno);
	return (0);
}





/*
printf("This is errno : %d\n", errno);
	printf("This is sys_nerr : %d\n", sys_nerr);
	for (int i = 0; i <= sys_nerr; i++)
		printf("[%d] : %s\n", i, sys_errlist[i]);
*/	
