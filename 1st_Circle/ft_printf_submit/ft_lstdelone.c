/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchoi <jchoi@student.42Seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 18:07:41 by jchoi             #+#    #+#             */
/*   Updated: 2022/01/06 18:07:43 by jchoi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (lst)
	{
		if (lst -> content)
			del(lst -> content);
		free (lst);
	}
}
