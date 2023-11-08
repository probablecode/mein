/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchoi <jchoi@student.42Seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 21:17:56 by jchoi             #+#    #+#             */
/*   Updated: 2022/06/26 22:29:33 by jchoi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/libft.h"
#include <signal.h>

void	signal_to_char(int bit)
{
	unsigned int		i;
	unsigned int		exp;
	static unsigned int	step = 0;
	static unsigned int	ret = 0;

	if (step < 8)
	{
		i = 0;
		exp = 1;
		while (i++ < step)
			exp *= 2;
		ret += exp * bit;
		step++;
	}
	else if (step == 8)
	{
		if (!ret)
			return ;
		else
			write(1, &ret, 1);
		step = 0;
		ret = 0;
	}
}

void	usr1(int s1)
{
	(void)s1;
	signal_to_char(0);
}

void	usr2(int s2)
{
	(void)s2;
	signal_to_char(1);
}

int	main(void)
{
	write(1, "pid : ", 6);
	ft_putnbr_fd(getpid(), 1);
	write(1, "\n", 1);
	signal(SIGUSR1, usr1);
	signal(SIGUSR2, usr2);
	while (1)
		usleep(10000);
	return (0);
}
