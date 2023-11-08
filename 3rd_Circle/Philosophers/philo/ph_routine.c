/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_routine.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchoi <jchoi@student.42Seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 16:06:06 by jchoi             #+#    #+#             */
/*   Updated: 2022/09/06 15:51:36 by jchoi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*ph_routine(void *arg)
{
	t_philo		*philo;
	t_monitor	*mon;

	philo = (t_philo *)arg;
	mon = philo->mon;
	pthread_mutex_lock(&philo->phm);
	pthread_mutex_unlock(&philo->phm);
	if (!(philo->idx % 2))
		usleep(1000);
	while (TRUE)
	{
		if (!ph_grap(philo, mon))
			break ;
		usleep(100);
	}
	return (NULL);
}

int	ph_error(t_monitor *mon, t_data *data)
{
	pthread_mutex_lock(&mon->end);
	mon->error = TRUE;
	mon->mic_on = FALSE;
	ph_term(mon->philos, data);
	pthread_mutex_unlock(&mon->end);
	printf("Invalid exit of program by error occuring\n");
	return (FALSE);
}

int	ph_report(t_monitor *mon, int state, t_philo *philo, long long cur)
{
	t_data				*data;
	static const char	*str[4] = {"has taken a fork\n", "is eating\n",
		"is sleeping\n", "is thinking\n"};

	data = philo->data;
	if (mon->mic_on == FALSE)
	{
		pthread_mutex_unlock(&mon->end);
		return (FALSE);
	}
	cur -= data->start;
	printf("%lld\t\t%d %s", cur, philo->idx + 1, str[state - 1]);
	if (state == GRAB)
		printf("%lld\t\t%d %s", cur, philo->idx + 1, str[state - 1]);
	return (TRUE);
}

int	ph_isend(t_philo *philo)
{
	t_data	*data;

	data = philo->data;
	pthread_mutex_lock(&(philo->phm));
	if (philo->isend)
	{
		pthread_mutex_unlock(&(philo->phm));
		if (philo->hands & LFORK)
		{
			philo->hands -= LFORK;
			pthread_mutex_unlock(&(data->forks[philo->idx]));
		}
		if (philo->hands & RFORK)
		{
			philo->hands -= RFORK;
			pthread_mutex_unlock(&(data->forks[(philo->idx + 1) % data->num]));
		}
		return (TRUE);
	}
	pthread_mutex_unlock(&(philo->phm));
	return (FALSE);
}

int	ph_finish(t_philo *philo, t_monitor *mon, t_data *data, long long cur)
{
	pthread_mutex_unlock(&(mon->eat));
	mon->mic_on = FALSE;
	pthread_mutex_lock(&(philo->phm));
	philo->hands -= LFORK;
	pthread_mutex_unlock(&(data->forks[philo->idx]));
	philo->hands -= RFORK;
	pthread_mutex_unlock(&(data->forks[(philo->idx + 1) % data->num]));
	pthread_mutex_unlock(&(philo->phm));
	ph_term(mon->philos, data);
	printf("%lld\t\tFinished!\n", cur - data->start);
	pthread_mutex_unlock(&(mon->end));
	return (FALSE);
}
