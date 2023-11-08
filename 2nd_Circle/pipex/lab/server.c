#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <signal.h>
#include <string.h>
void	fct(int sig);
int	main(void)
{
	signal(SIGINT, (void *)fct);
	
	while (1)
	{
	}
	return (0);
}

void	fct(int sig)
{
	perror("error : ");
	printf("hoho %d\n", sig);
}


