#ifndef COMMAND_H
# define COMMAND_H

# include "elem.h"
# include <unistd.h>

void	double_reverse_rotate_stack(t_elem **s1, t_elem **s2);
void	double_rotate_stack(t_elem **s1, t_elem **s2);
void	double_swap_stack(t_elem **stack_1, t_elem **stack_2);
void	swap_stack(t_elem **stack, char flag);
void	move_elem(t_elem **stack_1, t_elem **stack_2, char flag);
void	rotate_stack(t_elem **stack, char flag);
void	reverse_rotate_stack(t_elem **stack, char flag);

#endif
