#include "ft_printf.h"

int		check_flags(const char *s, int *flags)
{
	int		count;

	count = 0;
	while (*s == '-' || *s == '0' || *s == '.' || *s == '*')
	{
		if (*s == '-')
			*flags += 1;
		else if (*s == '0')
			*(flags + 1) += 1;
		else if (*s == '.')
			*(flags + 2) += 1;
		else if (*s == '*')
			*(flags + 3) += 1;
		count++;
		s++;
	}
	return (count);
}

int		check_num(const char *s, int *num)
{
	int		count;

	count = 0;
	*num = ft_atoi(s);
	while (*s >= '0' && *s <= '9')
	{
		s++;
		count++;
	}
	return (count);
}

int		make_format(char type, int *flags, int num, int *count, va_list ap)
{
	if (type == 'c')
		return (print_c(flags, num, count, ap));
	return (1);
	//else if (type == 's')
	//else if (type == 'p')
	//else if (type == 'd' || type == 'i')
	//else if (type == 'u')
	//else if (type == 'x')
	//else if (type == 'X')
}
