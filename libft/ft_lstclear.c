/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taewakim <taewakim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/27 16:17:04 by taewakim          #+#    #+#             */
/*   Updated: 2020/12/27 20:37:14 by taewakim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list		*pre;

	pre = 0;
	while ((*lst))
	{
		pre = *lst;
		*lst = (*lst)->next;
		del(pre->content);
		free(pre);
	}
}
