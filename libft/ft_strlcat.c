/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taewakim <taewakim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/23 02:05:04 by taewakim          #+#    #+#             */
/*   Updated: 2020/12/23 02:05:09 by taewakim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

size_t		ft_strlcat(char *dest, const char *src, size_t size)
{
	unsigned int	dest_count;
	unsigned int	src_count;
	unsigned int	count;

	dest_count = 0;
	src_count = 0;
	while (*dest++)
		dest_count++;
	if (size == 0 || size > dest_count)
		return (0);
	while (*(src + src_count))
		src_count++;
	if (dest_count > size)
		return (src_count + size);
	count = 0;
	while (count++ + dest_count + 1 < size && *src)
		*dest++ = *src++;
	*src = 0;
	return (src_count + dest_count);
}
