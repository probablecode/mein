/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   circular_stack_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchoi <jchoi@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 00:44:17 by jchoi             #+#    #+#             */
/*   Updated: 2022/07/16 22:21:28 by jchoi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>

int	push(t_circular_list *cl, t_clnode *new)
{
	int			ret;
	t_clnode	*tmp;

	ret = FALSE;
	if (cl && new)
	{
		if (cl->head)
		{
			tmp = (cl->head)->prev;
			if (!tmp)
				tmp = (cl->head);
			tmp->next = new;
			new->prev = tmp;
			tmp = cl->head;
			new->next = tmp;
			tmp->prev = new;
		}
		cl->head = new;
		(cl->count)++;
		ret = TRUE;
	}
	return (ret);
}

int	swap(t_circular_list *cl)
{
	t_clnode	*a;
	t_clnode	*b;
	t_clnode	*tmp;
	int			ret;

	ret = FALSE;
	if (cl && 1 < cl->count)
	{
		a = cl->head;
		b = a->next;
		tmp = a->prev;
		tmp->next = b;
		b->prev = tmp;
		tmp = b->next;
		tmp->prev = a;
		a->next = tmp;
		a->prev = b;
		b->next = a;
		cl->head = b;
		ret = TRUE;
	}
	return (ret);
}

t_clnode	*pop(t_circular_list *cl)
{
	t_clnode	*popup;

	popup = NULL;
	if (cl && 0 < cl->count)
	{
		popup = cl->head;
		cl->head = popup->next;
		if (cl->head)
		{
			if (popup->prev == popup->next)
			{
				(cl->head)->prev = NULL;
				(cl->head)->next = NULL;
			}
			else
			{
				(cl->head)->prev = popup->prev;
				(popup->prev)->next = cl->head;
			}
			popup->next = NULL;
			popup->prev = NULL;
		}
		(cl->count)--;
	}
	return (popup);
}

int	rotate(t_circular_list *cl)
{
	if (cl)
	{
		if (1 < cl->count)
			cl->head = (cl->head)->next;
		return (TRUE);
	}
	return (FALSE);
}

int	r_rotate(t_circular_list *cl)
{
	if (cl)
	{
		if (1 < cl->count)
			cl->head = (cl->head)->prev;
		return (TRUE);
	}
	return (FALSE);
}
