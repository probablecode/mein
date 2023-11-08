#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <signal.h>
#include <string.h>
void	signal_to_char(int bit)
{
	unsigned int	i;
	unsigned int	exp;
	static unsigned int	len = 0;
	static unsigned int	step = 0;
	static unsigned int	ret = 0;
	static unsigned char str[128];
	if (step < 8)
	{
		i = 0;exp = 1;
		while (i++ < step)
			exp *= 2;
		ret += exp * bit;
		usleep(2000);
		//		printf("[%dstep] ret : %d in char %c\n", step, ret, ret);
		step++;
	}
	else if (step == 8)
	{
		if (!ret)
		{
			printf("%s\n", str);
			memset(str, 0, sizeof(str));
			len = 0;
		}
		else
			str[len++] = (unsigned char)ret;
		//		printf("It's time for output[step %d], char : %c, value : %d\n",step, ret, ret);
		step = 0;
		ret = 0;
	}
}
void	USR1(int usr1)
{
	signal_to_char(0);
}

void	USR2(int usr2)
{
	signal_to_char(1);
}

int	main(void)
{
	int pid = getpid();
	printf("pid : %d\n", pid);
	signal(SIGUSR1, USR1);
	signal(SIGUSR2, USR2);
	
	while (1)
	{
		usleep(10000);
	}
	return (0);
}
