/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchoi <jchoi@student.42Seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 17:44:48 by jchoi             #+#    #+#             */
/*   Updated: 2022/09/06 15:26:55 by jchoi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ph_input(int argc, char *argv[], t_data *data)
{
	int	ret;

	ret = FALSE;
	if (argc == 5 || argc == 6)
	{
		ret = TRUE;
		ret *= ph_atoi(argv[1], &(data->num), sizeof(int));
		ret *= ph_atoi(argv[2], &(data->time_die), sizeof(long long));
		ret *= ph_atoi(argv[3], &(data->time_eat), sizeof(long long));
		ret *= ph_atoi(argv[4], &(data->time_nap), sizeof(long long));
		if (argc == 6)
		{
			data->opt = TRUE;
			ret *= ph_atoi(argv[5], &(data->opt_goal), sizeof(int));
		}
		else
			data->opt = FALSE;
	}
	return (ret);
}

int	ph_usage(void)
{
	printf("error : There must be 4 or 5 positive arguments only\n");
	printf("[usage] : ./philo %s %s %s %s %s\n",
		"number_of_philosophers",
		"time_to_die",
		"time_to_eat",
		"time_to_sleep",
		"[number_of_times_each_philosopher_must_eat]");
	return (INVALID);
}

int	ph_init(t_monitor *mon, t_philo **phs, t_data *data)
{
	int	i;
	int	j;

	if (!ph_calloc((void **)phs, data->num, sizeof(t_philo)))
		return (FALSE);
	if (!ph_calloc((void **)&data->forks, data->num, sizeof(pthread_mutex_t)))
		return (FALSE);
	i = 0;
	while (i < data->num && !pthread_mutex_init(data->forks + i, NULL))
		i++;
	if (i < data->num)
	{
		j = 0;
		while (j < i)
			pthread_mutex_destroy(data->forks + j++);
		return (FALSE);
	}
	mon->opt_done = 0;
	mon->error = FALSE;
	mon->mic_on = TRUE;
	if (pthread_mutex_init(&mon->end, NULL))
		return (FALSE);
	if (!ph_init_philo(*phs, mon, data) || pthread_mutex_init(&mon->eat, NULL))
		return (FALSE);
	return (ph_start(*phs, data));
}

int	ph_init_philo(t_philo *phs, t_monitor *mon, t_data *data)
{
	int		i;
	int		j;
	t_philo	philo;

	memset(&philo, 0, sizeof(t_philo));
	philo.mon = mon;
	philo.data = data;
	i = -1;
	while (++i < data->num)
	{
		phs[i] = philo;
		phs[i].idx = i;
		if (pthread_mutex_init(&phs[i].phm, NULL))
		{
			j = 0;
			while (j < i)
				pthread_mutex_destroy(&phs[j++].phm);
			return (FALSE);
		}
		pthread_mutex_lock(&phs[i].phm);
		if (pthread_create(&(phs[i].pth), NULL, ph_routine, (void *)(phs + i)))
			return (FALSE);
	}
	return (TRUE);
}

int	ph_start(t_philo *phs, t_data *data)
{
	int	i;

	i = 0;
	ph_curtime(&data->start);
	while (i < data->num)
	{
		phs[i].lastmeal = data->start;
		pthread_mutex_unlock(&phs[i++].phm);
	}
	return (TRUE);
}
