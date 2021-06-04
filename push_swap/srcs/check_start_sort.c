#include "push_swap.h"

static void	set_value_s(t_elem *s, int *value)
{
	value[0] = s->value;
	value[1] = s->next->value;
	value[2] = s->next->next->value;
}

static void	elem_two_sort_s(t_elem **stack)
{
	if ((*stack)->value > (*stack)->next->value)
		swap_stack(stack, 1);
}

static void	elem_three_sort_s(t_elem **s, int *v)
{
	if (v[0] > v[1] && v[0] < v[2])
		swap_stack(s, 1);
	else if (v[2] < v[1] && v[2] < v[0])
	{
		if (v[0] > v[1])
			swap_stack(s, 1);
		reverse_rotate_stack(s, 1);
	}
	else if (!(v[0] < v[1] && v[1] < v[2]))
	{
		rotate_stack(s, 1);
		if (v[1] > v[2])
		{
			swap_stack(s, 1);
			reverse_rotate_stack(s, 1);
		}
	}
}

char		check_start(t_elem **s1, int leng)
{
	int v[3];

	if (leng > 3)
		return (1);
	else if (!leng || leng == 1)
		return (0);
	else if (leng == 2)
		elem_two_sort_s(s1);
	else if (leng == 3)
	{
		set_value_s(*s1, v);
		elem_three_sort_s(s1, v);
	}
	return (0);
}
