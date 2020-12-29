/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taewakim <taewakim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/23 02:05:57 by taewakim          #+#    #+#             */
/*   Updated: 2020/12/29 10:14:32 by taewakim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*location;

	location = 0;
	while (*s)
	{
		if (*s == c)
			location = (char *)s;
		s++;
	}
	if (c == 0)
		return ((char *)s);
	return (location);
}
