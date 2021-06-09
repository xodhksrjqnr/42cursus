/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setting_program.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taewakim <taewakim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 13:38:24 by taewakim          #+#    #+#             */
/*   Updated: 2021/06/09 13:38:25 by taewakim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static char	check_argv(char **argv, t_elem **elem)
{
	int			flag;
	long long	count;

	flag = 1;
	if (**argv == '-')
	{
		flag = -1;
		(*argv)++;
	}
	count = 0;
	while ('0' <= **argv && **argv <= '9')
		count = count * 10 + *(*argv)++ - 48;
	count *= flag;
	if (**argv || count < -2147483648 || count > 2147483647)
		return (0);
	*elem = new_elem((int)count);
	if (!*elem)
		return (0);
	return (1);
}

int			setting_program(t_elem **stack_a, int argc, char **argv)
{
	t_elem	*tmp;
	int		i;

	if (argc < 2)
		return (0);
	argv++;
	i = 0;
	while (*argv)
	{
		if (!**argv)
			return (0);
		if (!check_argv(argv, &tmp))
			return (0);
		add_elem(stack_a, &tmp);
		i++;
		argv++;
	}
	return (i);
}
