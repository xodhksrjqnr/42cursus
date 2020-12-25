/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taewakim <taewakim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/23 02:05:47 by taewakim          #+#    #+#             */
/*   Updated: 2020/12/25 19:58:35 by taewakim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		check(const char *s1, const char *s2, size_t len)
{
	size_t		tmp;

	tmp = 0;
	while (*(s1 + tmp) && *(s2 + tmp))
		tmp++;
	if (*(s1 + tmp) == 0 && *(s2 + tmp) != 0)
		return (0);
	if (tmp > len)
		return (0);
	return (tmp);
}

char	*ft_strnstr(const char *s1, const char *s2, size_t len)
{
	size_t		s2_len;
	size_t		count;

	if (*s2 == 0)
		return ((char *)s1);
	if (!(s2_len = check(s1, s2, len)) || len == 0)
		return (0);
	count = 0;
	while (*s1 && count + s2_len <= len)
	{
		if (*s1 == *s2)
			if (ft_memcmp(s1, s2, s2_len) == 0)
				return ((char *)s1);
		s1++;
		count++;
	}
	return (0);
}
