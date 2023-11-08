/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchoi <jchoi@student.42Seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 04:00:28 by jchoi             #+#    #+#             */
/*   Updated: 2022/08/11 16:39:18 by jchoi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

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
