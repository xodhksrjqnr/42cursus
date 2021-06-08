#include "push_swap.h"

static int	first_div_stack(t_elem **s1, t_elem **s2, int leng)
{
	t_data	data;

	init_data(&data, find_pivot(*s1, leng, 0));
	while (data.i++ < leng)
	{
		if ((*s1)->value <= data.pivot)
		{
			move_elem(s1, s2, 2);
			if ((*s2)->value <= data.pivot2)
			{
				if (data.i - data.count != 1)
					rotate_stack(s2, 2);
				data.count++;
			}
			data.count2++;
		}
		else
			rotate_stack(s1, 1);
	}
	return (data.count);
}

static void	set_last_location(t_elem **s, int *leng)
{
	int	v[3];

	v[0] = (*s)->value;
	v[1] = (*s)->next->value;
	v[2] = (*s)->prev->value;
	if (v[0] > v[1] && v[0] > v[2])
		rotate_stack(s, 1);
	else if (v[1] > v[0] && v[1] > v[2])
		reverse_rotate_stack(s, 1);
	(*leng)--;
}

char		check_start(t_elem **s1, t_elem **s2, int *leng, char *flag)
{
	check_end_value(s1, leng, flag);
	if (*leng > 3)
		return (first_div_stack(s1, s2, *leng));
	if (*leng == 3)
		set_last_location(s1, leng);
	if (!*leng || *leng == 1)
		return (0);
	else if (*leng == 2 && (*s1)->value > (*s1)->next->value)
		swap_stack(s1, 1);
	return (0);
}
