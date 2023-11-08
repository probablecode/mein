/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchoi <jchoi@student.42Seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 17:14:39 by jchoi             #+#    #+#             */
/*   Updated: 2022/06/26 22:36:06 by jchoi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{	
	size_t	len;
	size_t	i;

	if (s)
	{
		len = ft_strlen(s);
		i = 0;
		while (i < len)
			ft_putchar_fd(s[i++], fd);
	}
}
