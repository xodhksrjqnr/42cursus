/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taewakim <taewakim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/29 06:00:31 by taewakim          #+#    #+#             */
/*   Updated: 2020/12/29 07:41:08 by taewakim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstmap(t_list *lst, void *(*f)(void *)
		, void (*del)(void *))
{
	t_list	*result;
	t_list	*node;

	result = 0;
	while (lst)
	{
		if (!(node = ft_lstnew(f(lst->content))))
		{
			ft_lstclear(&result, del);
			return (0);
		}
		ft_lstadd_back(&result, node);
		lst = lst->next;
	}
	return (result);
}
