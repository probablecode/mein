/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchoi <jchoi@student.42Seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 11:51:48 by jchoi             #+#    #+#             */
/*   Updated: 2022/07/16 16:04:51 by jchoi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	pivoting(t_clnode *start, int count, int pivots[])
{
	t_clnode	*node;
	int			min;
	int			i;

	min = start->value;
	node = start->next;
	i = 1;
	while (i++ < count)
	{
		if (node->value < min)
			min = node->value;
		node = node->next;
	}
	pivots[0] = min + count / 3;
	pivots[1] = pivots[0] + count / 3;
}

void	recover(t_push_swap	*ps, int ra, int rb)
{
	while (0 < ra || 0 < rb)
	{
		if (0 < ra)
		{
			instruct_push_swap(ps, RRA);
			ra--;
		}
		if (0 < rb)
		{
			instruct_push_swap(ps, RRB);
			rb--;
		}
	}
}

void	sort_a(t_push_swap *ps, int count)
{
	int	val;
	int	pivots[2];
	int	pb_rb_ra[3];

	if (count < 4)
		hardsort(ps, hardcode_a((ps->a)->head, count));
	else
	{
		ft_memset(pb_rb_ra, 0, 3 * sizeof(int));
		pivoting((ps->a)->head, count, pivots);
		while (pb_rb_ra[0] + pb_rb_ra[2] < count)
		{
			val = ((ps->a)->head)->value;
			if (val < pivots[1])
				pb_rb_ra[0] += instruct_push_swap(ps, PB);
			if (pivots[0] <= val && val < pivots[1])
				pb_rb_ra[1] += instruct_push_swap(ps, RB);
			if (pivots[1] <= val)
				pb_rb_ra[2] += instruct_push_swap(ps, RA);
		}
		recover(ps, pb_rb_ra[2], pb_rb_ra[1]);
		sort_a(ps, pb_rb_ra[2]);
		sort_b(ps, pb_rb_ra[1]);
		sort_b(ps, pb_rb_ra[0] - pb_rb_ra[1]);
	}
}

void	sort_b(t_push_swap *ps, int count)
{
	int	val;
	int	pivots[2];
	int	pa_ra_rb[3];

	if (count < 4)
		hardsort(ps, hardcode_b((ps->b)->head, count));
	else
	{
		ft_memset(pa_ra_rb, 0, 3 * sizeof(int));
		pivoting((ps->b)->head, count, pivots);
		while (pa_ra_rb[0] + pa_ra_rb[2] < count)
		{
			val = ((ps->b)->head)->value;
			if (pivots[0] <= val)
				pa_ra_rb[0] += instruct_push_swap(ps, PA);
			if (pivots[0] <= val && val < pivots[1])
				pa_ra_rb[1] += instruct_push_swap(ps, RA);
			if (val < pivots[0])
				pa_ra_rb[2] += instruct_push_swap(ps, RB);
		}
		sort_a(ps, pa_ra_rb[0] - pa_ra_rb[1]);
		recover(ps, pa_ra_rb[1], pa_ra_rb[2]);
		sort_a(ps, pa_ra_rb[1]);
		sort_b(ps, pa_ra_rb[2]);
	}
}

void	shortcase(t_push_swap *ps, int count)
{
	t_circular_list	*s;

	s = (ps->a);
	if (count == 4)
		instruct_push_swap(ps, (((s->head)->prev)->value == 1) * RRA);
	while (count == 4 && (s->head)->value != 1)
		instruct_push_swap(ps, RA);
	while (count == 5 && (s->head)->value != 1 && (s->head)->value != 2)
		instruct_push_swap(ps, RA);
	instruct_push_swap(ps, (4 <= count) * PB);
	while (count == 5 && (s->head)->value != 1 && (s->head)->value != 2)
		instruct_push_swap(ps, RA);
	instruct_push_swap(ps, (count == 5) * PB);
	instruct_push_swap(ps, (count == 5 && (((ps->b)->head)->value) == 1) * SB);
	leq3(ps, count);
	instruct_push_swap(ps, (4 <= count) * PA);
	instruct_push_swap(ps, (count == 5) * PA);
}
