/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchoi <jchoi@student.42Seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 20:00:34 by jchoi             #+#    #+#             */
/*   Updated: 2023/01/24 21:54:12 by jchoi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	main(int argc, char *argv[])
{
	(void)argc;
	(void)argv;

	t_vars	vars;
	t_image	img;
	char	*dst;
//	t_llist	list;

//	fdf_open(&list, argc, argv);
	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, WIDTH, HEIGHT, "fdf");
	img.img = mlx_new_image(vars.mlx, WIDTH, HEIGHT);
	img.addr = mlx_get_data_addr(img.img, &img.bpp, &img.len, &img.endian);
//fdf_projection_isometric(&img, &list);

	for (int i = 0; i < HEIGHT; i++)
	{
		for (int j = 0; j < WIDTH; j++)
		{
			int	h = HEIGHT - i;
			dst = img.addr + (h * img.len + j * (img.bpp / 8));
			*(unsigned int *)dst = ((unsigned long long)(0x00FFFFFF) * (h * j) * 1000 / (WIDTH * HEIGHT));


		}
	}

	mlx_put_image_to_window(vars.mlx, vars.win, img.img, 0, 0);
	mlx_key_hook(vars.win, fdf_close, &vars);
	mlx_loop(vars.mlx);
	return (0);
}
