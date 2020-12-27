/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taewakim <taewakim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/27 16:16:38 by taewakim          #+#    #+#             */
/*   Updated: 2020/12/27 19:56:47 by taewakim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list		*cur;

	if (!lst || !new)
		return ;
	if (!*lst)
		*lst = new;
	else
	{
		cur = *lst;
		while (cur->next)
			cur = cur->next;
		cur->next = new;
	}
}
