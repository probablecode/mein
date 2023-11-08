/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchoi <jchoi@student.42Seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 11:15:27 by jchoi             #+#    #+#             */
/*   Updated: 2022/01/12 08:46:29 by jchoi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
static size_t	ft_splitcount(char const *s, char c)
{
	size_t	count;
	size_t	i;
	int		flag;

	count = 0;
	flag = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			if (flag == 0)
			{
				flag = 1;
				count++;
			}
		}
		else
			flag = 0;
		i++;
	}
	return (count);
}

static char	**ft_splitstop(char **split, size_t done)
{
	size_t	k;

	k = 0;
	while (k < done)
	{
		free (split[k]);
		split[k] = NULL;
		k++;
	}
	free (split);
	split = NULL;
	return (split);
}

static char	**ft_splitmaker(char const *s, char c, char **split, size_t count)
{
	char	*check;
	size_t	len;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (i < count)
	{
		while (s[j] == c)
			j++;
		len = 0;
		while (s[j + len] && s[j + len] != c)
			len++;
		check = ft_substr(s, (unsigned int)j, len);
		if (!check)
			return (ft_splitstop(split, i));
		split[i] = check;
		j += len;
		i++;
	}
	split[count] = NULL;
	return (split);
}

char	**ft_split(char const *s, char c)
{
	char	**ret;
	size_t	count;

	if (!s)
		return (NULL);
	count = ft_splitcount(s, c);
	ret = ft_calloc(count + 1, sizeof(char *));
	if (ret)
		ret = ft_splitmaker(s, c, ret, count);
	return (ret);
}
