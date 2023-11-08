/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchoi <jchoi@student.42Seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 11:15:18 by jchoi             #+#    #+#             */
/*   Updated: 2022/01/16 13:25:32 by jchoi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*oldlst;
	t_list	*newlst;
	t_list	*tmplst;

	newlst = NULL;
	if (lst && f)
	{
		oldlst = lst;
		while (oldlst)
		{
			tmplst = ft_lstnew(f(oldlst -> content));
			if (!tmplst)
			{
				ft_lstclear(&newlst, del);
				return (NULL);
			}
			ft_lstadd_back(&newlst, tmplst);
			oldlst = oldlst -> next;
		}
	}
	return (newlst);
}
