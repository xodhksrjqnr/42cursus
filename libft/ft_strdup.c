/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taewakim <taewakim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/23 02:04:53 by taewakim          #+#    #+#             */
/*   Updated: 2020/12/26 18:26:28 by taewakim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strdup(const char *s)
{
	char	*result;
	char	*tmp;
	int		size;

	size = 0;
	while (*(s + size))
		size++;
	if (!(result = (char *)malloc(sizeof(char) * size + 1)))
		return (0);
	tmp = result;
	while (*s)
		*tmp++ = *s++;
	*tmp = 0;
	return (result);
}
