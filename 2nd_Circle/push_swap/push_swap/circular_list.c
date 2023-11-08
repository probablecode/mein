/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   circular_list.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchoi <jchoi@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 13:52:04 by jchoi             #+#    #+#             */
/*   Updated: 2022/07/14 09:55:02 by jchoi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>

t_clnode	*newclnode(int value)
{
	t_clnode	*new;

	new = malloc(sizeof(t_clnode));
	if (new)
	{
		new->value = value;
		new->prev = NULL;
		new->next = NULL;
	}
	return (new);
}

t_circular_list	*newclist(void)
{
	t_circular_list	*new;

	new = malloc(sizeof(t_circular_list));
	if (new)
	{
		new->head = NULL;
		new->count = 0;
	}
	return (new);
}

void	print_node(t_clnode *tmp)
{
	if (tmp)
		ft_printf("[%d]\t", tmp->value);
}

void	print_list(t_circular_list *cl)
{
	t_clnode	*tmp;

	if (cl)
	{
		if (cl -> head)
		{
			tmp = cl->head;
			ft_printf("{Head} - ");
			print_node(tmp);
			tmp = tmp->next;
			while (tmp && tmp != cl->head)
			{
				print_node(tmp);
				tmp = tmp->next;
			}
			ft_printf("\n");
		}
		else
			ft_printf("there's no clnode in circular_list\n");
	}
	else
		ft_printf("error : there's no circluar_list\n");
}

void	deleteclist(t_circular_list *cl)
{
	t_clnode	*tmp;

	if (cl)
	{		
		tmp = pop(cl);
		while (tmp)
		{
			free(tmp);
			tmp = pop(cl);
		}
		free(cl);
	}
}
