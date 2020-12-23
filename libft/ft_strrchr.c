/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taewakim <taewakim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/23 02:05:57 by taewakim          #+#    #+#             */
/*   Updated: 2020/12/23 16:05:27 by taewakim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrchr(const char *s, int c)
{
	char	*location;

	location = NULL;
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
