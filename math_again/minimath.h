/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimath.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchoi <jchoi@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 21:45:59 by jchoi             #+#    #+#             */
/*   Updated: 2023/01/29 22:47:47 by jchoi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIMATH_H
# define MINIMATH_H
# include "struct_vec.h"
# include <stdio.h>
# include <math.h>

# define ZERO 0
# define IDENTITY 1
# define STD_X 1
# define STD_Y 2
# define STD_Z 3

//	matrix.c
t_mtx3	init_mtx3(t_vec3 v0, t_vec3 v1, t_vec3 v2);
t_mtx3	regular_mtx3(int type);
void	print_mtx3(t_mtx3 m);

//	matrix_unary_operation.c
t_mtx3	times_mtx3(t_mtx3 m, double scalar);
t_mtx3	transpose_mtx3(t_mtx3 m);
double	det_mtx3(t_mtx3 m);
t_mtx3	inverse_mtx3(t_mtx3 m);	

//	matrix_binary_operation.c
t_mtx3	add_mtx3(t_mtx3 m1, t_mtx3 m2);
t_mtx3	add_inverse_mtx3(t_mtx3 m);
t_mtx3	sub_mtx3(t_mtx3 m1, t_mtx3 m2);
t_mtx3	mul_mtx3(t_mtx3 m1, t_mtx3 m2);
t_mtx3	pow_mtx3(t_mtx3 m, int times);

//	vector.c
t_vec3	init_vec3(double x, double y, double z);
t_vec3	regular_vec3(int type);
void	print_vec3(t_vec3 v);

//	vector_unary_operation.c
t_vec3	times_vec3(t_vec3 v, double scalar);
t_vec3	inverse_vec3(t_vec3 v);
double	sqrsum_vec3(t_vec3 v);
double	length_vec3(t_vec3 v);
t_vec3	normalize_vec3(t_vec3 v);

//	vector_binary_operation.c
t_vec3	add_vec3(t_vec3 v, t_vec3 v2);
t_vec3	sub_vec3(t_vec3 v, t_vec3 v2);
double	dot_product(t_vec3 v1, t_vec3 v2);
t_vec3	cross_product(t_vec3 v1, t_vec3 v2);

//	vector_projection.c
t_vec3	tangent_vec3(t_vec3 src, t_vec3 dir);
t_vec3	normal_vec3(t_vec3 src, t_vec3 dir);


////////////////////////////// 다른 수학적 개념들을 더 생각해 봅시다.

typedef	t_vec3	t_dot3;

typedef struct s_3d_line
{
	t_dot	origin;
	t_vec3	direct;
}	t_line3;
	

typedef struct s_3d_plane
{
	t_dot	origin;
	t_vec3	normal;
	double	term;
}	t_plane3;

double	dist_dot_dot(t_dot3 a, t_dot3 b)
{
	return (length_vec3(sub_vec3(a, b)));
}

double	dist_dot_line(t_dot3 a, t_line3 l)
{
	return (length_vec3(sub_vec3(a, b)));
}

double	dist_dot_plane(t_dot3 a, t_plane3 p)
{
	return (length_vec3(tangent_vec3(sub_vec3(p.origin, a), p.normal)));
}

double	tocos_vec3(t_vec3 u, t_vec3 v)
{
	return (dot_product(u, v) / (length_vec3(u) * length_vec3(v)));
}

int	isparallel_vec3(t_vec3 u, t_vec3 v)
{
	return (fabs(tocos_vec3(u,v)) == 1.0);
}

int	isperpendic_vec3(t_vec3 u, t_vec3 v)
{
	return (tocos_vec3(u,v) == 0.0);
}

double	dist_line_line()
{

}

t_line3	sol_line(t_plane3 p1, t_plane3 p2)
{

}


//	점과 점사이 거리
//	점과 직선사이 거리, 교점
//	점과 평면사이 거리

//	직선과 직선사이 거리, 교점
//	직선과 평면사이 거리, 교점

//	평면과 평면 사이 거리, 교선

//	rad <-> deg	함수
#endif
