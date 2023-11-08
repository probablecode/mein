/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchoi <jchoi@student.42Seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 15:54:37 by jchoi             #+#    #+#             */
/*   Updated: 2022/09/06 15:49:42 by jchoi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <sys/time.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>

# define TRUE 1
# define FALSE 0
# define ERROR -1
# define VALID 0
# define INVALID 1
# define GRAB 1
# define EAT 2
# define NAP 3
# define THINK 4
# define NOFORK 0
# define RFORK 1
# define LFORK 2

typedef struct s_data
{
	int				num;
	long long		time_die;
	long long		time_eat;
	long long		time_nap;
	int				opt;
	int				opt_goal;
	long long		start;
	pthread_mutex_t	*forks;
}	t_data;

typedef struct s_monitor
{
	int				opt_done;
	int				error;
	int				mic_on;
	struct s_philo	*philos;
	pthread_mutex_t	eat;
	pthread_mutex_t	end;
}	t_monitor;

typedef struct s_philo
{
	int				idx;
	int				eats;
	int				isend;
	int				hands;
	t_monitor		*mon;
	long long		lastmeal;
	pthread_mutex_t	phm;
	pthread_t		pth;
	t_data			*data;
}	t_philo;

//	ph_init.c 
int		ph_input(int argc, char *argv[], t_data *data);
int		ph_usage(void);
int		ph_init(t_monitor *mon, t_philo **phs, t_data *data);
int		ph_init_philo(t_philo *phs, t_monitor *mon, t_data *data);
int		ph_start(t_philo *phs, t_data *data);
//	ph_monitor.c
int		ph_monitor(t_monitor *mon, t_philo *phs, t_data *data);
int		ph_isterm(t_monitor *mon, t_philo *phs, t_data *data);
int		ph_isdead(t_monitor *mon, t_philo *phs, t_data *data);
void	ph_term(t_philo *phs, t_data *data);
//	ph_routine.c
void	*ph_routine(void *arg);
int		ph_error(t_monitor *mon, t_data *data);
int		ph_report(t_monitor *mon, int state, t_philo *philo, long long cur);
int		ph_isend(t_philo *philo);
int		ph_finish(t_philo *philo, t_monitor *mon, t_data *data, long long cur);
//	ph_action.c
int		ph_grap(t_philo *philo, t_monitor *mon);
int		ph_eat(t_philo *philo, t_monitor *mon, long long cur);
int		ph_put(t_philo *philo, t_monitor *mon, long long cur);
int		ph_nap(t_philo *philo, t_monitor *mon, long long cur);
int		ph_think(t_philo *philo, t_monitor *mon, long long cur);
//	ph_term.c
int		ph_term_error(t_monitor *mon, t_philo *phs, t_data *data);
int		ph_term_valid(t_monitor *mon, t_philo *phs, t_data *data);
//	ph_utils.c
int		ph_calloc(void **ptr, int num, size_t size);
int		ph_curtime(long	long *ms);
int		ph_wait(long long start, long long arg);
//	ph_atoi.c
int		ph_atoi(char *str, void *val, size_t size);
#endif
