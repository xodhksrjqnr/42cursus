/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taewakim <taewakim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/23 02:03:57 by taewakim          #+#    #+#             */
/*   Updated: 2020/12/24 21:47:41 by taewakim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*tmp1;
	unsigned char	*tmp2;
	size_t			count;

	tmp1 = (unsigned char *)s1;
	tmp2 = (unsigned char *)s2;
	if (n == 0)
		return (0);
	count = 0;
	while (count++ < n)
	{
		if (*tmp1 != *tmp2)
			break ;
		tmp1++;
		tmp2++;
	}
	return ((int)(*tmp1 - *tmp2));
}
