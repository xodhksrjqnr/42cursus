/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taewan <taewan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 23:53:52 by taewan            #+#    #+#             */
/*   Updated: 2022/03/26 12:55:07 by taewan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	my_usleep(int time)
{
	long	pre_time;

	pre_time = time_set();
	while (time_set() - pre_time < time)
		usleep(1000);
}

int	is_die(t_philo *philo)
{
	int	flag;

	pthread_mutex_lock(&philo->info->death);
	flag = philo->info->die;
	pthread_mutex_unlock(&philo->info->death);
	return (flag);
}

int	error_print(char *message)
{
	printf("%s\n", message);
	return (0);
}

long	time_set(void)
{
	struct timeval	e;

	gettimeofday(&e, NULL);
	return (e.tv_sec * 1000 + e.tv_usec / 1000);
}

void	print(const char *str, t_philo *philo)
{
	int	time;

	pthread_mutex_lock(&philo->info->print);
	time = time_set() - philo->info->start_time;
	if (!is_die(philo))
		printf("%d %d %s\n", time, philo->name, str);
	pthread_mutex_unlock(&philo->info->print);
}
