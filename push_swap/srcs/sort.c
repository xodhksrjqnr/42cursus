#include "push_swap.h"

static void	move_target(t_elem **s1, t_elem **s2, int leng, char flag)
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
		}
		else
			rotate_stack(s1, 2);
	}
	data.count2 = leng - data.count;
	find_low_start(s1, s2, &data.count2, 2);
	sort_target(s2, s1, data.count, 1);
	move_target(s1, s2, data.count2, flag);
}

void		sort_target(t_elem **s1, t_elem **s2, int leng, char flag)
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
		}
		else
			rotate_stack(s1, 1);
	}
	data.count2 = leng - data.count;
	if (flag)
		if (find_low_start(s1, s2, &data.count2, 1))
			data.check = 1;
	sort_target(s1, s2, data.count2, flag);
	if (data.check)
		move_target(s2, s1, leng - data.count - data.count2, flag);
	move_target(s2, s1, data.count, flag);
}

char		reverse_sort(t_elem **s1, t_elem **s2, int *leng, char flag)
{
	t_data	data;

	reverse_rotate_stack(s1, flag);
	init_data(&data, find_pivot(*s1, *leng, 1));
	while (data.i++ < *leng)
	{
		if ((*s1)->value < data.pivot && flag == 1)
		{
			move_elem(s1, s2, 2);
			data.count++;
		}
		else if ((*s1)->value >= data.pivot && flag == 2)
		{
			move_elem(s1, s2, 1);
			data.count++;
		}
		if (data.i != *leng)
			reverse_rotate_stack(s1, flag);
	}
	*leng -= data.count;
	return (1);
}
