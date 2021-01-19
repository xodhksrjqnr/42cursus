/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_s.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taewakim <taewakim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 15:33:01 by taewakim          #+#    #+#             */
/*   Updated: 2021/01/19 16:00:06 by taewakim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

int				print_s(t_flags cur, char *s, int *count, char *tmp)
{
	int		len;
	char	*save;

	check_dot(cur, s);
	len = ft_strlen(s);
	if (len >= cur.first)
	{
		while (*s)
			write(1, s++, 1);
		*count += len;
		return (1);
	}
	save = tmp;
	tmp = (cur.minus) ? tmp : tmp + cur.first - len;
	while (*s)
		*tmp++ = *s++;
	while (*save)
		write(1, save++, 1);
	*count += cur.first;
	return (1);
}
