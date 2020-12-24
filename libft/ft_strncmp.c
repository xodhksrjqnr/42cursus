/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taewakim <taewakim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/23 02:05:37 by taewakim          #+#    #+#             */
/*   Updated: 2020/12/25 01:11:43 by taewakim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			count;
	unsigned char	*tmp1;
	unsigned char	*tmp2;

	if (n == 0 || (s1 == s2))
		return (0);
	tmp1 = (unsigned char *)s1;
	tmp2 = (unsigned char *)s2;
	count = 0;
	while (*(tmp1 + count) && *(tmp2 + count) && count < n
			&& *(tmp1 + count) == *(tmp2 + count))
		count++;
	return (*(tmp1 + count) - *(tmp2 + count));
}
