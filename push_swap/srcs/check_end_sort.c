#include "push_swap.h"

static void	set_value_e(t_elem *s, int *value)
{
	value[0] = s->value;
	value[1] = s->next->value;
	value[2] = s->next->next->value;
}

static void	elem_two_sort_e(t_elem **stack)
{
	if ((*stack)->value > (*stack)->next->value)
		swap_stack(stack, 1);
}

static void	elem_three_sort_e(t_elem **s1, int *v)
{
	if (v[2] < v[0] && v[2] < v[1])
	{
		if (v[0] > v[1])
			swap_stack(s1, 1);
		rotate_stack(s1, 1);
		swap_stack(s1, 1);
		reverse_rotate_stack(s1, 1);
		swap_stack(s1, 1);
	}
	else if (v[2] > v[0] && v[2] > v[1])
	{
		if (v[0] > v[1])
			swap_stack(s1, 1);
	}
	else
	{
		if (v[0] > v[1])
			swap_stack(s1, 1);
		rotate_stack(s1, 1);
		swap_stack(s1, 1);
		reverse_rotate_stack(s1, 1);
	}
}

char		check_end(t_elem **s1, int leng)
{
	int v[3];

	if (leng > 3)
		return (1);
	else if (!leng || leng == 1)
		return (0);
	else if (leng == 2)
		elem_two_sort_e(s1);
	else if (leng == 3)
	{
		set_value_e(*s1, v);
		elem_three_sort_e(s1, v);
	}
	return (0);
}