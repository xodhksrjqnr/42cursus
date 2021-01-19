/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_percent.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taewakim <taewakim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 15:33:19 by taewakim          #+#    #+#             */
/*   Updated: 2021/01/19 16:52:23 by taewakim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int		print_percent(t_flags cur, int *count, char *tmp)
{
	if (!*tmp)
	{
		write(1, "%", 1);
		*count += 1;
		return (1);
	}
	if (cur.minus)
		tmp[0] = '%';
	else
		tmp[cur.first - 1] = '%';
	while (*tmp)
	{
		write(1, tmp, 1);
		*count += 1;
	}
	return (1);
}
