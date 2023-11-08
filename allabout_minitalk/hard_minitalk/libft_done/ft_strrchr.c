/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchoi <jchoi@student.42Seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 19:16:49 by jchoi             #+#    #+#             */
/*   Updated: 2022/01/10 15:43:15 by jchoi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
char	*ft_strrchr(const char *s, int c)
{
	char	*ptr;
	char	ch;

	ch = (char)c;
	ptr = (char *)s;
	while (*ptr)
		ptr++;
	while (s <= ptr && *ptr != ch)
		ptr--;
	if (ptr < s)
		ptr = NULL;
	return (ptr);
}
