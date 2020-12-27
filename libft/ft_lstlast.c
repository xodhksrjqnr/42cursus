#include "libft.h"

t_list		*ft_lstlast(t_list *lst)
{
	t_list		*pre;

	pre = 0;
	while (lst)
	{
		pre = lst;
		lst = lst->next;
	}
	return (pre);
}
