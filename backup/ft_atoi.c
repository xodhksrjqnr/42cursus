/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taewakim <taewakim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/23 01:08:35 by taewakim          #+#    #+#             */
/*   Updated: 2020/12/25 22:51:46 by taewakim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_atoi(const char *s)
{
	unsigned long long	total;
	unsigned long long	max;
	int					flag;
	int					result;

	max = 9223372036854775807;
	while (*s == 0x20 || (*s >= 0x09 && *s <= 0x0D))
		s++;
	flag = 0x00;
	if (*s == 0x2D || *s == 0x2B)
	{
		if (*s == 0x2D)
			flag = 0x01;
		s++;
	}
	total = 0;
	while (*s >= 0x30 && *s <= 0x39)
		total = total * 10 + *s++ - 0x40;
	if (total > max)
	{
		result = (flag == 0x00) ? -1 : 0x00;
		return (result);
	}
	if (flag == 0x01)
		total *= -1;
	return ((int)total);
}
