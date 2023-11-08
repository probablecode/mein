/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_monitor.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchoi <jchoi@student.42Seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 18:58:52 by jchoi             #+#    #+#             */
/*   Updated: 2022/09/06 15:20:13 by jchoi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ph_monitor(t_monitor *mon, t_philo *phs, t_data *data)
{
	int	i;

	while (TRUE)
	{
		if (ph_isterm(mon, phs, data))
			break ;
		usleep(1000);
	}
	i = 0;
	while (i < data->num)
	{	
		pthread_join(phs[i].pth, NULL);
		i++;
	}
	return (mon->error);
}

int	ph_isterm(t_monitor *mon, t_philo *phs, t_data *data)
{
	pthread_mutex_lock(&mon->end);
	if (mon->error || mon->mic_on == FALSE)
	{
		pthread_mutex_unlock(&mon->end);
		return (TRUE);
	}
	if (ph_isdead(mon, phs, data))
		return (TRUE);
	return (FALSE);
}

int	ph_isdead(t_monitor *mon, t_philo *phs, t_data *data)
{
	long long	cur;
	int			i;

	ph_curtime(&cur);
	i = 0;
	while (i < data->num)
	{
		pthread_mutex_lock(&(phs[i].phm));
		if (data->time_die + phs[i].lastmeal <= cur)
		{
			pthread_mutex_unlock(&(phs[i].phm));
			mon->mic_on = FALSE;
			ph_term(phs, data);
			printf("%lld\t\t%d is died\n", cur - data->start, i + 1);
			pthread_mutex_unlock(&mon->end);
			return (TRUE);
		}
		pthread_mutex_unlock(&(phs[i].phm));
		i++;
	}
	pthread_mutex_unlock(&mon->end);
	return (FALSE);
}

void	ph_term(t_philo *phs, t_data *data)
{
	int	i;

	i = 0;
	while (i < data->num)
	{
		pthread_mutex_lock(&(phs[i].phm));
		phs[i].isend = TRUE;
		pthread_mutex_unlock(&(phs[i].phm));
		i++;
	}
}
