/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taewakim <taewakim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/23 02:05:04 by taewakim          #+#    #+#             */
/*   Updated: 2020/12/24 23:47:42 by taewakim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

size_t		ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t		dest_count;
	size_t		src_count;
	size_t		result;

	if (size == 0)
		return (0);
	dest_count = 0;
	while (*dest)
	{
		dest++;
		dest_count++;
	}
	src_count = 0;
	while (src_count + dest_count + 1 < size && *src)
	{
		*dest++ = *src++;
		src_count++;
	}
	*dest = 0;
	result = (dest_count > size) ? size : dest_count;
	result += src_count;
	return (result);
}
