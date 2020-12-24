/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taewakim <taewakim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/23 02:05:47 by taewakim          #+#    #+#             */
/*   Updated: 2020/12/24 21:40:54 by taewakim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

char	*ft_strnstr(const char *s1, const char *s2, size_t len)
{
	size_t		count;
	size_t		count2;

	if (*s2 == 0)
		return ((char *)s1);
	else if (*s1 == 0 || len == 0)
		return (0);
	count = 0;
	while (*s1 && count < len)
	{
		if (*s1 == *s2)
		{
			count2 = 0;
			while (*(s1 + count2) == *(s2 + count2) && *(s1 + count2)
					&& *(s2 + count2))
				count2++;
			if (*(s2 + count2) == 0 && count + count2 < len)
				return ((char *)s1);
		}
		count++;
		s1++;
	}
	return (0);
}
