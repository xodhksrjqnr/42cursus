#include "push_swap.h"

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

char		check_start(t_elem **s1, int *leng, char *flag)
{
	*flag = 0;
	if (*leng > 3)
		return (1);
	if (*leng == 3)
		set_last_location(s1, leng);
	if (!*leng || *leng == 1)
		return (0);
	else if (*leng == 2 && (*s1)->value > (*s1)->next->value)
		swap_stack(s1, 1);
	return (0);
}
