#ifndef PHILO_H
# define PHILO_H
# include <pthread.h>
# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <sys/time.h>
# include <stdio.h>

int	setting(int ac, char **av, long *input);
int	running(long *input);

#endif