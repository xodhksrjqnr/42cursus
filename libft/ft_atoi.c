/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taewakim <taewakim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/23 01:08:35 by taewakim          #+#    #+#             */
/*   Updated: 2020/12/23 21:38:05 by taewakim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_atoi(const char *s)
{
	int		total;
	int		flag;

	while (*s == ' ' || *s == '\t')
		s++;
	flag = 0;
	if (*s == '-' || *s == '+')
	{
		if (*s == '-')
			flag = 1;
		s++;
	}
	if (!(*s >= '0' && *s <= '9'))
		return (0);
	total = 0;
	while (*s >= '0' && *s <= '9')
		total = total * 10 + *s++ - 48;
	if (flag == 1)
		total *= -1;
	return (total);
}
