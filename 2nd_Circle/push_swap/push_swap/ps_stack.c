/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_stack.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchoi <jchoi@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 19:02:42 by jchoi             #+#    #+#             */
/*   Updated: 2022/07/16 19:51:45 by jchoi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>

t_push_swap	*create_push_swap(void)
{
	t_push_swap	*ps;

	ps = (t_push_swap *)malloc(sizeof(t_push_swap));
	if (ps)
	{
		ps->count = 0;
		ps->a = newclist();
		ps->b = newclist();
		ps->commands = newclist();
		if (!(ps->a) || !(ps->b) || !(ps->commands))
		{
			deleteclist(ps->a);
			deleteclist(ps->b);
			deleteclist(ps->commands);
			free(ps);
			ps = NULL;
		}
	}
	return (ps);
}

int	init_push_swap(t_push_swap *ps, int *orders, int count)
{
	int			i;
	int			ret;
	t_clnode	*newnode;

	ret = FALSE;
	if (ps && ps->a && orders && 0 < count)
	{
		i = 0;
		while (i < count)
		{
			newnode = newclnode(orders[i]);
			if (!newnode || !push(ps->a, newnode))
			{
				delete_push_swap(ps);
				return (FALSE);
			}
			i++;
		}
		ps -> count = count;
		if (orders)
			free(orders);
		ret = TRUE;
	}
	return (ret);
}

void	enqueue_cmd(t_push_swap *ps, int cmd)
{
	t_clnode	*tmp;
	int			hval;

	if ((ps->commands)->head)
	{
		hval = ((ps->commands)->head)->value;
		if ((cmd == SA && hval == SB) || (cmd == SB && hval == SA))
			cmd = SS;
		else if ((cmd == RA && hval == RB) || (cmd == RB && hval == RA))
			cmd = RR;
		else if ((cmd == RRA && hval == RRB) || (cmd == RRB && hval == RRA))
			cmd = RRR;
	}
	if (cmd == SS || cmd == RR || cmd == RRR)
	{
		tmp = pop(ps->commands);
		if (tmp)
			free(tmp);
	}
	push(ps->commands, newclnode(cmd));
}

int	instruct_push_swap(t_push_swap *ps, int cmd)
{
	enqueue_cmd(ps, cmd);
	if (cmd == SA)
		return (swap(ps->a));
	else if (cmd == SB)
		return (swap(ps->b));
	else if (cmd == SS)
		return (swap(ps->a) && swap(ps->b));
	else if (cmd == PA)
		return (push(ps->a, pop(ps->b)));
	else if (cmd == PB)
		return (push(ps->b, pop(ps->a)));
	else if (cmd == RA)
		return (rotate(ps->a));
	else if (cmd == RB)
		return (rotate(ps->b));
	else if (cmd == RR)
		return (rotate(ps->a) && rotate(ps->b));
	else if (cmd == RRA)
		return (r_rotate(ps->a));
	else if (cmd == RRB)
		return (r_rotate(ps->b));
	else if (cmd == RRR)
		return (r_rotate(ps->a) && r_rotate(ps->b));
	return (FALSE);
}

void	delete_push_swap(t_push_swap *ps)
{
	if (ps)
	{
		deleteclist(ps->a);
		deleteclist(ps->b);
		deleteclist(ps->commands);
		free(ps);
	}
}
