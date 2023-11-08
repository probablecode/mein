/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchoi <jchoi@student.42Seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 10:08:15 by jchoi             #+#    #+#             */
/*   Updated: 2022/01/07 10:08:18 by jchoi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*thislst;
	t_list	*nextlst;

	if (lst && del)
	{
		if (*lst)
		{
			thislst = (*lst)->next;
			ft_lstdelone(*lst, del);
			while (thislst)
			{
				nextlst = thislst -> next;
				ft_lstdelone(thislst, del);
				thislst = nextlst;
			}
		}
		*lst = NULL;
	}
}
