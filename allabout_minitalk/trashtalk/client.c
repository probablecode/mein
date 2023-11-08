/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchoi <jchoi@student.42Seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 22:18:17 by jchoi             #+#    #+#             */
/*   Updated: 2022/06/26 22:29:40 by jchoi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include "./libft/libft.h"

void	char_to_signal(int pid, unsigned int ch)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		if (ch % 2)
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		ch /= 2;
		i++;
		usleep(100);
	}
	kill(pid, SIGUSR1);
}

int	main(int argc, char *argv[])
{
	int		i;
	char	*ch;
	pid_t	pid;

	if (argc == 3)
	{
		pid = ft_atoi(argv[1]);
		ch = argv[2];
		if (0 < pid)
		{
			i = 0;
			while (ch[i])
			{
				char_to_signal(pid, (unsigned int)ch[i]);
				usleep(1000);
				i++;
			}
			char_to_signal(pid, (unsigned int)ch[i]);
		}
	}
	return (0);
}
