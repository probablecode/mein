/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchoi <jchoi@student.42Seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 17:45:25 by jchoi             #+#    #+#             */
/*   Updated: 2022/06/26 22:30:22 by jchoi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static const char	*ft_skip(const char *s)
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

static long	ft_count(const char *n)
{
	long		num;
	size_t		digits;

	digits = 0;
	num = 0;
	while (ft_isdigit(*n))
	{
		digits++;
		num *= 10;
		num += (*n - '0');
		if (18 == digits)
		{
			if (922337203685477580L < num && ft_isdigit(n[1]))
				return (-1);
			else if (922337203685477580L == num && (n[1] == '8' || n[1] == '9'))
				return (-1);
		}
		else if (19 < digits)
			return (-1);
		n++;
	}
	return ((long)num);
}

int	ft_atoi(const char *str)
{
	long	sign;
	long	ret;

	sign = 1;
	str = ft_skip(str);
	if (str != NULL)
	{
		if (*str == '+' || *str == '-')
		{
			sign = (*str == '+') - (*str == '-');
			str++;
		}
		ret = ft_count(str);
		if (ret == -1)
			return (-(sign == 1));
		return ((int)(sign * ft_count(str)));
	}
	return (0);
}
