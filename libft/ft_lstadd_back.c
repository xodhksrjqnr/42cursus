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
