/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taewakim <taewakim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 13:38:13 by taewakim          #+#    #+#             */
/*   Updated: 2021/06/09 13:38:14 by taewakim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_stack(t_elem **stack, char flag)
{
	t_elem	*tmp;

	if (!*stack)
		return ;
	else if (!(*stack)->next || *stack == (*stack)->next)
		return ;
	tmp = sub_elem(stack);
	*stack = (*stack)->next;
	add_elem(stack, &tmp);
	*stack = (*stack)->prev->prev;
	write(1, "s", 1);
	if (flag == 1)
		write(1, "a", 1);
	else if (flag == 2)
		write(1, "b", 1);
	write(1, "\n", 1);
}

void	move_elem(t_elem **stack_1, t_elem **stack_2, char flag)
{
	t_elem	*tmp;

	if (!*stack_1)
		return ;
	tmp = sub_elem(stack_1);
	add_elem(stack_2, &tmp);
	*stack_2 = (*stack_2)->prev;
	write(1, "p", 1);
	if (flag == 1)
		write(1, "a", 1);
	else if (flag == 2)
		write(1, "b", 1);
	write(1, "\n", 1);
}

void	rotate_stack(t_elem **stack, char flag)
{
	if (!*stack)
		return ;
	*stack = (*stack)->next;
	write(1, "r", 1);
	if (flag == 1)
		write(1, "a", 1);
	else if (flag == 2)
		write(1, "b", 1);
	write(1, "\n", 1);
}

void	reverse_rotate_stack(t_elem **stack, char flag)
{
	if (!*stack)
		return ;
	*stack = (*stack)->prev;
	write(1, "rr", 2);
	if (flag == 1)
		write(1, "a", 1);
	else if (flag == 2)
		write(1, "b", 1);
	write(1, "\n", 1);
}
