/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchoi <jchoi@student.42Seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 14:01:42 by jchoi             #+#    #+#             */
/*   Updated: 2022/01/06 14:06:30 by jchoi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
int	ft_lstsize(t_list *lst)
{
	t_list	*nextlst;
	int		size;

	size = 0;
	if (lst)
	{
		size++;
		nextlst = lst -> next;
		while (nextlst != NULL)
		{
			size++;
			nextlst = nextlst -> next;
		}
	}
	return (size);
}
