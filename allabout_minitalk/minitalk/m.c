#include <stdio.h>
#include <signal.h>
#include <unistd.h>
int	main(void)
{
	
	kill(getppid(),SIGKILL);
	return (0);
}
