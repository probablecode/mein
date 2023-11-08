/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchoi <jchoi@student.42Seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 04:00:28 by jchoi             #+#    #+#             */
/*   Updated: 2022/08/02 15:08:50 by jchoi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line_bonus.h"

void	*ft_calloc(size_t count, size_t size)
{	
	void	*ret;

	ret = malloc(count * size);
	if (ret)
		ft_memset(ret, 0, count * size);
	return (ret);
}

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*ch;

	ch = (unsigned char *)b;
	if (len == 0)
		return (b);
	while (0 < len--)
		ch[len] = (unsigned char)c;
	return (b);
}

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	if (s)
	{
		while (s[i])
		i++;
	}
	return ((size_t)i);
}

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

int	gnl_lengthen(char **line, char buf[], size_t len)
{
	char	*new;
	char	tmp[BUFFER_SIZE];
	size_t	prelen;

	prelen = ft_strlen(*line);
	if (prelen < len)
	{
		new = ft_calloc((len + 1), sizeof(char));
		ft_memset(tmp, 0, BUFFER_SIZE);
		if (new)
		{
			ft_memcpy(new, *line, prelen);
			ft_memcpy(new + prelen, buf, len - prelen);
			new[len] = '\0';
			ft_memcpy(tmp, buf + (len - prelen), BUFFER_SIZE - (len - prelen));
		}
		ft_memcpy(buf, tmp, BUFFER_SIZE);
		free(*line);
		*line = new;
		return ((*line != NULL) * TRUE + (*line == NULL) * ERROR);
	}
	else
		return (FALSE);
}
