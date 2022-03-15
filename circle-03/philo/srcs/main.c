/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taewan <taewan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 23:54:01 by taewan            #+#    #+#             */
/*   Updated: 2022/03/15 15:03:31 by taewan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	free_data(t_info *info, t_philo *philos, int num)
{
	int	i;

	pthread_mutex_destroy(&info->print);
	pthread_mutex_destroy(&info->death);
	i = -1;
	while (++i < info->num)
		pthread_mutex_destroy(info->forks + i);
	free(info->forks);
	if (num == 1)
		free(philos);
	return (0);
}

int	main(int ac, char **av)
{
	t_info	info;
	t_philo	*philos;

	philos = 0;
	if (!init_info(&info, ac, av))
		return (0);
	if (!init_philo(&philos, &info))
		return (free_data(&info, philos, 0));
	if (!run_threads(philos, &info))
		info.die = 1;
	free_data(&info, philos, 1);
	return (0);
}
