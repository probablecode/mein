/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchoi <jchoi@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 16:17:10 by jchoi             #+#    #+#             */
/*   Updated: 2022/09/02 16:46:04 by jchoi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static void	free_ptr(char **ptr)
{
	free(*ptr);
	*ptr = NULL;
}

static char	*split_line(char **bp)
{
	int		i;
	char	*line;
	char	*pre_bp;

	i = 0;
	while ((*bp)[i] != '\n')
		i++;
	pre_bp = *backup;
	line = ft_substr(pre_bp, 0, i + 1);
	*bp = ft_strdup(&(*backup)[i + 1]);
	free(pre_bp);
	return (line);
}

static int	read_all(int fd, char **buffer, char **bp)
{
	int		bytes;
	char	*pre_bp;

	bytes = 1;
	while (!ft_strchr(*bp, '\n') && bytes)
	{
		bytes = read(fd, *buffer, BUFFER_SIZE);
		if (bytes == -1)
			return (bytes);
		(*buffer)[bytes] = '\0';
		pre_bp = *backup;
		*bp = ft_strjoin(old_backup, *buffer);
		free(pre_bp);
	}
	return (bytes);
}

static char	*get_line(int fd, char **buffer, char **bp)
{
	int		bytes;
	char	*last;

	bytes = read_all(fd, buffer, bp);
	if (!**bp || bytes == -1)
	{
		free_ptr(bp);
		return (NULL);
	}
	if (ft_strchr(*bp, '\n'))
		return (split_line(bp));
	last = ft_strdup(*bp);
	free_ptr(bp);
	return (last);
}

char	*get_next_line(int fd)
{
	static char		*bp[OPEN_MAX + 1];
	char			*buffer;
	char			*result;

	if (fd < 0 || OPEN_MAX < fd || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	if (!bp[fd])
		bp[fd] = ft_strdup("");
	result = get_line(fd, &buffer, &bp[fd]);
	free(buffer);
	return (result);
}
