/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchoi <jchoi@student.42Seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 14:40:43 by jchoi             #+#    #+#             */
/*   Updated: 2022/01/07 14:55:18 by jchoi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
char	*ft_substr(char const *str, unsigned int start, size_t len)
{
	size_t	slen;
	char	*substr;

	if (str == NULL)
		return (NULL);
	slen = ft_strlen(str);
	if (slen <= (size_t)start)
		len = 0;
	else if (len > slen - (size_t)start)
		len = slen -(size_t)start;
	substr = (char *)malloc((len + 1) * sizeof(char));
	if (substr != NULL)
		ft_strlcpy(substr, str + start, len + 1);
	return (substr);
}
