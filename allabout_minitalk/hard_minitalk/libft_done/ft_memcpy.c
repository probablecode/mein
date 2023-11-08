/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchoi <jchoi@student.42Seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 13:18:17 by jchoi             #+#    #+#             */
/*   Updated: 2022/01/12 08:44:14 by jchoi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*dstptr;
	unsigned char	*srcptr;
	size_t			i;

	if (dst != src)
	{
		dstptr = (unsigned char *)dst;
		srcptr = (unsigned char *)src;
		i = 0;
		while (i < n)
		{
			dstptr[i] = srcptr[i];
			i++;
		}
	}
	return (dst);
}
