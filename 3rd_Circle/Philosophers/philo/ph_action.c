/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_action.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchoi <jchoi@student.42Seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 16:06:06 by jchoi             #+#    #+#             */
/*   Updated: 2022/09/06 18:03:26 by jchoi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ph_grap(t_philo *philo, t_monitor *mon)
{
	long long	cur;
	t_data		*data;

	data = philo->data;
	if (ph_isend(philo))
		return (FALSE);
	if (pthread_mutex_lock(&(data->forks[philo->idx])))
		return (pthread_mutex_unlock(&(mon->end)) && ph_error(mon, data));
	philo->hands += LFORK;
	if (philo->data->num == 1)
	{
		usleep(data->time_die * 1200);
		if (ph_isend(philo))
			return (FALSE);
	}
	else if (pthread_mutex_lock(&(data->forks[(philo->idx + 1) % data->num])))
		return (pthread_mutex_unlock(&(mon->end)) && ph_error(mon, data));
	philo->hands += RFORK;
	pthread_mutex_lock(&mon->end);
	ph_curtime(&cur);
	if (ph_report(mon, GRAB, philo, cur))
	{
		return (ph_eat(philo, mon, cur));
	}
	return (!ph_isend(philo));
}

int	ph_eat(t_philo *philo, t_monitor *mon, long long cur)
{
	t_data		*data;
	int			count;

	data = philo->data;
	if (!ph_report(mon, EAT, philo, cur))
		return (!ph_isend(philo));
	pthread_mutex_lock(&(philo->phm));
	philo->lastmeal = cur;
	count = ++philo->eats;
	pthread_mutex_unlock(&(philo->phm));
	if (data->opt && (data->opt_goal == count))
	{
		pthread_mutex_lock(&(mon->eat));
		if (data->num == ++mon->opt_done)
			return (ph_finish(philo, mon, data, cur));
		pthread_mutex_unlock(&mon->eat);
	}	
	pthread_mutex_unlock(&mon->end);
	ph_wait(cur, data->time_eat);
	return (ph_put(philo, mon, cur + data->time_eat));
}

int	ph_put(t_philo *philo, t_monitor *mon, long long cur)
{
	t_data	*data;

	data = philo->data;
	if (ph_isend(philo))
		return (FALSE);
	if (pthread_mutex_unlock(&(data->forks[philo->idx])))
		return (ph_error(mon, philo->data));
	else
		philo->hands -= LFORK;
	if (pthread_mutex_unlock(&(data->forks[(philo->idx + 1) % data->num])))
		return (ph_error(mon, philo->data));
	else
		philo->hands -= RFORK;
	return (ph_nap(philo, mon, cur));
}

int	ph_nap(t_philo *philo, t_monitor *mon, long long cur)
{
	if (ph_isend(philo))
		return (FALSE);
	pthread_mutex_lock(&(mon->end));
	if (ph_report(mon, NAP, philo, cur))
	{
		pthread_mutex_unlock(&(mon->end));
		ph_wait(cur, philo->data->time_nap);
		return (ph_think(philo, mon, cur + philo->data->time_nap));
	}
	else
		return (!ph_isend(philo));
}

int	ph_think(t_philo *philo, t_monitor *mon, long long cur)
{
	if (ph_isend(philo))
		return (FALSE);
	pthread_mutex_lock(&(mon->end));
	if (ph_report(mon, THINK, philo, cur))
	{
		pthread_mutex_unlock(&(mon->end));
		return (TRUE);
	}
	else
		return (!ph_isend(philo));
}
