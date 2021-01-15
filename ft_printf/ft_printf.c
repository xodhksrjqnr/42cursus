#include "ft_printf.h"
#include <stdio.h>

static int	error_check(const char *s)
{
 	s++;
	return (1);
}

static int	print_format(const char *s, int *count)
{
	int			len;
	int			flags[4];
	int			num;
	char		type;
	const char	*save;

	save = s;
	if (*s == '%')
	{
		write(1, "%", 1);
		*count += 1;
	}
	else
	{
		ft_bzero(flags, 16);
		s += check_flags(s, flags);
		s += check_num(s, &num);
		type = *s;
		make_format(type, flags, num, count);
	}
	return (s - save);
}

int			ft_printf(const char *format, ...)
{
	va_list		ap;
	int			count;
	int			len;

	va_start(ap, format);
	if (!(error_check(format)))
		return (-1);
	count = 0;
	len = 0;
	while (*format)
	{
		if (*format == '%')
		{
			len = print_format(++format, &count);
			format += len;
		}
		else
		{
			write(1, format, 1);
			count++;
		}
		format++;
	}
	return (count);
}

int			main(void)
{
	ft_printf("%-*.*d.end\n");
	return (0);
}
