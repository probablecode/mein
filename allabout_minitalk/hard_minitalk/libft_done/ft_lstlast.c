/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchoi <jchoi@student.42Seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 14:07:51 by jchoi             #+#    #+#             */
/*   Updated: 2022/01/06 14:18:50 by jchoi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
t_list	*ft_lstlast(t_list *lst)
{
	t_list	*thislst;
	t_list	*nextlst;

	thislst = lst;
	if (thislst)
	{
		nextlst = thislst -> next;
		while (nextlst != NULL)
		{
			thislst = nextlst;
			nextlst = nextlst -> next;
		}
	}
	return (thislst);
}
