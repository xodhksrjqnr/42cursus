/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taewakim <taewakim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/27 05:12:26 by taewakim          #+#    #+#             */
/*   Updated: 2020/12/27 05:12:33 by taewakim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int		num_len(int n)
{
	int		count;

	count = 1;
	if (n < 0)
		count++;
	while (n /= 10)
		count++;
	return (count);
}

char			*ft_itoa(int n)
{	
	char	*result;
	int		len;
	int		flag;

	flag = (n < 0) ? -1 : 1;
	len = num_len(n);
	if (!(result = (char *)malloc(len + 1)))
		return (0);
	result[len--] = 0;
	result[len--] = (n < 0) ? ((n % 10) * -1) + 48
		: n % 10 + 48;
	n /= 10;
	n *= flag;
	while (len >= 0)
	{
		result[len--] = n % 10 + 48;
		n /= 10;
	}
	if (flag == -1)
		result[0] = '-';
	return (result);
}
