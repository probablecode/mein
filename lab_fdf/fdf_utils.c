/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchoi <jchoi@student.42Seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 15:54:13 by jchoi             #+#    #+#             */
/*   Updated: 2022/08/18 09:29:09 by jchoi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	fdf_error(int errnum, void *tofree, int fd, int fopened)
{
	if (errnum == WRONG_ARGC)
		ft_printf("[Invalid Input] : Only one filename is required\n");
	else if (errnum == FILE_EXTENTION)
		ft_printf("[Invalid Input] : file extention must be .fdf\n");
	else if (errnum == FOPEN_FAILURE)
		ft_printf("[File Open is failed]\n");
	else if (errnum == MALLOC_ERROR)
	{
		if (tofree)
			free(tofree);
		ft_printf("[Malloc Error Occurs]\n");
	}
	else if (errnum == INVALID_MAP)
	{
		fdf_splitclear((char **)tofree);
		ft_printf("[Invalid Input] : Map data is not properly formatted\n");
	}
	if (fopened == TRUE)
		close(fd);
	exit(1);
}

void	fdf_llistclear(t_llist *list)
{
	t_line	*node;
	t_line	*tmp;

	node = list->lines;
	while (node)
	{
		tmp = node->next;
		free(node);
		node = tmp;
	}
}

void	fdf_lineclear(t_line *node)
{
	while (node)
	{
		if (node->line)
			free(node->line);
		node = node->next;
	}
}

void	fdf_splitclear(char **split)
{
	int	len;

	len = 0;
	while (split[len])
	{
		free(split[len]);
		len++;
	}
	free(split);
}

int	fdf_close(int keycode, t_vars *vars)
{
	if (keycode == ESC)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		exit(0);
	}
	return (0);
}
