#ifndef COMMAND_H
# define COMMAND_H

# include "elem.h"
# include <unistd.h>

void	swap_stack(t_elem **stack, char flag);
void	move_elem(t_elem **stack_1, t_elem **stack_2, char flag);
void	rotate_stack(t_elem **stack, char flag);
void	reverse_rotate_stack(t_elem **stack, char flag);

void	double_swap_stack(t_elem **stack_1, t_elem **stack_2);

void	print_command(char *command, char flag, int leng);

#endif
