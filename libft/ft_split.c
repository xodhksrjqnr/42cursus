/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taewakim <taewakim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/27 05:12:38 by taewakim          #+#    #+#             */
/*   Updated: 2020/12/27 19:47:26 by taewakim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static char		*new_arr(char const *s, char c)
{
	char	*result;
	int		len;
	int		count;

	len = 0;
	while (*(s + len) != c && *(s + len))
		len++;
	if (!(result = (char *)malloc(len + 1)))
		return (0);
	result[len] = 0;
	count = 0;
	while (count < len)
	{
		*(result + count) = *(s + count);
		count++;
	}
	return (result);
}

static int		next_location(char const *s, char c)
{
	int		len;

	len = 0;
	while (*(s + len) != c && *(s + len))
		len++;
	while (*(s + len) == c)
		len++;
	return (len);
}

static int		check_len(char const *s, char c)
{
	int		len;

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

char			**ft_split(char const *s, char c)
{
	char	**result;
	int		len;
	int		count;

	if (!s)
		return (0);
	while (*s == c)
		s++;
	len = check_len(s, c);
	if (!(result = (char **)malloc((len + 1) * sizeof(char *))))
		return (0);
	count = 0;
	while (count < len)
	{
		if (!(*(result + count++) = new_arr(s, c)))
			return (0);
		s += next_location(s, c);
	}
	*(result + count) = 0;
	return (result);
}
