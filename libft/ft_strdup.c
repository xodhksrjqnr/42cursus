/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taewakim <taewakim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/23 02:04:53 by taewakim          #+#    #+#             */
/*   Updated: 2020/12/29 10:08:14 by taewakim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*result;
	char	*tmp;

	if (!(result = (char *)malloc((ft_strlen(s) + 1))))
		return (0);
	tmp = result;
	while (*s)
		*tmp++ = *s++;
	*tmp = 0;
	return (result);
}
