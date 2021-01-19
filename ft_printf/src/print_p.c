/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_p.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taewakim <taewakim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 15:33:31 by taewakim          #+#    #+#             */
/*   Updated: 2021/01/20 00:43:15 by taewakim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static char		*convert_adr(unsigned long long p)
{
	unsigned long long	stand;
	char				*result;
	int					count;
	int					num;

	if (!(result = malloc(15)))
		return (0);
	result[14] = 0;
	result[0] = '0';
	result[1] = 'x';
	count = 0;
	stand = 0xf00000000000;
	while (count < 12)
	{
		num = (stand & p) >> (11 - count) * 4;
		result[count++ + 2] = "0123456789abcdef"[num];
		stand = stand >> 4;
	}
	return (result);
}

int				print_p(t_flags cur, char *p, int *count, char *tmp)
{
	char	*adr;
	char	*save;

	if (!(adr = convert_adr((unsigned long long)p)))
		return (0);
	if (cur.first <= 14)
	{
		ft_putstr(adr);
		free(adr);
		*count += 14;
		return (1);
	}
	save = tmp;
	if (!cur.minus)
		tmp += cur.first - 15;
	while (*adr)
		*tmp++ = *adr++;
	free(adr - 14);
	ft_putstr(save);
	*count += cur.first;
	return (1);
}
