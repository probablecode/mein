#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>

int	main(void)
{
	pid_t	pid;
	pid_t	ret;
	int		status;
	int		i=0;
	pid = fork();
	if (pid == -1)
		return (1);
	else if (!pid)
	{
		printf("Child: I will yield Exit Code 2\n");
		while(1)
			i++;

		return (42);
	}
	else
	{
		printf("Parent: I have a Child with pid %d\n", pid);

			printf("Parent: Successfully got status from %d Child\n", ret);
			
printf("Parent: Exit Code is %d, Signal is %d\nand the status : %d\n", WEXITSTATUS(status), WTERMSIG(status),status);			ret = wait(&status);
		while (1)
		{
			sleep(1);
			printf("Parent: Successfully got status from %d Child\n", ret);
			printf("Parent: Exit Code is %d, Signal is %d\nand the status : %d\n", WEXITSTATUS(status), WTERMSIG(status),status);
		}
	}
	return (0);
}
