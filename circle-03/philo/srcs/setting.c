/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taewan <taewan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 23:53:55 by taewan            #+#    #+#             */
/*   Updated: 2022/03/12 13:41:06 by taewan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	my_atoi(const char *str)
{
	long	num;
	int		sign;
	int		cur;

	cur = 0;
	while ((9 <= str[cur] && str[cur] <= 13) || str[cur] == ' ')
		cur++;
	sign = 1;
	if (str[cur] == '+' || str[cur] == '-')
		sign = 44 - str[cur++];
	num = 0;
	while (str[cur])
	{
		if (!('0' <= str[cur] && str[cur] <= '9'))
			return (-1);
		num = num * 10 + str[cur] - 48;
		cur++;
	}
	num *= sign;
	if (num < -2147483648 || num > 2147483647)
		return (-1);
	return ((int)num);
}

static int	info_mutex_init(t_info *info)
{
	int	i;

	if (pthread_mutex_init(&info->print, NULL))
		return (error_print("mutex init error"));
	if (pthread_mutex_init(&info->death, NULL))
	{
		pthread_mutex_destroy(&info->print);
		return (error_print("mutex init error"));
	}
	i = -1;
	while (++i < info->num)
		if (pthread_mutex_init(info->forks + i, NULL))
			break ;
	if (i != info->num)
	{
		while (--i >= 0)
			pthread_mutex_destroy(info->forks + i);
		pthread_mutex_destroy(&info->print);
		pthread_mutex_destroy(&info->death);
		return (error_print("mutex init error"));
	}
	return (1);
}

int	init_info(t_info *info, int ac, char **av)
{
	if (ac < 5 || ac > 6)
		return (error_print("argument invalid"));
	info->num = my_atoi(av[1]);
	info->t_die = my_atoi(av[2]);
	info->t_eat = my_atoi(av[3]);
	info->t_sleep = my_atoi(av[4]);
	info->must_eat = -1;
	info->die = 0;
	if (ac == 6)
		info->must_eat = my_atoi(av[5]);
	if (info->num < 0 || info->t_die < 0 || info->t_eat < 0
		|| info->t_sleep < 0 || info->must_eat < -1)
		return (error_print("argument invalid"));
	info->forks = malloc(info->num * sizeof(pthread_mutex_t));
	if (!info->forks)
		return (error_print("malloc error"));
	return (info_mutex_init(info));
}

int	init_philo(t_philo **philos, t_info *info)
{
	int	i;

	*philos = malloc(info->num * sizeof(t_philo));
	if (!*philos)
		return (error_print("init philo error"));
	i = -1;
	while (++i < info->num)
	{
		(*philos + i)->name = i + 1;
		(*philos + i)->p_time = 0;
		(*philos + i)->eat = info->must_eat;
		(*philos + i)->left = info->forks + i;
		(*philos + i)->right = info->forks + (i + 1) % info->num;
		(*philos + i)->info = info;
	}
	return (1);
}
