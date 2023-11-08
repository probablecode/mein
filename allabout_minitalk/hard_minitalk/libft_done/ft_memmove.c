/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchoi <jchoi@student.42Seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 13:24:53 by jchoi             #+#    #+#             */
/*   Updated: 2022/01/12 08:39:21 by jchoi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*dstptr;
	unsigned char	*srcptr;

	if (dst < src)
		return (ft_memcpy(dst, src, len));
	else if (src < dst)
	{
		dstptr = (unsigned char *)dst;
		srcptr = (unsigned char *)src;
		while (0 < len--)
			dstptr[len] = srcptr[len];
	}
	return (dst);
}
