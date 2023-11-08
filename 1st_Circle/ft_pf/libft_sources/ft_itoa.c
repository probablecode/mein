/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchoi <jchoi@student.42Seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 18:25:52 by jchoi             #+#    #+#             */
/*   Updated: 2022/01/05 14:50:51 by jchoi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
char	*ft_itoa(int n)
{
	int		sign;
	int		i;
	int		j;
	int		digits[10];
	char	*str;

	sign = (0 < n) - (n < 0);
	i = 0;
	while (n != 0)
	{
		digits[i++] = n % 10;
		n /= 10;
	}
	str = (char *)ft_calloc(i + (sign <= 0) + 1, sizeof(char));
	if (str)
	{
		j = 0;
		if (sign <= 0)
			str[j++] = (sign < 0) * '-' + (sign == 0) * '0';
		while (0 < i--)
			str[j++] = digits[i] * sign + '0';
		str[j] = '\0';
	}
	return (str);
}
