#include "ft_printf.h"
#include "./libft/libft.h"

static t_list	*parse(const char *s)
{
	t_list	*result;
	t_list	*new;

	while (*s)
	{
		if (*s == '%')
		{
			if (!(new = make_parse(++s)))
				return (0);
			s += new->len;
			ft_lstadd_back(&result, new);
		}
		s++;
	}
	return (result);
}

static int		print_format(t_list *list, va_list ap)
{
	int		count;
	char	*tmp;

	if (list->type == '%')
	{
		write(1, "%", 1);
		return (1);
	}
	if (!(!list->star && !list->first))
		list->first = !list->star ? list->first : va_arg(ap, int);
	if (!(tmp = malloc(list->first + 1)))
		return (0);
	tmp[list->first] = 0;
	ft_memset(tmp, ' ', list->first - 1);
	if (list->type == 'c' || list->type == 's')
		count = print_str(list, ap, tmp);
	else if (list->type == 'p')
		count = print_adr(list, ap, tmp);
	else if (list->type == 'x' || list->type == 'X')
		count = print_hex(list, ap, tmp);
	else if (list->type == 'd' || list->type == 'i')
		count = print_num(list, ap, tmp);
	free(tmp);
	return (count);
}

int				ft_printf(const char *s, ...)
{
	va_list		ap;
	t_list		*list;
	t_list		*save;
	int			count;

	if (!(list = parse(s)))
		return (-1);
	va_start(ap, s);
	count = 0;
	save = list;
	while (*s)
	{
		if (*s == '%')
		{
			count += print_format(list, ap);
			s += list->len;
			list = list->next;
		}
		else
			write(1, s++, 1);
		count++;
	}
	va_end(ap);
	return (count);
}
