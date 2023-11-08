/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchoi <jchoi@student.42Seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 10:08:05 by jchoi             #+#    #+#             */
/*   Updated: 2022/01/07 10:08:07 by jchoi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	t_list	*thislst;

	if (lst && f)
	{
		thislst = lst;
		while (thislst)
		{
			f(thislst -> content);
			thislst = thislst -> next;
		}
	}
}
