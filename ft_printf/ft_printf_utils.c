#include "ft_printf.h"

t_list		*newformat(void)
{
	t_list	*new;

	new->type = 0;
	new->left = 0;
	new->zero = 0;
	new->dot = 0;
	new->wild = 0;
	new->width = 0;
	return (new);
}
