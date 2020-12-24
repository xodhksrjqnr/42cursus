/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taewakim <taewakim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/23 02:05:15 by taewakim          #+#    #+#             */
/*   Updated: 2020/12/25 01:55:04 by taewakim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t		count;

	count = 0;
	while (count + 1 < size && *src)
	{
		*dest++ = *src++;
		count++;
	}
	if (count != 0)
		*dest = 0;
	while (*src++)
		count++;
	return (count);
}
