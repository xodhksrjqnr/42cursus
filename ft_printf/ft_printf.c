#include "ft_printf.h"
#include <stdio.h>

static int	error_check(const char *s)
{
 	s++;
	return (1);
}

static int	print_format(const char *s, int *count, va_list ap)
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
		if (!make_format(type, flags, num, count, ap))
			return (-1);
	}
	return (s - save);
}

int			ft_printf(const char *format, ...)
{
	va_list		ap;
	int			count;
	int			len;

	if (!(error_check(format)))
		return (-1);
	va_start(ap, format);
	count = 0;
	len = 0;
	while (*format)
	{
		if (*format == '%')
		{
			if ((len = print_format(++format, &count, ap)) == -1)
				return (-1);
			format += len;
		}
		else
		{
			write(1, format, 1);
			count++;
		}
		format++;
	}
	va_end(ap);
	return (count);
}

int			main(void)
{
	ft_printf("%-*c.end\n", 'a');
	printf("%-*c.end\n", 10, 'a');
	return (0);
}
