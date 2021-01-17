#include "ft_printf.h"
#include "./libft/libft.h"

static t_list	*newlist(void)
{
	t_list	*new;

	if (!(new = malloc(t_list)))
		return (0);
	ft_memset(new, 0, 9);
	new->first = -1;
	new->second = -1;
	new->next = 0;
	return (new);
}

static int		check_flags(const char *s, t_list *new, int div)
{
	const char	*save;

	save = s;
	if (*s == '-' && !div)
	{
		new->miner = '1';
		s++;
	}
	if (*s == '.' && div)
	{
		new->dot = '1';
		s++;
	}
	if (*s == '0')
	{
		new->zero = '1';
		s++;
	}
	if (*s == '*')
	{
		new->star = !div ? '1' : '2';
		s++;
	}
	return (s - save);
}

static int		check_nums(const char *s, t_list *new)
{
	int		count;

	count = 0;
	if (*s >= '0' && *s <= '9')
	{
		new->first = ft_atoi(s);
		while (*s >= '0' && *s <= '9')
		{
			s++;
			count++;
		}
	}
	return (count);
}

t_list			*make_parse(const char *s)
{
	t_list		*new;
	const char	*save;

	if (!(new = newlist()))
		return (0);
	save = s;
	s += check_flags(s, new, 0);
	s += check_nums(s, new);
	if (*s == '.')
	{
		s += check_flags(s, new, 1);
		s += check_nums(s, new);
	}
	if (err_check(s, new))
	{
		free(new);
		return (0);
	}
	new->type = *s;
	new->len = s - save;
	return (new);
}
