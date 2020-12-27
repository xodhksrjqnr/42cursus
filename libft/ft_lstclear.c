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
