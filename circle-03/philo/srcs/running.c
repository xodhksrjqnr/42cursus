/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   running.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taewan <taewan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 23:53:44 by taewan            #+#    #+#             */
/*   Updated: 2022/03/12 00:41:27 by taewan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	drop_fork(t_philo *philo)
{
	pthread_mutex_unlock(philo->right);
	pthread_mutex_unlock(philo->left);
	print("is sleeping", philo);
	my_usleep(philo->info->t_sleep);
	print("is thinking", philo);
}

static void	check_time(t_philo *philo)
{
	int	time;

	time = time_set() - philo->info->s_time;
	if (time - philo->p_time > philo->info->t_die)
	{
		pthread_mutex_lock(&philo->info->print);
		if (!philo->info->die)
			printf("%d %d %s\n", time, philo->name, "died");
		pthread_mutex_lock(&philo->info->death);
		philo->info->die = 1;
		pthread_mutex_unlock(&philo->info->death);
		pthread_mutex_unlock(&philo->info->print);
	}
	philo->p_time = time;
}

static void	*philo_one(t_philo *philo)
{
	while (!is_die(philo) && philo->eat != 0)
	{
		pthread_mutex_lock(philo->left);
		print("has taken a fork", philo);
		while (!is_die(philo))
		{
			check_time(philo);
			philo->p_time = 0;
		}
		pthread_mutex_unlock(philo->left);
	}
	return (0);
}

static void	*behavior(void *data)
{
	t_philo	*philo;

	philo = (t_philo *)data;
	if (philo->info->num == 1)
		return (philo_one(philo));
	if (philo->name % 2 == 0)
		usleep(100);
	while (!is_die(philo) && philo->eat != 0)
	{
		pthread_mutex_lock(philo->left);
		print("has taken a fork", philo);
		usleep(50);
		pthread_mutex_lock(philo->right);
		print("has taken a fork", philo);
		check_time(philo);
		print("is eating", philo);
		my_usleep(philo->info->t_eat);
		philo->eat--;
		drop_fork(philo);
		usleep(50);
	}
	return (0);
}

int	run_threads(t_philo *philos, t_info *info)
{
	int		i;

	i = -1;
	info->s_time = time_set();
	while (++i < info->num)
	{
		usleep(50);
		if (pthread_create(&(philos + i)->thread, NULL, behavior, philos + i))
			return (error_print("pthread create error"));
	}
	usleep(1000000);
	while (--i >= 0)
	{
		usleep(1000);
		if (pthread_join((philos + i)->thread, NULL))
			error_print("pthread join error");
	}
	return (1);
}
