/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchoi <jchoi@student.42Seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 17:44:48 by jchoi             #+#    #+#             */
/*   Updated: 2022/09/06 15:44:00 by jchoi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char *argv[])
{
	t_monitor	mon;
	t_philo		*phs;
	t_data		data;
	int			err;

	if (!ph_input(argc, argv, &data))
		return (ph_usage());
	if (!ph_init(&mon, &phs, &data))
		return (printf("ph_init function failed, exit. \n"));
	mon.philos = phs;
	err = ph_monitor(&mon, phs, &data);
	if (err)
		return (ph_term_error(&mon, phs, &data));
	else
		return (ph_term_valid(&mon, phs, &data));
}
