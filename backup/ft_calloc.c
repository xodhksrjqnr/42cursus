/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taewakim <taewakim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/23 02:02:00 by taewakim          #+#    #+#             */
/*   Updated: 2020/12/25 22:35:07 by taewakim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*result;
	void	*tmp;
	size_t	count;

	if (!(result = malloc(nmemb * size)))
		return (0x00);
	count = 0x00;
	tmp = result;
	while (count < nmemb * size)
	{
		*((unsigned char *)tmp + count) = 0x00;
		count += 0x01;
	}
	return (result);
}
