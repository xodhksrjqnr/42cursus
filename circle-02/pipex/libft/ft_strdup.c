/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taewan <taewan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/23 02:04:53 by taewakim          #+#    #+#             */
/*   Updated: 2021/08/19 04:50:23 by taewan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*result;
	char	*tmp;

	result = (char *)malloc((ft_strlen(s) + 1));
	if (!result)
		return (0);
	tmp = result;
	while (*s)
		*tmp++ = *s++;
	*tmp = 0;
	return (result);
}
