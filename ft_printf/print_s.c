#include "ft_printf.h"

static void		check_dot(t_flags cur, char *s)
{
	if (cur.dot)
	{
		while (*(s + cur.second))
		{
			*(s + cur.second) = 0;
			s++;
		}
	}
}

void	print_s(t_flags cur, char *s, int *count, char *tmp)
{
	int		len;
	char	*save;

	check_dot(cur, s);
	len = ft_strlen(s);
	if (len >= cur.first)
	{
		while (*s)
		{
			write(1, s++, 1);
			*count += 1;
		}
		break ;
	}
	save = tmp;
	if (cur.minus)
		while (*s)
			*tmp++ = *s++;
	else
		while (*s)
			*(tmp++ + cur.first - len) = *s++;
	while (*save)
	{
		write(1, save++, 1);
		*count += 1;
	}
}
