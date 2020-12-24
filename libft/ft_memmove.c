/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taewakim <taewakim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/23 02:04:19 by taewakim          #+#    #+#             */
/*   Updated: 2020/12/24 18:06:03 by taewakim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*tmp;
	size_t			count;

	if (!dest && !src)
		return (0);
	count = 0;
	tmp = dest;
	if (dest < src)
	{
		while (count < n)
		{
			*(tmp + count) = *((unsigned char *)src + count);
			count++;
		}
		return (dest);
	}
	while (count++ < n)
		*(tmp + n - count) = *((unsigned char *)src + n - count);
	return (dest);
}
