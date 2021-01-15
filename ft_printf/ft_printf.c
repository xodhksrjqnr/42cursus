#include "ft_printf.h"
#include "./Libft/libft.h"

static int		error_check(const char *s, int len)
{
	write(1, "error_check\n", 12);
	return (1);
}

static int		make_list(const char *format, t_list **result)
{
	t_list		*add;
	int			len;

	while (*format)
	{
		if (*format == '%')
		{
			format++;
			len = error_check(format);
			if (!(add = make_node(format, len)))
			{
				ft_lstclear(result);
				return (0);
			}
			ft_lstadd_back(result, add);
			format += len - 1;
		}
		format++;
	}
	return (1);
}

int				ft_printf(const char *format, ...)
{
	t_list		*list;
	va_list		ap;

	va_start(ap, format);
	if (!make_list(format, &list))
		return (-1);
}
