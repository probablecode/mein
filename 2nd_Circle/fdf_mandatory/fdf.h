/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchoi <jchoi@student.42Seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 15:48:28 by jchoi             #+#    #+#             */
/*   Updated: 2022/08/18 09:29:51 by jchoi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef FDF_H
# define FDF_H
# include "./include/libft.h"
# include "./include/ft_printf.h"
# include "./include/get_next_line.h"
# include "./include/mlx.h"
# define TRUE 1
# define FALSE 0
# define ERROR -1
# define WRONG_ARGC -2
# define FILE_EXTENTION -3
# define FOPEN_FAILURE -4 
# define INVALID_MAP -5
# define MALLOC_ERROR -6
# define W0 60 
# define H0 540
# define COLOR 0x00FFFFFF
# define ESC 53

typedef struct s_vars {
	void	*mlx;
	void	*win;
}	t_vars;

typedef struct s_image {
	void	*img;
	char	*addr;
	int		bpp;
	int		len;
	int		endian;
}	t_image;

typedef struct s_line
{
	int				*line;
	struct s_line	*next;
}	t_line;

typedef struct s_llist
{
	t_line	*lines;
	int		row;
	int		col;
}	t_llist;

void	fdf_open(t_llist *list, int argc, char *argv[]);
void	fdf_parse(t_llist *list, int fd);
void	fdf_newline(t_llist *list, int	*newline, char **split, int fd);
void	fdf_addline(t_llist *list, t_line *node);
int		**fdf_list_to_map(t_llist *list);

void	fdf_pixel(t_image *data, int x, int y, int color);
void	fdf_vertical(t_image *img, int **map, int i, int j);
void	fdf_horizontal(t_image *img, int **map, int i, int j);
void	fdf_projection_isometric(t_image *img, t_llist *list);

void	fdf_error(int errnum, void *tofree, int fd, int fopened);
void	fdf_llistclear(t_llist *list);
void	fdf_lineclear(t_line *node);
void	fdf_splitclear(char **split);
int		fdf_close(int keycode, t_vars *vars);
#endif
