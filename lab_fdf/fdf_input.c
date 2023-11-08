/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_input.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchoi <jchoi@student.42Seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 20:00:34 by jchoi             #+#    #+#             */
/*   Updated: 2022/08/18 09:28:35 by jchoi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>

void	fdf_open(t_llist *list, int argc, char *argv[])
{
	int		len;
	int		fd;

	if (argc == 2)
	{
		len = ft_strlen(argv[1]);
		if (4 < len && !ft_strncmp(".fdf", argv[1] + len - 4, 4))
		{
			fd = open(argv[1], O_RDONLY);
			if (fd == ERROR)
				fdf_error(FOPEN_FAILURE, NULL, 0, FALSE);
			else
				return (fdf_parse(list, fd));
		}
		else
			fdf_error(FILE_EXTENTION, NULL, 0, FALSE);
	}
	else
		fdf_error(WRONG_ARGC, NULL, 0, FALSE);
}

void	fdf_parse(t_llist *list, int fd)
{
	int		len;
	char	*str;
	char	**split;
	int		*newline;

	ft_memset(list, 0, sizeof(t_llist));
	str = get_next_line(fd);
	while (str)
	{
		len = 0;
		split = ft_split(str, ' ');
		free(str);
		if (!split)
			fdf_error(MALLOC_ERROR, NULL, fd, TRUE);
		while (split[len] && ft_strncmp(split[len], "\n", 1))
			len++;
		if (list->col && list->col != len)
			fdf_error(INVALID_MAP, split, fd, TRUE);
		list->col = len;
		newline = ft_calloc(len, sizeof(int));
		fdf_newline(list, newline, split, fd);
		str = get_next_line(fd);
	}
	close(fd);
}

void	fdf_newline(t_llist *list, int *newline, char **split, int fd)
{
	t_line	*node;
	int		i;

	if (newline)
	{
		i = 0;
		while (i < list->col)
		{
			newline[i] = ft_atoi(split[i]);
			i++;
		}
		i = 0;
		fdf_splitclear(split);
		node = (t_line *)malloc(sizeof(t_line));
		if (!node)
			fdf_error(MALLOC_ERROR, newline, fd, TRUE);
		node->line = newline;
		node->next = NULL;
		fdf_addline(list, node);
	}
	else
	{
		fdf_splitclear(split);
		fdf_error(MALLOC_ERROR, NULL, fd, TRUE);
	}
}

void	fdf_addline(t_llist *list, t_line *node)
{
	t_line	*tmp;

	tmp = list->lines;
	if (!tmp)
		list->lines = node;
	else
	{
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = node;
	}
	list->row++;
}

int	**fdf_list_to_map(t_llist *list)
{
	t_line	*cur;
	int		**map;
	int		i;

	cur = list->lines;
	map = (int **)ft_calloc(list->row, sizeof(int *));
	if (map)
	{
		i = 0;
		while (i < list->row)
		{
			map[i++] = cur->line;
			cur = cur->next;
		}
	}
	else
	{
		fdf_lineclear(list->lines);
		fdf_llistclear(list);
		fdf_error(MALLOC_ERROR, NULL, 0, FALSE);
	}	
	fdf_llistclear(list);
	return (map);
}
