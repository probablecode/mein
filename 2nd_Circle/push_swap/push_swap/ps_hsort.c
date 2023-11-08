/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_hsort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchoi <jchoi@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 02:28:59 by jchoi             #+#    #+#             */
/*   Updated: 2022/07/16 16:42:31 by jchoi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	hardcode_a(t_clnode *head, int count)
{
	int	dt[2];
	int	code;

	code = 0;
	if (1 < count)
		dt[0] = (head->next)->value - head->value;
	if (2 < count)
		dt[1] = ((head->next)->next)->value - (head->next)->value;
	if (count == 3 && dt[0] == -2 && dt[1] == 1)
		code = RRA << 12 | SA << 8 | RA << 4 | SA;
	else if (dt[0] == -1 && (dt[1] == 2 || count == 2))
		code = SA;
	else if (count == 3 && dt[0] == -1 && dt[1] == -1)
		code = SA << 16 | RRA << 12 | SA << 8 | RA << 4 | SA;
	else if (count == 3 && dt[0] == 1 && dt[1] == -2)
		code = SA << 12 | RRA << 8 | SA << 4 | RA;
	else if (count == 3 && dt[0] == 2 && dt[1] == -1)
		code = RRA << 8 | SA << 4 | RA;
	return (code);
}

int	hardcode_b(t_clnode *head, int count)
{
	int	dt[2];
	int	code;

	code = PA;
	if (1 < count)
		dt[0] = (head->next)->value - head->value;
	if (2 < count)
		dt[1] = ((head->next)->next)->value - (head->next)->value;
	if (count == 2 && dt[0] == -1)
		code = PA << 4 | PA;
	else if (count == 2 && dt[0] == 1)
		code = PA << 8 | PA << 4 | SB;
	else if (count == 3 && dt[0] == 1 && dt[1] == 1)
		code = SA << 20 | PA << 16 | SA << 12 | PA << 8 | SB << 4 | PA;
	else if (count == 3 && dt[0] == 2 && dt[1] == -1)
		code = PA << 16 | PA << 12 | SB << 8 | PA << 4 | SB;
	else if (count == 3 && dt[0] == -1 && dt[1] == 2)
		code = PA << 16 | SA << 12 | PA << 8 | SB << 4 | PA;
	else if (count == 3 && dt[0] == 1 && dt[1] == -2)
		code = PA << 12 | PA << 8 | PA << 4 | SB;
	else if (count == 3 && dt[0] == -1 && dt[1] == -1)
		code = PA << 8 | PA << 4 | PA;
	else if (count == 3 && dt[0] == -2 && dt[1] == 1)
		code = PA << 12 | PA << 8 | SB << 4 | PA;
	return (code);
}

void	hardsort(t_push_swap *ps, int code)
{
	while (code)
	{
		instruct_push_swap(ps, code & 15);
		code = code >> 4;
	}
}

void	leq3(t_push_swap *ps, int count)
{
	t_clnode	*h;
	int			dt[2];

	h = (ps->a)->head;
	if (1 < count)
		dt[0] = (h->next)->value - h->value;
	if (2 < count)
		dt[1] = ((h->next)->next)->value - (h->next)->value;
	if (1 < count && dt[0] == -1)
		instruct_push_swap(ps, SA);
	if (2 < count && (dt[1] == -1 || dt[1] == -2))
		instruct_push_swap(ps, RRA);
	if (1 < count && dt[0] == 2)
		instruct_push_swap(ps, SA);
	if (1 < count && dt[0] == -2)
		instruct_push_swap(ps, RA);
}
