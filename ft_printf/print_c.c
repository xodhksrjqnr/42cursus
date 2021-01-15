#include "ft_printf.h"

int		print_c(int *flags, int num, int *count, va_list ap)
{
	char	*tmp;
	char	c;

	c = va_arg(ap, int);
	if (num <= 1)
	{
		write(1, &c, 1);
		*count += 1;
	}
	else
	{
		if (!(tmp = malloc(num + 1)))
			return (0);
		tmp[num] = 0;
		if (flags[1])
			ft_memset(tmp, '0', num);
		else
			ft_memset(tmp, ' ', num);
		if (flags[0])
			tmp[0] = c;
		else
			tmp[num - 1] = c;
		*count += num;
		while (*tmp)
			write(1, tmp++, 1);
	}
	return (1);
}
