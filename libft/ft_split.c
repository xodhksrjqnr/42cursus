/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taewakim <taewakim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/27 05:12:38 by taewakim          #+#    #+#             */
/*   Updated: 2020/12/30 23:56:52 by taewakim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		check_len(char const *s, char c)
{
	int		len;

	len = 0;
	while (*s)
	{
		len++;
		while (*s != c && *s)
			s++;
		while (*s == c && *s)
			s++;
	}
	return (len);
}

static char		**free_clear(char **target, int count)
{
	while (--count > 0)
	{
		ft_bzero(*(target + count), sizeof(*(target + count)));
		free(*(target + count));
	}
	free(target);
	target = 0;
	return (0);
}

char			**ft_split(char const *s, char c)
{
	char	**result;
	char	*start;
	int		count;

	if (!s)
		return (0);
	while (*s == c && *s)
		s++;
	if (!(result = (char **)malloc((check_len(s, c) + 1) * sizeof(char *))))
		return (0);
	count = 0;
	while (*s)
	{
		start = (char *)s;
		while (*s != c && *s)
			s++;
		if (!(*(result + count) = (char *)malloc(s - start + 1)))
			return (free_clear(result, count));
		ft_strlcpy(*(result + count), start, s - start + 1);
		count++;
		while (*s == c && *s)
			s++;
	}
	*(result + count) = 0;
	return (result);
}
