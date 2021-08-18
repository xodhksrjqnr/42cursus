/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taewakim <taewakim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/27 05:12:26 by taewakim          #+#    #+#             */
/*   Updated: 2021/01/20 00:04:21 by taewakim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		num_len(int n, int div)
{
	int				count;
	unsigned int	num;

	count = 1;
	if (!div)
	{
		if (n < 0)
			count++;
		while (n /= 10)
			count++;
	}
	else
	{
		num = n;
		while (num /= 10)
			count++;
	}
	return (count);
}

char			*ft_itoa(int n, int div)
{
	char			*result;
	int				len;
	int				flag;
	unsigned int	num;

	len = num_len(n, div);
	if (!(result = (char *)malloc(len + 1)))
		return (0);
	result[len--] = 0;
	flag = 0;
	if (n < 0 && !div)
	{
		n *= -1;
		flag = 1;
	}
	num = n;
	while (len >= 0)
	{
		result[len--] = num % 10 + 48;
		num /= 10;
	}
	if (flag == 1)
		result[0] = '-';
	return (result);
}
