#include "push_swap.h"

static char	move_end(t_elem **s1, t_elem **s2, int leng)
{
	int	i;

	if (leng > 3)
		return (1);
	i = 0;
	while (i++ < leng)
		move_elem(s1, s2, 1);
	check_end(s2, leng);
	return (0);
}

static void	move_target(t_elem **s1, t_elem **s2, int leng)
{
	int	pivot;
	int	count;
	int	i;

	if (!move_end(s1, s2, leng))
		return ;
	i = 0;
	pivot = find_pivot(*s1, leng);
	count = 0;
	while (i++ < leng)
	{
		if ((*s1)->value >= pivot)
		{
			move_elem(s1, s2, 1);
			count++;
		}
		else
			rotate_stack(s1, 2);
	}
	find_low_start(s1, leng - count, 1, 2);
	sort_target(s2, s1, count, 1);
	move_target(s1, s2, leng - count);
}

void		sort_target(t_elem **s1, t_elem **s2, int leng, char flag)
{
	int	pivot;
	int	count;
	int	i;

	if (!check_end(s1, leng))
		return ;
	pivot = find_pivot(*s1, leng);
	i = 0;
	count = 0;
	while (i++ < leng)
	{
		if ((*s1)->value < pivot)
		{
			move_elem(s1, s2, 2);
			count++;
		}
		else
			rotate_stack(s1, 1);
	}
	find_low_start(s1, leng - count, flag, 1);
	sort_target(s1, s2, leng - count, flag);
	move_target(s2, s1, count);
}