/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchoi <jchoi@student.42Seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 08:52:41 by jchoi             #+#    #+#             */
/*   Updated: 2022/09/06 11:38:14 by jchoi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ph_calloc(void **ptr, int num, size_t size)
{
	*ptr = malloc(num * size);
	if (!(*ptr))
		return (FALSE);
	memset(*ptr, 0, num * size * sizeof(unsigned char));
	return (TRUE);
}

int	ph_curtime(long	long *ms)
{
	struct timeval	tval;

	if (gettimeofday(&tval, NULL) == ERROR)
		return (FALSE);
	*ms = (long long)(tval.tv_sec * 1000 + tval.tv_usec / 1000);
	return (TRUE);
}

int	ph_wait(long long start, long long arg)
{
	long long		cur;

	ph_curtime(&cur);
	usleep((arg - (cur - start)) * 900);
	while (TRUE)
	{
		ph_curtime(&cur);
		if (start + arg <= cur)
			return (TRUE);
		usleep(100);
	}
}
