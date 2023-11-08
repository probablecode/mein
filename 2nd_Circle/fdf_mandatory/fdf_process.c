/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_process.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchoi <jchoi@student.42Seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 20:00:34 by jchoi             #+#    #+#             */
/*   Updated: 2022/08/17 14:15:20 by jchoi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	fdf_projection_isometric(t_image *img, t_llist *list)
{
	int	**map;
	int	i;
	int	j;

	map = fdf_list_to_map(list);
	i = 0;
	while (i < list->row)
	{
		j = 0;
		while (j < list->col)
		{
			if (i + 1 < list->row)
				fdf_vertical(img, map, i, j);
			if (j + 1 < list->col)
				fdf_horizontal(img, map, i, j);
			j++;
		}
		free(map[i]);
		i++;
	}
	free(map);
}

void	fdf_vertical(t_image *img, int **map, int i, int j)
{
	int	x;
	int	y;
	int	dy;
	int	n;
	int	d;

	x = (i + j) * 7 * MAG;
	y = ((j - i) * 4 + map[i][j] * 8) * MAG;
	dy = ((-4) + (map[i + 1][j] - map[i][j]) * 8) * MAG;
	if (map[i][j] == map[i + 1][j])
		d = MAG * 7;
	else
		d = dy;
	n = 0;
	while (n != d)
	{
		fdf_pixel(img, W0 + x + MAG * 7 * n / d, H0 - (y + dy * n / d), COLOR);
		n += ((n < d) - (d < n));
	}
	fdf_pixel(img, W0 + x + MAG * 7, H0 - (y + dy), COLOR);
}

void	fdf_horizontal(t_image *img, int **map, int i, int j)
{
	int	x;
	int	y;
	int	dy;
	int	n;
	int	d;

	x = (i + j) * 7 * MAG;
	y = ((j - i) * 4 + map[i][j] * 8) * MAG;
	dy = (4 + (map[i][j + 1] - map[i][j]) * 8) * MAG;
	if (map[i][j] == map[i][j + 1])
		d = MAG * 7;
	else
		d = dy;
	n = 0;
	while (n != d)
	{
		fdf_pixel(img, W0 + x + MAG * 7 * n / d, H0 - (y + dy * n / d), COLOR);
		n += ((n < d) - (d < n));
	}
	fdf_pixel(img, W0 + x + MAG * 7, H0 - (y + dy), COLOR);
}

void	fdf_pixel(t_image *data, int x, int y, int color)
{
	char	*dst;

	if (0 < x && x < WIDTH && 0 < y && y < HEIGHT)
	{
		dst = data->addr + (y * data->len + x * (data->bpp / 8));
		*(unsigned int *)dst = color;
	}
}
