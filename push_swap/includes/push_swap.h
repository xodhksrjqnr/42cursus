#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "command.h"
# include <stdlib.h>
# include <fcntl.h>

#include <stdio.h>

int		setting_program(t_elem **stack_a, int argc, char **argv);
void	sort_target(t_elem **s1, t_elem **s2, int leng, char flag);
char	check_start(t_elem **s1, int leng);
char	check_end(t_elem **s1, int leng);

void	find_low_start(t_elem **stack, int leng, char flag, char flag2);
int		find_pivot(t_elem *s, int leng);

void    error_message(void);

void print_tmp(t_elem *s1, t_elem *s2);
void    check(char *buff, t_elem **s1, t_elem **s2);

#endif