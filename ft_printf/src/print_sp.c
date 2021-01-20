/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_s.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taewakim <taewakim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 15:33:01 by taewakim          #+#    #+#             */
/*   Updated: 2021/01/20 13:48:44 by taewakim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static char		*convert_adr(unsigned long long p)
{
	unsigned long long	stand;
	char				*result;
	int					count;
	int					num;

	count = 0;
	stand = 0xf00000000000;
	while (!(stand & p))
	{
		stand = stand >> 4;
		count++;
	}
	if (!(result = malloc(12 - count + 3)))
		return (0);
	result[14 - count] = 0;
	result[0] = '0';
	result[1] = 'x';
	while (count < 12)
	{
		num = (stand & p) >> (11 - count) * 4;
		result[count++ + 2] = "0123456789abcdef"[num];
		stand = stand >> 4;
	}
	return (result);
}

static char		*check_dot(t_flags cur, char *s)
{
	int		count;

	count = 0;
	if (cur.dot)
	{
		count += cur.second;
		while (*(s + count))
		{
			*(s + count) = 0;
			count++;
		}
	}
	return (s);
}

static int		print_result(t_flags cur, char *str, int *count, char *tmp)
{
	int		len;
	char	*save;

	len = ft_strlen(str);
	if (len >= cur.first)
	{
		ft_putstr(str);
		free(str);
		*count += len;
		return (1);
	}
	if (cur.zero)
		ft_memset(tmp, '0', cur.first);
	save = tmp;
	tmp = (cur.minus) ? tmp : tmp + cur.first - len;
	while (*str)
		*tmp ++ = *str++;
	free(str - len);
	ft_putstr(save);
	*count += cur.first;
	return (1);
}

int				print_sp(t_flags cur, char *s, int *count, char *tmp)
{
	char	*str;

	if (cur.type == 's')
	{
		if (!(str = (!s) ? ft_strdup("(null)") : ft_strdup(s)))
			return (0);
	}
	else
		if (!(str = !s ? ft_strdup("0x0") : convert_adr((unsigned long long)s)))
			return (0);
	str = check_dot(cur, str);
	return (print_result(cur, str, count, tmp));
}
