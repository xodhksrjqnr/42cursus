/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taewakim <taewakim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/23 02:05:47 by taewakim          #+#    #+#             */
/*   Updated: 2020/12/23 02:05:52 by taewakim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

char	*ft_strnstr(const char *s1, const char *s2, size_t len)
{
	size_t		count;
	size_t		count2;

	if (s2 == 0)
		return ((char *)s1);
	count = 0;
	while (*s1 && count < len)
	{
		if (*s1 == *s2)
		{
			count2 = 0;
			while (count2 + count < len && *(s1 + count2) && *(s2 + count2))
			{
				if (*(s1 + count2) != *(s2 + count2))
					break ;
				count2++;
			}
			if (*(s1 + count2) == 0)
				return ((char *)s1);
		}
		count++;
		s1++;
	}
	return (0);
}
