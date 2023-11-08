/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchoi <jchoi@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 12:20:48 by jchoi             #+#    #+#             */
/*   Updated: 2022/08/02 15:08:30 by jchoi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H
# include <limits.h>
# include <unistd.h>
# include <stdlib.h>
# define TRUE 1
# define FALSE 0
# define ERROR -1

typedef struct s_data
{
	char			buf[BUFFER_SIZE];
	int				fd;
	int				flag;
	struct s_data	*next;
}	t_data;
typedef struct s_gnl
{
	t_data	*remains;
	int		count;
}	t_gnl;

char	*get_next_line(int fd);
t_data	*gnl_remain(t_gnl *gnl, int fd);
void	gnl_cleanup(t_gnl *gnl, t_data *cur);
int		gnl_makeline(t_data *cur, char **line);

void	*ft_calloc(size_t count, size_t size);
void	*ft_memset(void *b, int c, size_t len);
void	*ft_memcpy(void *dst, const void *src, size_t n);
size_t	ft_strlen(const char *s);
int		gnl_lengthen(char **line, char buf[], size_t len);

#endif
