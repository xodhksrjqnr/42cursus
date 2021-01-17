#include "ft_printf.h"

int		print_c(t_list *cur, va_list ap)
{
	int		count;
	char	c;

	count = 0;
	c = va_arg(ap, int);
	if (cur->first == -1)
	{
		write(1, &c, 1);
		return (1);
	}
	if (cur->minus)
	{
		write(1, &c, 1);
		while (count++ < cur->first - 1)
			write(1, " ", 1);
	}
	else
	{
		while (count++ < cur->first - 1)
			write(1, " ", 1);
		write(1, &c, 1);
	}
	return (count + 1);
}
