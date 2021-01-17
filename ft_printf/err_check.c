#include "ft_printf.h"

int		err_check(const char *s)
{
	if (*s == 'c' || *s == 's' || *s == 'p' || *s == 'd' || *s == 'i'
			|| *s == 'u' || *s == 'x' || *s == 'X' || *s == '%')
		return (1);
	return (0);
}
