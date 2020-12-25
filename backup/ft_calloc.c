/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taewakim <taewakim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/23 02:02:00 by taewakim          #+#    #+#             */
/*   Updated: 2020/12/24 20:11:10 by taewakim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*result;
	void	*tmp;
	size_t	count;

	if (!(result = malloc(nmemb * size)))
		return (0);
	count = 0;
	tmp = result;
	while (count < nmemb * size)
	{
		*((unsigned char *)tmp + count) = 0;
		count++;
	}
	return (result);
}
