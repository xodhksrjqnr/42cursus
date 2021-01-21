/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taewakim <taewakim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 15:33:50 by taewakim          #+#    #+#             */
/*   Updated: 2021/01/21 14:24:19 by taewakim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static t_flags	init_node(void)
{
	t_flags		tmp;

	tmp.type = 0;
	tmp.minus = 0;
	tmp.zero = 0;
	tmp.dot = 0;
	tmp.first = 0;
	tmp.second = 0;
	return (tmp);
}

static int		check_num(const char *s, va_list ap, t_flags *cur, int div)
{
	char	*save;
	int		*tmp;

	if (div == 1)
		cur->dot = 1;
	save = (char *)s;
	tmp = (!div) ? &(cur->first) : &(cur->second);
	if (*s == '*')
	{
		*tmp = va_arg(ap, int);
		s++;
	}
	else if (*s >= '0' && *s <= '9')
	{
		*tmp = ft_atoi(s);
		while (*s >= '0' && *s <= '9')
			s++;
	}
	return (s - save);
}

static int		parse(const char *s, va_list ap, int *count)
{
	t_flags		cur;
	char		*save;

	save = (char *)s;
	cur = init_node();
	while (*s == '-' || *s == '0')
	{
		if (*s == '-')
			cur.minus = 1;
		else
			cur.zero = 1;
		s++;
	}
	s += check_num(s, ap, &cur, 0);
	if (*s == '.')
	{
		s++;
		s += check_num(s, ap, &cur, 1);
	}
	cur.type = *s;
	if (!(check_combi(&cur)))
		return (0);
	if (!print_form(cur, ap, count))
		return (0);
	return (s - save + 1);
}

int				ft_printf(const char *s, ...)
{
	va_list		ap;
	int			count;
	int			move;

	count = 0;
	va_start(ap, s);
	while (*s)
	{
		if (*s == '%')
		{
			if (!(move = parse(++s, ap, &count)))
			{
				va_end(ap);
				return (-1);
			}
			s += move;
		}
		else
		{
			write(1, s++, 1);
			count++;
		}
	}
	va_end(ap);
	return (count);
}
