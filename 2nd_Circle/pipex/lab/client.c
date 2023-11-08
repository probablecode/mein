/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchoi <jchoi@student.42Seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 22:18:17 by jchoi             #+#    #+#             */
/*   Updated: 2022/05/30 16:17:25 by jchoi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <signal.h>
#include <string.h>
void	char_to_signal(int pid, unsigned int ch)
{
	int	i;

	i = 0;
	//printf("I got char : %c\n", ch);
	while (i < 8)
	{
		if (ch % 2)
		{
			kill(pid, SIGUSR2);
		}
		else
		{
			kill(pid, SIGUSR1);
		}
		//printf ("[%d] : ch = %d, ch %% 2 = %d, kill to %d USR\n", i, ch, ch % 2 , pid);
		ch /= 2;
		i++;
		usleep(10000);
	}

	kill(pid, SIGUSR1);
	//printf("hey! it's time for output!\n");
}

int	main(int argc, char *argv[])
{
	int		i = 0;
	int		pid;
	unsigned char	ch[128];
	if (argc == 3)
	{//ft_atoi를 써야한다!
		pid = atoi(argv[1]);
		if (0 < pid)
		{
			strcpy(ch, argv[2]);
			while (ch[i])
			{
				char_to_signal(pid, (unsigned int)ch[i]);
				usleep(100000);
				i++;
			}
			char_to_signal(pid, (unsigned int)ch[i]);
		}
	}
	return (0);
}
