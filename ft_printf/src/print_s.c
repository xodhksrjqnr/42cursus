/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_s.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taewakim <taewakim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 15:33:01 by taewakim          #+#    #+#             */
/*   Updated: 2021/01/19 20:52:11 by taewakim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

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

int				print_s(t_flags cur, char *s, int *count, char *tmp)
{
	int		len;
	char	*save;
	char	*str;

	if (!(str = (!s) ? ft_strdup("(null)") : ft_strdup(s)))
		return (0);
	str = check_dot(cur, str);
	len = ft_strlen(str);
	if (len >= cur.first)
	{
		while (*str)
			write(1, str++, 1);
		*count += len;
		free(str - len);
		return (1);
	}
	save = tmp;
	tmp = (cur.minus) ? tmp : tmp + cur.first - len;
	while (*str)
		*tmp++ = *str++;
	free(str - len);
	while (*save)
		write(1, save++, 1);
	*count += cur.first;
	return (1);
}
