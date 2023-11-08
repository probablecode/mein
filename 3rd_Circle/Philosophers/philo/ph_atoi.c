/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchoi <jchoi@student.42Seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 18:05:20 by jchoi             #+#    #+#             */
/*   Updated: 2022/09/06 15:19:08 by jchoi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	ph_isdigit(int c)
{
	return ('0' <= c && c <= '9');
}

static char	*ph_skip(char *s)
{
	while (*s)
	{
		if (*s - '\t' && *s - '\n' && *s - '\v')
		{
			if (*s - '\f' && *s - '\r' && *s - ' ')
				return (s);
		}
		s++;
	}
	return (NULL);
}

int	ph_atoi(char *str, void *val, size_t size)
{
	int		idx;
	int		sign;
	long	ret;

	str = ph_skip(str);
	if (!str)
		return (FALSE);
	sign = (*str != '-') - (*str == '-');
	str += (*str == '+' || *str == '-');
	ret = 0;
	idx = 0;
	while (str[idx] != 0)
	{
		if (!ph_isdigit(str[idx]))
			return (FALSE);
		ret *= 10L;
		ret += (str[idx++] - '0');
	}
	if (idx == 0 || 11 < idx || sign <= 0 || ret == 0 || 2147483647L < ret)
		return (FALSE);
	if (size == sizeof(int))
		*((int *)val) = (int)ret;
	else if (size == sizeof(long long))
		*((long long *)val) = (long long)ret;
	return (TRUE);
}
