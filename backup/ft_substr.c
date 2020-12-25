/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taewakim <taewakim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/23 02:06:08 by taewakim          #+#    #+#             */
/*   Updated: 2020/12/23 14:05:39 by taewakim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_substr(char const *s, unsigned int start, unsigned int len)
{
	char			*result;
	char			*tmp;
	unsigned int	count;

	if (!(result = (char *)malloc(sizeof(char) * len + 1)))
		return (0);
	count = 0;
	while (count < start)
	{
		count++;
		s++;
	}
	tmp = result;
	while (count < len)
	{
		*tmp++ = *s++;
		count++;
	}
	*tmp = 0;
	return (result);
}
