#include "push_swap.h"

void		find_low_start(t_elem **stack, int leng, char flag, char flag2)
{
	t_elem	*tmp;
	int		i;

	if (!flag)
		return ;
	i = 0;
	tmp = *stack;
	while (i++ < leng)
		tmp = tmp->prev;
	i = 1;
	while (tmp != *stack && i++)
		tmp = tmp->prev;
	i--;
	if (i < leng)
		while (i-- > 0)
			rotate_stack(stack, flag2);
	else
		while (leng-- > 0)
			reverse_rotate_stack(stack, flag2);
}

static int	find_mid(t_elem *s, int leng)
{
	int	min;
	int	max;
	int	i;

	min = s->value;
	max = s->value;
	i = 0;
	while (i++ < leng)
	{
		if (min < s->value)
			min = s->value;
		else if (max > s->value)
			max = s->value;
		s = s->next;
	}
	return ((min + max) / 2);
}

int			find_pivot(t_elem *s, int leng)
{
	long long	diff;
	long long	tmp;
	long long	mid;
	int			i;
	int			pivot;

	mid = (long long)find_mid(s, leng);
	pivot = s->value;
	diff = mid - (long long)pivot;
	if (diff < 0)
		diff *= -1;
	i = 0;
	while (i++ < leng)
	{
		tmp = mid - (long long)s->value;
		if (tmp < 0)
			tmp *= -1;
		if (tmp < diff)
		{
			pivot = s->value;
			diff = tmp;
		}
		s = s->next;
	}
	return (pivot);
}
