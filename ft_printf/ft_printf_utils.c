/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taewakim <taewakim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 15:33:40 by taewakim          #+#    #+#             */
/*   Updated: 2021/01/20 18:27:16 by taewakim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		combi_set(t_flags *cur)
{
	if (cur->first < 0)
	{
		cur->first *= -1;
		cur->minus = 1;
	}
	if (cur->minus && cur->zero)
		cur->zero = 0;
	if (cur->zero && cur->dot)
		cur->zero = 0;
	if ((cur->type == 'd' || cur->type == 'i') && (cur->zero && !cur->dot))
	{
		cur->zero = 0;
		cur->dot = 2;
		cur->second = cur->first;
		cur->first = 0;
	}
}

int				check_combi(t_flags *cur)
{
	if (!(cur->type == 'c' || cur->type == 's' || cur->type == 'p' ||
			cur->type == 'd' || cur->type == 'i' || cur->type == 'u' ||
			cur->type == 'x' || cur->type == 'X' || cur->type == '%'))
		return (0);
	combi_set(cur);
	return (1);
}

int				print_form(t_flags cur, va_list ap, int *count)
{
	char	*tmp;
	int		result;

	result = 0;
	if (!(tmp = malloc(cur.first + 1)))
		return (0);
	tmp[cur.first] = 0;
	ft_memset(tmp, ' ', cur.first);
	if (cur.type == '%')
		result = print_percent(cur, count, tmp);
	else if (cur.type == 'c')
		result = print_c(cur, va_arg(ap, int), count, tmp);
	else if (cur.type == 's' || cur.type == 'p')
		result = print_sp(cur, va_arg(ap, char *), count, tmp);
	else if (cur.type == 'd' || cur.type == 'i' || cur.type == 'u' ||
			cur.type == 'x' || cur.type == 'X')
		result = print_num(cur, va_arg(ap, int), count, tmp);
	free(tmp);
	return (result);
}
