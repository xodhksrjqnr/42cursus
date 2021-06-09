/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_end_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taewakim <taewakim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/09 13:38:05 by taewakim          #+#    #+#             */
/*   Updated: 2021/06/09 13:38:07 by taewakim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		check_end_value(t_elem **s, int *leng, char *flag)
{
	t_elem	*tmp;
	t_data	data;

	tmp = *s;
	init_data(&data, tmp->value);
	data.count = 1;
	while (data.i++ < *leng)
	{
		if (data.pivot < tmp->value)
		{
			data.pivot = tmp->value;
			data.count++;
		}
		tmp = tmp->next;
	}
	if (data.pivot == tmp->prev->value && data.count == *leng)
		(*leng)--;
	else
		return ;
	check_end_value(s, leng, flag);
	*flag = 1;
}

static void	elem_three_sort_e(t_elem **s, int *v)
{
	v[0] = (*s)->value;
	v[1] = (*s)->next->value;
	v[2] = (*s)->next->next->value;
	if (v[2] < v[0] && v[2] < v[1])
	{
		if (v[0] > v[1])
			swap_stack(s, 1);
		rotate_stack(s, 1);
		swap_stack(s, 1);
		reverse_rotate_stack(s, 1);
		swap_stack(s, 1);
	}
	else if (v[2] > v[0] && v[2] > v[1])
	{
		if (v[0] > v[1])
			swap_stack(s, 1);
	}
	else
	{
		if (v[0] > v[1])
			swap_stack(s, 1);
		rotate_stack(s, 1);
		swap_stack(s, 1);
		reverse_rotate_stack(s, 1);
	}
}

char		check_end(t_elem **s, int *leng, char *flag)
{
	int	v[3];

	check_end_value(s, leng, flag);
	if (*leng > 3)
		return (1);
	else if (!*leng || *leng == 1)
		return (0);
	else if (*leng == 2 && (*s)->value > (*s)->next->value)
		swap_stack(s, 1);
	else if (*leng == 3)
		elem_three_sort_e(s, v);
	return (0);
}

char		move_end(t_elem **s1, t_elem **s2, int *leng, char *flag)
{
	int		i;

	if (*leng > 3)
		return (1);
	i = 0;
	while (i++ < *leng)
		move_elem(s1, s2, 1);
	check_end(s2, leng, flag);
	return (0);
}
