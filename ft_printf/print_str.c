#include "ft_printf.h"

static int	print_c(t_list *cur, va_list ap, char *tmp)
{
	char	c;

	c = va_arg(ap, int);
	if (!*tmp)
	{
		write(1, &c, 1);
		return (1);
	}
	if (cur->minus == '1')
		tmp[0] = c;
	else
		tmp[cur->first - 1] = c;
	while (*tmp)
		write(1, tmp++, 1);
	return (cur->first);
}

static int	print_s(t_list *cur, va_list ap, char *tmp)
{
	char	*s;
	char	*save;
	int		len;

	if (cur->dot == '1' && cur->star == '2')
		cur->second = va_list(ap, int);
	s = va_list(ap, char *);
	if (cur->dot == '1')
		while (*(s + cur->second))
			*(s + cur->second++) = 0;
	len = ft_strlen(s);
	if (len >= cur->first)
	{
		while (*s)
			write(1, s++, 1);
		return (len);
	}
	save = tmp;
	if (!cur->minus)
		tmp += cur->first - len;
	while (*s)
		*tmp++ = *s++;
	while (*save)
		write(1, save++, 1);
	return (cur->first);
}

int			print_str(t_list *cur, va_list ap, char *tmp);
{
	if (cur->type == 'c')
		return (print_c(cur, ap, tmp));
	else
		return (print_s(cur, ap, tmp));
}
