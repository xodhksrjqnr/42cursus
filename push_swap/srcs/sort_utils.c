#include "push_swap.h"

void		init_data(t_data *data, int pivot)
{
	data->check = 0;
	data->count2 = 0;
	data->count = 0;
	data->i = 0;
	data->pivot = pivot;
}

void		set_dir(t_elem **s, char dir)
{
	if (!dir)
		*s = (*s)->next;
	else
		*s = (*s)->prev;
}

char		find_low_start(t_elem **s1, t_elem **s2, int *leng, char flag)
{
	t_elem	*tmp;
	int		i;

	i = 1;
	tmp = *s1;
	while (tmp->next != *s1 && i++)
		tmp = tmp->next;
	i--;
	i -= *leng;
	if (i < *leng)
		while (i-- > 0)
			rotate_stack(s1, flag);
	else if (flag == 2)
	{
		i = 0;
		while (i++ < *leng)
			reverse_rotate_stack(s1, flag);
	}
	else
		return (reverse_sort(s1, s2, leng, flag));
	return (0);
}

static int	find_mid(t_elem *s, int leng, char dir)
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
		set_dir(&s, dir);
	}
	return ((min + max) / 2);
}

int			find_pivot(t_elem *s, int leng, char dir)
{
	long long	diff;
	long long	tmp;
	long long	mid;
	int			pivot;

	mid = (long long)find_mid(s, leng, dir);
	pivot = s->value;
	diff = mid - (long long)s->value;
	if (diff < 0)
		diff *= -1;
	while (leng-- > 0)
	{
		tmp = mid - (long long)s->value;
		if (tmp < 0)
			tmp *= -1;
		if (tmp < diff)
		{
			pivot = s->value;
			diff = tmp;
		}
		set_dir(&s, dir);
	}
	return (pivot);
}
