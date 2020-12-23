/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taewakim <taewakim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/23 02:05:04 by taewakim          #+#    #+#             */
/*   Updated: 2020/12/23 15:51:52 by taewakim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

size_t		ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t		dest_count;
	size_t		src_count;
	size_t		result;

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
	result = src_count + (dest_count > size) ? size : dest_count;
	return (result);
}
