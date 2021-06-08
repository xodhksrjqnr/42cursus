#include "push_swap.h"

static void	double_check(t_elem **s1, t_elem **s2, t_data *data)
{
	if (data->count > 3 && data->count2 > 3)
		return ;
	else if (data->count < 2 && data->count2 < 2)
		return ;
	if ((*s1)->value > (*s1)->next->value && (*s2)->value < (*s2)->next->value)
		double_swap_stack(s1, s2);
}

void	move_target(t_elem **s1, t_elem **s2, int leng, char flag)
{
	t_data	data;

	if (!move_end(s1, s2, &leng, &flag))
		return ;
	init_data(&data, find_pivot(*s1, leng, 0));
	while (data.i++ < leng)
	{
		if ((*s1)->value >= data.pivot)
		{
			move_elem(s1, s2, 1);
			data.count++;
			continue ;
		}
		if (data.i != leng)
			rotate_stack(s1, 2);
		else
			data.check2 = 1;
	}
	data.count2 = leng - data.count;
	find_low_start(s1, s2, &data, 2);
	double_check(s2, s1, &data);
	sort_target(s2, s1, data.count, 1);
	move_target(s1, s2, data.count2, flag);
}

void	sort_target(t_elem **s1, t_elem **s2, int leng, char flag)
{
	t_data	data;

	if (!check_end(s1, &leng, &flag))
		return ;
	init_data(&data, find_pivot(*s1, leng, 0));
	while (data.i++ < leng)
	{
		if ((*s1)->value < data.pivot)
		{
			move_elem(s1, s2, 2);
			data.count++;
			continue ;
		}
		if (data.i != leng)
			rotate_stack(s1, 1);
		else
			data.check2 = 1;
	}
	data.count2 = leng - data.count;
	find_low_start(s1, s2, &data, 1);
	double_check(s1, s2, &data);
	sort_target(s1, s2, data.count2, flag);
	if (data.check)
		move_target(s2, s1, leng - data.count - data.count2, flag);
	move_target(s2, s1, data.count, flag);
}

void	reverse_sort(t_elem **s1, t_elem **s2, int *leng)
{
	t_data	data;

	init_data(&data, find_pivot(*s1, *leng, 1));
	while (data.i++ < *leng)
	{
		if ((*s1)->value < data.pivot)
		{
			move_elem(s1, s2, 2);
			data.count++;
		}
		if (data.i != *leng)
			reverse_rotate_stack(s1, 1);
	}
	*leng -= data.count;
}
