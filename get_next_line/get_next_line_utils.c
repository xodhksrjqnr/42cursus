/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taewakim <taewakim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/31 12:15:10 by taewakim          #+#    #+#             */
/*   Updated: 2021/01/02 15:14:38 by taewakim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	count;

	count = 0;
	while (*s++)
		count++;
	return (count);
}

char	*ft_strchr(const char *s)
{
	while (*s)
	{
		if (*s == '\n')
			return (s);
		s++;
	}
	return (s);
}

char	*ft_strdup(const char *s, size_t len)
{
	char	*result;
	size_t	count;
	
	if (!s)
		return (0);
	if (!(result = (char *)malloc(len + 1)))
		return (0);
	result[len] = 0;
	count = 0;
	while (*s)
		*(result + count++) = *s++;
	return (result);
}

char	*ft_strjoin(const char *s1, const char *s2)
{
	size_t	size;
	char	*result;
	char	*tmp;

	if (!s1 || !s2)
		return (0);
	size = ft_strlen(s1) + ft_strlen(s2) + 1;
	if (!(result = (char *)malloc(size)))
		return (0);
	result[size - 1] = 0;
	tmp = result;
	while (*s1)
		*tmp++ = *s1++;
	while (*s2)
		*tmp++ = *s2++;
	return (result);
}
