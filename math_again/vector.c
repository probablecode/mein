/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchoi <jchoi@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 21:46:50 by jchoi             #+#    #+#             */
/*   Updated: 2023/01/29 21:46:55 by jchoi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minimath.h"

t_vec3	init_vec3(double x, double y, double z)
{
	t_vec3	v;

	v.e[x_] = x;
	v.e[y_] = y;
	v.e[z_] = z;
	return (v);
}

t_vec3	regular_vec3(int type)
{
	if (type < ZERO || STD_Z < type)
		printf("invalid type\n");
	return (init_vec3(type == STD_X, type == STD_Y, type == STD_Z));
}

void	print_vec3(t_vec3 v)
{
	printf("x : %f\t", v.e[x_]);
	printf("y : %f\t", v.e[y_]);
	printf("z : %f\t", v.e[z_]);
	printf("\n");
}
