/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taewakim <taewakim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/23 02:04:28 by taewakim          #+#    #+#             */
/*   Updated: 2020/12/25 20:05:17 by taewakim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memset(void *s, int c, size_t n)
{
	size_t			count;
	unsigned char	*tmp1;
	unsigned char	tmp2;

	tmp1 = (unsigned char *)s;
	tmp2 = (unsigned char)c;
	count = 0;
	while (count++ < n)
		*tmp1++ = tmp2;
	return (s);
}
