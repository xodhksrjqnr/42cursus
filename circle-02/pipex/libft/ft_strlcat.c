/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taewan <taewan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/23 02:05:04 by taewakim          #+#    #+#             */
/*   Updated: 2021/08/19 04:50:47 by taewan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t		d_count;
	size_t		s_count;
	size_t		count;

	d_count = ft_strlen(dest);
	s_count = ft_strlen(src);
	if (d_count >= size)
		return (size + s_count);
	count = 0;
	dest += d_count;
	while (count++ + d_count + 1 < size && *src)
		*dest++ = *src++;
	*dest = 0;
	return (s_count + d_count);
}
