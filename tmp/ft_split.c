/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taewakim <taewakim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/27 05:12:38 by taewakim          #+#    #+#             */
/*   Updated: 2020/12/29 20:22:16 by taewakim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		check_len(char const *s, char c)
{
	int		len;

	while (*s == c)
		s++;
	len = 0;
	while (*s)
	{
		len++;
		while (*s != c && *s)
			s++;
		while (*s == c)
			s++;
	}
	return (len);
}

static int		free_clear(char **target)
{
	int		count;

	count = 0;
	while (*(target + count))
		free(*(target + count++));
	free(target);
	return (0);
}

char			**ft_split(char const *s, char c)
{
	char	**result;
	char	*start;
	int		count;

	if (!s)
		return (0);
	if (!(result = (char **)malloc((check_len(s, c) + 1) * sizeof(char *))))
		return (0);
	count = 0;
	while (s*)
	{
		start = s;
		while (*s != c && *s)
			s++;
		if (!(*(result + count++) = (char *)malloc(s - save + 1)))
			return (free_clear(result));
		ft_strlcpy(*(result + count), start, s - save + 1);
		while (*s == c)
			s++;
	}
	*(result + count) = 0;
	return (result);
}
