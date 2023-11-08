/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchoi <jchoi@student.42Seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 16:30:26 by jchoi             #+#    #+#             */
/*   Updated: 2022/06/26 22:32:49 by jchoi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*thislst;

	if (lst)
	{
		if (*lst)
		{
			thislst = *lst;
			while (thislst -> next)
				thislst = thislst -> next;
			thislst -> next = new;
		}
		else
			*lst = new;
	}
}
