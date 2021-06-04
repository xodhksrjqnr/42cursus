#include "elem.h"

t_elem	*new_elem(int num)
{
	t_elem	*new;

	new = malloc(sizeof(t_elem));
	if (!new)
		return (0);
	new->next = new;
	new->prev = new;
	new->value = num;
	return (new);
}

t_elem	*sub_elem(t_elem **stack)
{
	t_elem	*save;

	if (!*stack)
		return (0);
	else if (*stack == (*stack)->next)
	{
		save = *stack;
		*stack = 0;
		return (save);
	}
	else
	{
		save = *stack;
		(*stack)->prev->next = (*stack)->next;
		(*stack)->next->prev = (*stack)->prev;
		*stack = (*stack)->next;
	}
	return (save);
}

void	add_elem(t_elem **stack, t_elem **new_elem)
{
	(*new_elem)->next = *new_elem;
	(*new_elem)->prev = *new_elem;
	if (!*stack)
		*stack = *new_elem;
	else if (!(*stack)->prev)
	{
		(*stack)->prev = *new_elem;
		(*stack)->next = *new_elem;
		(*new_elem)->next = *stack;
		(*new_elem)->prev = *stack;
	}
	else
	{
		(*new_elem)->prev = (*stack)->prev;
		(*new_elem)->next = *stack;
		(*new_elem)->prev->next = *new_elem;
		(*stack)->prev = *new_elem;
	}
}
