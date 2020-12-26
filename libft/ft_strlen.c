/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taewakim <taewakim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/23 02:05:26 by taewakim          #+#    #+#             */
/*   Updated: 2020/12/27 05:53:07 by taewakim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

size_t		ft_strlen(const char *s)
{
	size_t		size;

	size = 0;
	while (*s++)
		size++;
	return (size);
}
