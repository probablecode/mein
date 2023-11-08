/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchoi <jchoi@student.42Seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 11:39:26 by jchoi             #+#    #+#             */
/*   Updated: 2022/01/04 12:00:39 by jchoi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
void	*ft_calloc(size_t count, size_t size)
{	
	void	*ret;

	ret = malloc (count * size);
	if (ret)
		ft_bzero(ret, count * size);
	return (ret);
}
