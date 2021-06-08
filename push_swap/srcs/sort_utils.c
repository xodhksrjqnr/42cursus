#include "push_swap.h"

void		init_data(t_data *data, int pivot)
{
	data->check = 0;
	data->check2 = 0;
	data->count2 = 0;
	data->count = 0;
	data->i = 0;
	data->pivot = pivot;
	if (data->pivot > 0)
		data->pivot2 = pivot * 0.5;
	else
		data->pivot2 = pivot * 2;
}

void		set_dir(t_elem **s, char dir)
{
	if (!dir)
		*s = (*s)->next;
	else
		*s = (*s)->prev;
}

void		find_low_start(t_elem **s1, t_elem **s2, t_data *data, char flag)
{
	t_elem	*tmp;

	if (!flag)
		return ;
	data->i = 0;
	tmp = *s1;
	while (tmp->next != *s1 && data->i++ > -1)
		tmp = tmp->next;
	data->i -= data->count2;
	if (data->i < data->count2)
		while (data->i-- > 0 - (int)data->check2)
			rotate_stack(s1, flag);
	else if (flag == 2)
	{
		data->i = 0 + (int)data->check2;
		while (data->i++ < data->count2)
			reverse_rotate_stack(s1, flag);
	}
	else
	{
		data->check = 1;
		if (!data->check2)
			reverse_rotate_stack(s1, 1);
		reverse_sort(s1, s2, &data->count2);
	}
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
