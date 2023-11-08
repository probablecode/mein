/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   circular_list.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchoi <jchoi@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 00:44:17 by jchoi             #+#    #+#             */
/*   Updated: 2022/07/14 09:54:00 by jchoi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef CIRCULAR_LIST_H
# define CIRCULAR_LIST_H
# define TRUE 1
# define FALSE 0
# define ERROR -1

typedef struct s_clnode
{
	int				value;
	struct s_clnode	*prev;
	struct s_clnode	*next;
}	t_clnode;

typedef struct s_circular_list
{
	t_clnode	*head;
	int			count;
}	t_circular_list;

t_clnode		*newclnode(int value);
t_circular_list	*newclist(void);
t_clnode		*pop(t_circular_list *cl);
int				push(t_circular_list *cl, t_clnode *newnode);
void			print_node(t_clnode *tmp);
void			print_list(t_circular_list *cl);
int				swap(t_circular_list *cl);
int				rotate(t_circular_list *cl);
int				r_rotate(t_circular_list *cl);
void			deleteclist(t_circular_list *cl);
#endif
