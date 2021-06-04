#include "push_swap.h"

void	error_message(void)
{
	write(0, "Error\n", 6);
	exit(1);
}

int		main(int argc, char **argv)
{
	t_elem	*stack_a;
	t_elem	*stack_b;
	int		size;

	stack_a = 0;
	stack_b = 0;
	size = setting_program(&stack_a, argc, argv);
	if (!size)
		error_message();
	if (!check_start(&stack_a, size))
		return (0);
	sort_target(&stack_a, &stack_b, size, 0);
	//print_tmp(stack_a, stack_b);
	return (0);
}
