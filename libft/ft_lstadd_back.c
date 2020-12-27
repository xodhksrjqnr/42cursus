/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taewakim <taewakim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/27 16:16:38 by taewakim          #+#    #+#             */
/*   Updated: 2020/12/27 16:16:44 by taewakim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list		*pre;

	if (!lst || !new)
		return ;
	pre = 0;
	while (*lst)
	{
		pre = *lst;
		*lst = (*lst)->next;
	}
	if (!pre)
		*lst = new;
	else
		pre->next = new;
}
