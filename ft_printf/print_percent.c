#include "ft_print.h"

void	print_percent(t_flags cur, int *count, char *tmp)
{
	if (!*tmp)
	{
		write(1, "%", 1);
		*count += 1;
		return ;
	}
	if (cur.minus)
		tmp[0] = '%';
	else
		tmp[cur.first - 1] = '%';
	while (*tmp)
	{
		write(1, tmp, 1);
		*count += 1;
	}
}
