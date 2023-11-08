/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchoi <jchoi@student.42Seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 18:06:53 by jchoi             #+#    #+#             */
/*   Updated: 2022/06/26 22:37:51 by jchoi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_istrimmed(char ch, char const *set)
{
	size_t	setlen;
	size_t	i;

	setlen = ft_strlen(set);
	i = 0;
	while (i < setlen)
	{
		if (ch == set[i])
			return (1);
		i++;
	}
	return (0);
}

size_t	ft_trimlen(char	const *s1, char const *set, size_t *pre, size_t *pst)
{
	int	len;
	int	i;

	len = (int)ft_strlen(s1);
	*pre = 0;
	i = 0;
	while (i < len && ft_istrimmed(s1[i], set))
	{
		(*pre)++;
		i++;
	}
	*pst = 0;
	i = len - 1;
	while (0 <= i && ft_istrimmed(s1[i], set))
	{
		(*pst)++;
		i--;
	}
	if ((size_t)len <= *pst + *pre)
		return (0);
	return ((size_t)len - *pst - *pre);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	pre;
	size_t	pst;
	size_t	len;
	char	*str;

	if (!s1 || !set)
		return (NULL);
	len = ft_trimlen(s1, set, &pre, &pst);
	str = (char *)ft_calloc(len + 1, sizeof(char));
	if (str != NULL)
		ft_strlcpy(str, s1 + pre, len + 1);
	return (str);
}
