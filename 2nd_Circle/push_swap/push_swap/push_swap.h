/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchoi <jchoi@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 14:37:20 by jchoi             #+#    #+#             */
/*   Updated: 2022/07/17 08:40:39 by jchoi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "./libft/libft.h"
# include "./libft/ft_printf.h"
# include "./libft/get_next_line.h"
# include "circular_list.h"
# define SA 1
# define SB 2
# define SS 3
# define PA 4
# define PB 5
# define RA 6
# define RB 7
# define RR 8
# define RRA 9
# define RRB 10
# define RRR 11

typedef struct s_push_swap
{
	t_circular_list	*a;
	t_circular_list	*b;
	t_circular_list	*commands;
	int				count;
}	t_push_swap;

t_push_swap	*create_push_swap(void);
int			init_push_swap(t_push_swap *ps, int *orders, int count);
int			instruct_push_swap(t_push_swap *ps, int cmd);
void		enqueue_cmd(t_push_swap *ps, int cmd);
void		delete_push_swap(t_push_swap *ps);

char		***make_split(int argc, char *argv[], int *count);
int			*split_to_intarray(char **split[], int splits, int count);
void		*split_delete(char **split[], int count);
int			indexing(int *arr, int *orders[], int count);
int			*inputprocess(int argc, char *argv[], int *count);

int			is_sorted(t_push_swap *ps);
void		print_push_swap(t_push_swap *ps);
void		print_commands(t_push_swap *ps);

void		recover(t_push_swap	*ps, int ra, int rb);
void		pivoting(t_clnode *start, int count, int pivots[]);
void		sort_a(t_push_swap *ps, int count);
void		sort_b(t_push_swap *ps, int count);
void		shortcase(t_push_swap *ps, int count);

int			hardcode_a(t_clnode *head, int count);
int			hardcode_b(t_clnode *head, int count);
void		hardsort(t_push_swap *ps, int code);
void		leq3(t_push_swap *ps, int count);
#endif
