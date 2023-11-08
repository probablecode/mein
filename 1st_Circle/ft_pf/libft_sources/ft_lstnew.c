/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchoi <jchoi@student.42Seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 20:47:21 by jchoi             #+#    #+#             */
/*   Updated: 2022/01/05 20:50:47 by jchoi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
t_list	*ft_lstnew(void *content)
{
	t_list	*ret;

	ret = (t_list *)malloc (sizeof (t_list));
	if (ret)
	{
		ret -> content = content;
		ret -> next = NULL;
	}
	return (ret);
}
