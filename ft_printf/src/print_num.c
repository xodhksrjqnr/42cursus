/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_num.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taewakim <taewakim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 15:33:10 by taewakim          #+#    #+#             */
/*   Updated: 2021/01/20 13:53:53 by taewakim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static char		*check_dot(t_flags cur, char *n)
{
	char	*tmp;
	int		len;

	len = ft_strlen(n);
	if (n[0] == '-' && cur.dot != 2)
		len -= 1;
	if (cur.dot && (cur.second > len))
	{
		if (!(tmp = malloc(cur.second - len + 1)))
			return (0);
		tmp[cur.second - len] = 0;
		ft_memset(tmp, '0', cur.second - len);
		if (n[0] == '-')
		{
			n[0] = '0';
			tmp[0] = '-';
		}
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
	while (8 - count)
	{
		result = (stand & num) >> ((7 - count++) * 4);
		*tmp++ = "0123456789abcdef"[result] -
			((type == 'X' && result >= 10) ? 32 : 0);
		stand = stand >> 4;
	}
	return (save);
}

static int		print_result(t_flags cur, char *num, int *count, char *tmp)
{
	char	*save;
	int		len;

	len = ft_strlen(num);
	if (len >= cur.first)
	{
		ft_putstr(num);
		*count += len;
		free(num);
		return (1);
	}
	save = tmp;
	tmp = (cur.minus) ? tmp : tmp + cur.first - len;
	if (cur.zero && tmp != save)
		ft_memset(save, '0', cur.first - len);
	while (*num)
		*tmp++ = *num++;
	free(num - len);
	ft_putstr(save);
	*count += cur.first;
	return (1);
}

int				print_num(t_flags cur, int n, int *count, char *tmp)
{
	char	*num;
	int		flag;

	if (cur.type == 'd' || cur.type == 'i' || cur.type == 'u')
	{
		flag = 0;
		flag = (cur.type == 'u') ? 1 : 0;
		num = (!cur.second && !n) ? ft_strdup("") : ft_itoa(n, flag);
		if (!num)
			return (0);
	}
	else
	{
		if (!n && cur.dot)
			num = ft_strdup("");
		else
			num = n ? convert_hex((unsigned int)n, cur.type) : ft_strdup("0");
		if (!num)
			return (0);
	}
	if (!num)
		return (0);
	if (!(num = check_dot(cur, num)))
		return (0);
	return (print_result(cur, num, count, tmp));
}
