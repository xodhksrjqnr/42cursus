#include "ft_printf.h"

static t_list	*parse(const char *s)
{
	while (*s)
	{
		if (*s == '%')

	}	
}

int				ft_printf(const char *s, ...)
{
	va_list		ap;
	t_list		*list;
	int			count;

	if (!(list = parse(s)))
		return (-1);
	va_start(ap, s);
	count = 0;
	while (*s)
	{
		if (*s == '%')
		{
			s += print_format(list, ap);
			count += list->len;
		}
		else
			write(1, s++, 1);
		count++;
	}
	va_end(ap);
	return (count);
}
