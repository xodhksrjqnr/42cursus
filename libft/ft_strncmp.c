/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taewakim <taewakim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/23 02:05:37 by taewakim          #+#    #+#             */
/*   Updated: 2020/12/24 22:50:06 by taewakim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			count;

	if (n == 0)
		return (0);
	count = 0;
	while (*(s1 + count) && *(s2 + count) && count < n
			&& *(s1 + count) == *(s2 + count))
		count++;
	return (*(s1 + count) - *(s2 + count));
}
