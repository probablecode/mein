/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchoi <jchoi@student.42Seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 13:16:08 by jchoi             #+#    #+#             */
/*   Updated: 2022/01/03 14:13:55 by jchoi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
int	ft_isalnum(int c)
{
	return (ft_isalpha(c) || ft_isdigit(c));
}
