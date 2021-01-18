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

static char		*convert_hex(unsigned int num, char type)
{
	unsigned int	stand;
	unsigned int	result;
	int				count;
	char			*tmp;
	char			*save;

	stand = 0xf0000000;
	count = 0;
	while (!(stand & num))
	{
		stand = stand >> 4;
		count++;
	}
	if (!(tmp = malloc(8 - count + 1)))
		return (0);
	tmp[8 - count] = 0;
	save = tmp;
	while ((result = stand & num))
	{
		result =  result >> ((7 - count++) * 4);
		*tmp++ = "0123456789abcdef"[result] -
			(type == 'x' && result >= 10) ? 0 : 32;
		stand = stand >> 4;
	}
	return (save);
}

static int		print_result(t_flags cur, char *num , int *count, char *tmp)
{
	char	*save;
	char	*save2;

	len = ft_strlen(num);
	if (len >= cur.first)
	{
		save = num;
		while (*num)
			write(1, num++, 1);
		free(save);
		*count += len;
		return (1);
	}
	save = tmp;
	tmp = (cur.minus) ? tmp : tmp + cur.first - len;
	save2 = num;
	while (*num)
		*tmp++ = *num++;
	while (*save)
		write(1, save, 1);
	*count += cur.first;
	free(save2);
	return (1);
}

int				print_num(t_flags cur, int n, int *count, char *tmp)
{
	char			*num;
	int				len;

	if (cur.type == 'd' || cur.type == 'i')
		num = ft_itoa(n);
	else if (cur.type == 'u')
		num = ft_itoa((unsigned int)n);
	else
		num = convert_hex((unsigned int)n, cur.type);
	if (!num)
		return (0);
	if (!(num = check_dot(cur, num)))
		return (0);
	return (print_result(cur, num, count, tmp));
}
