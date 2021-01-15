#include "ft_printf.h"

t_list		*newformat(void)
{
	t_list	*new;

	if (!(new = malloc(sizeof(t_list))))
		return (0);
	new->type = 0;
	new->left = 0;
	new->zero = 0;
	new->dot = 0;
	new->star = 0;
	new->width = 0;
	new->next = 0;
	return (new);
}
