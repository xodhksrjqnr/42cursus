/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taewakim <taewakim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/23 02:04:28 by taewakim          #+#    #+#             */
/*   Updated: 2020/12/25 22:54:35 by taewakim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memset(void *s, int c, size_t n)
{
	size_t			count;
	
	count = 0x00;
	while (count < n)
	{
		*((unsigned char *)s) = (unsigned char)c;
		s += 0x01;
		count += 0x01;
	}
	return (s);
}
