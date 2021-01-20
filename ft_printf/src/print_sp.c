/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_s.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taewakim <taewakim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 15:33:01 by taewakim          #+#    #+#             */
/*   Updated: 2021/01/20 17:51:23 by taewakim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static char		*convert_adr(unsigned long long p)
{
	unsigned long long	stand;
	char				*result;
	int					count;
	int					count2;
	int					num;

	count = 0;
	stand = 0xf00000000000;
	while (!(stand & p) && count < 12)
	{
		stand = stand >> 4;
		count++;
	}
	count = (count == 12) ? 1 : 12 - count;
	if (!(result = malloc(count + 1)))
		return (0);
	result[count] = 0;
	count2 = 0;
	while (count2 < count)
	{
		num = (stand & p) >> (count - count2 - 1) * 4;
		result[count2++] = "0123456789abcdef"[num];
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
	if (cur.zero && cur.type == 's')
		ft_memset(tmp, '0', cur.first);
	save = tmp;
	tmp = (cur.minus) ? tmp : tmp + cur.first - len;
	while (*str)
		*tmp++ = *str++;
	free(str - len);
	ft_putstr(save);
	*count += cur.first;
	return (1);
}

int				print_sp(t_flags cur, char *s, int *count, char *tmp)
{
	char	*str;
	char	*tmp2;
	int		len;

	if (cur.type == 's')
	{
		if (!(str = (!s) ? ft_strdup("(null)") : ft_strdup(s)))
			return (0);
		str = check_dot(cur, str);
		return (print_result(cur, str, count, tmp));
	}
	str = convert_adr((unsigned long long)s);
	if ((len = ft_strlen(str)) < cur.second)
	{
		if (!(tmp2 = malloc(cur.second - len + 1)))
			return (0);
		ft_memset(tmp2, '0', cur.second - len);
		str = ft_strjoin(tmp2, str);
	}
	if (str[0] != '0' && cur.dot)
		cur.dot = 0;
	str = check_dot(cur, str);
	if (!(str = ft_strjoin(ft_strdup("0x"), str)))
		return (0);
	return (print_result(cur, str, count, tmp));
}
