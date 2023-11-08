/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchoi <jchoi@student.42Seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 20:09:59 by jchoi             #+#    #+#             */
/*   Updated: 2022/01/04 11:11:59 by jchoi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	searchlen;
	size_t	i;

	if (ft_strlen(haystack) < len)
		len = ft_strlen(haystack);
	searchlen = ft_strlen(needle);
	if (len >= searchlen)
	{
		len -= searchlen;
		i = 0;
		while (i <= len)
		{
			if (!ft_strncmp(haystack + i, needle, searchlen))
				return ((char *)haystack + i);
			i++;
		}
	}
	return (NULL);
}
