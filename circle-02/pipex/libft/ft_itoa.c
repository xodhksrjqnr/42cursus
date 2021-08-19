/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taewan <taewan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/27 05:12:26 by taewakim          #+#    #+#             */
/*   Updated: 2021/08/19 04:47:03 by taewan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	num_len(int n)
{
	int		count;

	count = 1;
	if (n < 0)
		count++;
	while (n)
	{
		n /= 10;
		count++;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	char			*result;
	int				len;
	int				flag;
	unsigned int	num;

	len = num_len(n);
	result = (char *)malloc(len + 1);
	if (!result)
		return (0);
	result[len--] = 0;
	flag = 0;
	if (n < 0)
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
