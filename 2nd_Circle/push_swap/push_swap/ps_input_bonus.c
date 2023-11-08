/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_input_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchoi <jchoi@student.42Seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 11:51:48 by jchoi             #+#    #+#             */
/*   Updated: 2022/07/17 16:55:13 by jchoi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>

int	indexing(int *arr, int *orders[], int count)
{
	int	i;
	int	j;
	int	result;

	result = ERROR;
	if (*orders && arr)
	{
		i = 0;
		while (i < count)
		{
			(*orders)[i] = 1;
			j = 0;
			while (j < count)
			{
				if (i != j && arr[i] == arr[j])
					return (ERROR);
				(*orders)[i] += (arr[j++] < arr[i]);
			}
			i++;
		}
		result = TRUE;
	}
	return (result);
}

void	*split_delete(char **split[], int count)
{
	int	i;
	int	j;

	i = 0;
	if (split)
	{
		while (i < count)
		{
			j = 0;
			while (split[i][j])
			{
				free(split[i][j]);
				j++;
			}
			free(split[i]);
			i++;
		}
		free(split);
	}
	return (NULL);
}

int	*inputprocess(int argc, char *argv[], int *count)
{
	char	***split;
	int		*values;
	int		*orders;

	values = NULL;
	*count = 0;
	split = make_split(argc - 1, argv + 1, count);
	if (split)
		values = split_to_intarray(split, argc - 1, *count);
	orders = ft_calloc(*count, sizeof(int));
	if (indexing(values, &orders, *count) == ERROR)
	{
		free(orders);
		orders = NULL;
		*count = ERROR;
	}
	if (values)
		free(values);
	split_delete(split, argc - 1);
	return (orders);
}

char	***make_split(int argc, char *argv[], int *count)
{
	char	***split;
	int		i;
	int		j;

	split = (char ***)ft_calloc(argc, sizeof(char **));
	if (split)
	{
		i = 0;
		while (i < argc)
		{
			split[i] = ft_split(argv[argc - 1 - i], ' ');
			if (!split[i] || (split[i] && !split[i][0]))
				return (split_delete(split, i + (split[i] != NULL)));
			i++;
		}
		i = 0;
		while (i < argc)
		{
			j = 0;
			while (split[i][j++])
				(*count)++;
			i++;
		}
	}
	return (split);
}

int	*split_to_intarray(char **split[], int splits, int count)
{
	int		*values;
	int		i[3];
	long	check;

	ft_memset(i, 0, 3 * sizeof(int));
	values = (int *)ft_calloc(count, sizeof(int));
	while (values && i[0] < count && i[1] < splits)
	{
		i[2] = 0;
		while (split[i[1]][i[2]])
			i[2]++;
		while (0 < i[2]--)
		{
			check = ft_strtol(split[i[1]][i[2]]);
			if (check < -2147483648 || 2147483647 < check)
			{
				free(values);
				return (NULL);
			}
			values[i[0]++] = ft_atoi(split[i[1]][i[2]]);
		}
		i[1]++;
	}
	return (values);
}
