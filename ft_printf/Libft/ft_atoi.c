/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taewakim <taewakim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/23 01:08:35 by taewakim          #+#    #+#             */
/*   Updated: 2020/12/29 06:47:33 by taewakim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_atoi(const char *s)
{
	unsigned long long	total;
	unsigned long long	max;
	int					flag;

	max = 9223372036854775807;
	while (*s == ' ' || (*s >= 9 && *s <= 13))
		s++;
	flag = 0;
	if (*s == '-' || *s == '+')
	{
		if (*s == '-')
			flag = 1;
		s++;
	}
	total = 0;
	while (*s >= '0' && *s <= '9')
		total = total * 10 + *s++ - 48;
	if (total > max && flag == 0)
		return (-1);
	else if (total > max && flag == 1)
		return (0);
	if (flag == 1)
		total *= -1;
	return ((int)total);
}
