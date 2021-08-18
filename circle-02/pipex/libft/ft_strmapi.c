/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taewakim <taewakim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/27 05:12:15 by taewakim          #+#    #+#             */
/*   Updated: 2020/12/29 10:48:27 by taewakim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t		len;
	size_t		count;
	char		*result;

	if (!s)
		return (0);
	len = ft_strlen(s);
	if (!(result = (char *)malloc(len + 1)))
		return (0);
	result[len] = 0;
	count = 0;
	while (count < len)
	{
		*(result + count) = f(count, *(s + count));
		count++;
	}
	return (result);
}
