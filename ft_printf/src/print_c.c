/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_c.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taewakim <taewakim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 15:32:52 by taewakim          #+#    #+#             */
/*   Updated: 2021/01/19 16:49:26 by taewakim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int		print_c(t_flags cur, char c, int *count, char *tmp)
{
	if (!*tmp)
	{
		write(1, &c, 1);
		*count += 1;
		return (1);
	}
	if (cur.minus)
		tmp[0] = c;
	else
		tmp[cur.first - 1] = c;
	while (*tmp)
	{
		write(1, tmp, 1);
		*count += 1;
	}
	return (1);
}
