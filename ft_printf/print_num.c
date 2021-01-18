#include "ft_printf.h"

static char		*check_dot(t_flags cur, char *n)
{
	char	*tmp;
	int		len;

	len = ft_strlen(n);
	if (cur.dot && (cur.second > len))
	{
		if (!(tmp = malloc(cur.second - len + 1)))
			return (0);
		tmp[cur.second - len] = 0;
		ft_memset(tmp, '0', cur.second - len - 1);
		return (ft_strjoin(tmp, n));
	}
	return (n);
}

int				print_num(t_flags cur, int n, int *count, char *tmp)
{
	char	*num;
	char	*save;
	int		len;

	num = (cur.type == 'u') ? ft_itoa((unsigned int)n) : ft_itoa(n);
	if (!(num = check_dot(cur, num)))
		return (0);
	len = ft_strlen(num);
	if (len >= cur.first)
	{
		while (*num)
			write(1, num++, 1);
		*count += len;
		return (1);
	}
	save = tmp;
	tmp = (cur.minus) ? tmp : tmp + cur.first - len;
	while (*num)
		*tmp++ = *num++;
	while (*save)
		write(1, save, 1);
	*count += cur.first;
	return (1);
}
