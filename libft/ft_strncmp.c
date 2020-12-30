/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taewakim <taewakim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/23 02:05:37 by taewakim          #+#    #+#             */
/*   Updated: 2020/12/30 20:33:19 by taewakim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			count;

	if (n == 0 || ((s1 == s2) && s1 && s2))
		return (0);
	count = 0;
	while ((*s1 || *s2) && count < n)
	{
		if (*s1 != *s2)
			return (*((unsigned char *)s1) - *((unsigned char *)s2));
		s1++;
		s2++;
		count++;
	}
	return (0);
}
