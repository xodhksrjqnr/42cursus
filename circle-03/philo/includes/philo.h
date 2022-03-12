/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taewan <taewan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 23:54:04 by taewan            #+#    #+#             */
/*   Updated: 2022/03/12 00:01:25 by taewan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include <pthread.h>
# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <sys/time.h>
# include <stdio.h>

typedef struct s_info
{
	pthread_mutex_t	print;
	pthread_mutex_t	death;
	pthread_mutex_t	*forks;
	long			s_time;
	int				die;
	int				num;
	int				t_die;
	int				t_eat;
	int				t_sleep;
	int				must_eat;
}	t_info;

typedef struct s_philo
{
	int				p_time;
	int				name;
	int				eat;
	pthread_mutex_t	*left;
	pthread_mutex_t	*right;
	pthread_t		thread;
	struct s_info	*info;
}	t_philo;

int		init_info(t_info *info, int ac, char **av);
int		init_philo(t_philo **philos, t_info *info);
int		run_threads(t_philo *philos, t_info *info);

int		is_die(t_philo *philo);
int		error_print(char *message);
void	my_usleep(int time);
void	print(const char *str, t_philo *philo);
long	time_set(void);

#endif