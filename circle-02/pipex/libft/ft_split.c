/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taewan <taewan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/27 05:12:38 by taewakim          #+#    #+#             */
/*   Updated: 2021/08/19 05:42:27 by taewan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	check_next(char const *s, char c, int flag)
{
	int	count;

	count = 0;
	if (flag)
	{
		while (*s == c && *s)
		{
			s++;
			count++;
		}
		return (count);
	}
	while (*s != c && *s)
	{
		s++;
		count++;
	}
	return (count);
}

static int	check_len(char const *s, char c)
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

static char	**free_clear(char **target, int count)
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

char	**ft_split(char const *s, char c)
{
	char	**result;
	char	*start;
	int		count;

	if (!s)
		return (0);
	s += check_next(s, c, 1);
	result = (char **)malloc((check_len(s, c) + 1) * sizeof(char *));
	if (!result)
		return (0);
	count = 0;
	while (*s)
	{
		start = (char *)s;
		s += check_next(s, c, 0);
		*(result + count) = (char *)malloc(s - start + 1);
		if (!*(result + count))
			return (free_clear(result, count));
		ft_strlcpy(*(result + count), start, s - start + 1);
		count++;
		s += check_next(s, c, 1);
	}
	*(result + count) = 0;
	return (result);
}
