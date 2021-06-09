/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taewakim <taewakim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 13:38:21 by taewakim          #+#    #+#             */
/*   Updated: 2021/06/09 13:39:16 by taewakim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	check_size(t_elem *stack)
{
	t_elem	*start;
	int		count;

	count = 1;
	start = stack;
	while (stack->next != start)
	{
		count++;
		stack = stack->next;
	}
	return (count);
}

void		error_message(void)
{
	write(0, "Error\n", 6);
	exit(1);
}

int			main(int argc, char **argv)
{
	t_elem	*stack_a;
	t_elem	*stack_b;
	int		size;
	int		count[2];
	char	flag;

	stack_a = 0;
	stack_b = 0;
	size = setting_program(&stack_a, argc, argv);
	if (!size)
		error_message();
	flag = 0;
	count[0] = check_start(&stack_a, &stack_b, &size, &flag);
	if (!count[0])
		exit(0);
	count[1] = check_size(stack_b);
	sort_target(&stack_a, &stack_b, size - count[1], flag);
	move_target(&stack_b, &stack_a, count[1] - count[0], 1);
	move_target(&stack_b, &stack_a, count[0], 1);
	exit(0);
}
