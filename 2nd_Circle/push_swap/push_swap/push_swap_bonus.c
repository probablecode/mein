/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchoi <jchoi@student.42Seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 11:51:48 by jchoi             #+#    #+#             */
/*   Updated: 2022/07/17 17:02:17 by jchoi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	main(int argc, char *argv[])
{
	t_push_swap	*ps;
	int			*orders;
	int			count;
	char		*cmd;

	orders = inputprocess(argc, argv, &count);
	if (orders && count)
	{
		ps = create_push_swap();
		if (!init_push_swap(ps, orders, count))
			return (-1);
		cmd = get_next_line(0);
		while (cmd != 0)
		{
			if (!instruct_push_swap(ps, read_instruct((const char *)cmd)))
				break ;
			free(cmd);
			cmd = get_next_line(0);
		}
		ps_checker(ps, cmd);
		delete_push_swap(ps);
	}
	else if (1 < argc)
		ft_putendl_fd("Error", 2);
	return (0);
}

void	ps_checker(t_push_swap *ps, char *cmd)
{
	if (cmd)
	{
		free(cmd);
		ft_putendl_fd("Error", 2);
	}
	else if (is_sorted(ps))
		ft_putendl_fd("OK", 1);
	else
		ft_putendl_fd("KO", 1);
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

int	read_instruct(const char *cmd)
{
	int	ret;

	ret = 0;
	if (ft_strlen(cmd) == 3)
	{
		ret += (ft_strncmp("sa\n", cmd, 3) == 0) * SA;
		ret += (ft_strncmp("sb\n", cmd, 3) == 0) * SB;
		ret += (ft_strncmp("ss\n", cmd, 3) == 0) * SS;
		ret += (ft_strncmp("pa\n", cmd, 3) == 0) * PA;
		ret += (ft_strncmp("pb\n", cmd, 3) == 0) * PB;
		ret += (ft_strncmp("ra\n", cmd, 3) == 0) * RA;
		ret += (ft_strncmp("rb\n", cmd, 3) == 0) * RB;
		ret += (ft_strncmp("rr\n", cmd, 3) == 0) * RR;
	}
	else if (ft_strlen(cmd) == 4)
	{
		ret += (ft_strncmp("rra\n", cmd, 4) == 0) * RRA;
		ret += (ft_strncmp("rrb\n", cmd, 4) == 0) * RRB;
		ret += (ft_strncmp("rrr\n", cmd, 4) == 0) * RRR;
	}
	return (ret);
}
