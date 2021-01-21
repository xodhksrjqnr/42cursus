/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taewakim <taewakim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/23 02:04:53 by taewakim          #+#    #+#             */
/*   Updated: 2021/01/21 15:57:07 by taewakim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(char *s)
{
	char	*result;
	char	*tmp;
	size_t	len;

	len = ft_strlen(s);
	if (!(result = (char *)malloc(len + 1)))
		return (0);
	ft_memset(result, 0, len + 1);
	tmp = result;
	while (*s)
		*tmp++ = *s++;
	return (result);
}
