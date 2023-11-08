/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchoi <jchoi@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 12:29:46 by jchoi             #+#    #+#             */
/*   Updated: 2022/08/02 15:05:15 by jchoi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

t_data	*gnl_remain(t_gnl *gnl, int fd)
{
	t_data	*prev;
	t_data	*tmp;

	tmp = gnl->remains;
	while (tmp)
	{
		if (fd == tmp->fd)
			return (tmp);
		prev = tmp;
		tmp = tmp->next;
	}
	tmp = (t_data *)malloc(sizeof(t_data));
	if (tmp)
	{
		ft_memset(tmp->buf, 0, BUFFER_SIZE);
		tmp->fd = fd;
		tmp->flag = BUFFER_SIZE;
		tmp->next = NULL;
		(gnl->count)++;
	}
	if (gnl->count <= 1)
			gnl->remains = tmp;
	else
		prev->next = tmp;
	return (tmp);
}

void	gnl_cleanup(t_gnl *gnl, t_data *cur)
{
	t_data	*tmp;
	int		i;

	if (cur->flag < BUFFER_SIZE)
	{
		i = 0;
		while (cur->flag != ERROR && i < BUFFER_SIZE)
		{
			if ((cur->buf)[i])
				return ;
			i++;
		}
		tmp = gnl->remains;
		if (tmp == cur)
			gnl->remains = cur->next;
		else
		{
			while (tmp->next != cur)
				tmp = tmp->next;
			tmp->next = cur->next;
		}
		free(cur);
		(gnl->count)--;
	}
}

int	gnl_makeline(t_data *cur, char **line)
{
	size_t	idx;
	size_t	len;
	int		newline;

	if (cur->flag != ERROR)
	{
		len = BUFFER_SIZE;
		while (0 < len && cur->buf[len - 1] == '\0')
			len--;
		idx = 0;
		newline = FALSE;
		while (idx < len && cur->buf[idx] && newline == FALSE)
			newline = ((cur->buf)[idx++] == '\n');
		if (gnl_lengthen(line, cur->buf, idx + ft_strlen(*line)) == ERROR)
			return (cur->flag = ERROR);
		return (newline || cur->flag < BUFFER_SIZE);
	}
	else
	{
		if (*line)
			free(*line);
		*line = NULL;
		return (ERROR);
	}
}

char	*get_next_line(int fd)
{
	static t_gnl	gnl;
	char			*line;
	t_data			*cur;

	if (fd < 0 || OPEN_MAX < fd || BUFFER_SIZE <= 0)
		return (NULL);
	line = NULL;
	cur = gnl_remain(&gnl, fd);
	if (cur && !gnl_makeline(cur, &line))
	{
		while (!gnl_makeline(cur, &line) && cur->flag == BUFFER_SIZE)
		{
			ft_memset(cur->buf, 0, BUFFER_SIZE);
			cur->flag = read(fd, cur->buf, BUFFER_SIZE);
		}
	}
	gnl_cleanup(&gnl, cur);
	return (line);
}
