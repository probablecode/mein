/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_term.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchoi <jchoi@student.42Seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 17:43:26 by jchoi             #+#    #+#             */
/*   Updated: 2022/09/06 15:28:46 by jchoi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ph_term_error(t_monitor *mon, t_philo *phs, t_data *data)
{
	int	i;

	if (data->forks)
	{
		i = 0;
		while (i < data->num)
			pthread_mutex_destroy(data->forks + i++);
		free(data->forks);
	}
	pthread_mutex_destroy(&(mon->eat));
	pthread_mutex_destroy(&(mon->end));
	if (phs)
	{
		i = 0;
		while (i < data->num)
			pthread_mutex_destroy(&(phs[i++].phm));
		free(phs);
	}
	return (INVALID);
}

int	ph_term_valid(t_monitor *mon, t_philo *phs, t_data *data)
{
	int	i;

	if (data->forks)
	{
		i = 0;
		while (i < data->num)
			pthread_mutex_destroy(data->forks + i++);
		free(data->forks);
	}
	pthread_mutex_destroy(&(mon->eat));
	pthread_mutex_destroy(&(mon->end));
	if (phs)
	{
		i = 0;
		while (i < data->num)
			pthread_mutex_destroy(&(phs[i++].phm));
		free(phs);
	}	
	return (VALID);
}
