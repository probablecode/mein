/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchoi <jchoi@student.42Seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 11:51:48 by jchoi             #+#    #+#             */
/*   Updated: 2022/07/17 17:00:39 by jchoi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	main(int argc, char *argv[])
{
	t_push_swap	*ps;
	int			*orders;
	int			count;

	orders = inputprocess(argc, argv, &count);
	if (orders && count)
	{
		ps = create_push_swap();
		if (!init_push_swap(ps, orders, count))
			return (ERROR);
		else if (!is_sorted(ps))
		{
			if (5 < count)
				sort_a(ps, count);
			else
				shortcase(ps, count);
			print_commands(ps);
		}
		delete_push_swap(ps);
	}
	else if (1 < argc)
		ft_putendl_fd("Error", 2);
	return (0);
}

int	is_sorted(t_push_swap *ps)
{
	t_clnode	*tmp;
	int			i;
	int			ret;

	tmp = (ps->a)->head;
	ret = ((ps->a)->count == ps->count && (ps->b)->count == 0);
	i = 1;
	while (ret == TRUE && i < (ps->a)->count)
	{
		ret = (tmp->value + 1 == (tmp->next)->value);
		tmp = tmp->next;
		i++;
	}
	return (ret);
}

static void	print_instruct(int cmd)
{
	if (cmd == SA)
		ft_putendl_fd("sa", 1);
	else if (cmd == SB)
		ft_putendl_fd("sb", 1);
	else if (cmd == SS)
		ft_putendl_fd("ss", 1);
	else if (cmd == PA)
		ft_putendl_fd("pa", 1);
	else if (cmd == PB)
		ft_putendl_fd("pb", 1);
	else if (cmd == RA)
		ft_putendl_fd("ra", 1);
	else if (cmd == RB)
		ft_putendl_fd("rb", 1);
	else if (cmd == RR)
		ft_putendl_fd("rr", 1);
	else if (cmd == RRA)
		ft_putendl_fd("rra", 1);
	else if (cmd == RRB)
		ft_putendl_fd("rrb", 1);
	else if (cmd == RRR)
		ft_putendl_fd("rrr", 1);
}

void	print_commands(t_push_swap *ps)
{
	t_clnode	*tmp;
	int			i;

	tmp = ((ps->commands)->head);
	if (tmp->prev)
		tmp = tmp->prev;
	i = 0;
	while (i < (ps->commands)->count)
	{
		if (tmp)
			print_instruct(tmp->value);
		tmp = tmp->prev;
		i++;
	}
}

void	print_push_swap(t_push_swap *ps)
{
	if (ps)
	{
		ft_printf("\n[Stack A]");
		print_list(ps->a);
		ft_printf("[Stack B]");
		print_list(ps->b);
	}
}
