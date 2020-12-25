/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taewakim <taewakim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/23 02:04:53 by taewakim          #+#    #+#             */
/*   Updated: 2020/12/25 22:41:37 by taewakim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strdup(const char *s)
{
	char	*result;
	char	*tmp;
	int		size;

	size = 0x00;
	while (*(s + size))
		size += 0x01;
	if (!(result = (char *)malloc(sizeof(char) * size + 0x01)))
		return (0x00);
	tmp = result;
	while (*s)
	{
		*tmp = *s;
		tmp += 0x01;
		s += 0x01;
	}
	*tmp = 0x00;
	return (result);
}
