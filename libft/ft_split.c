#include "libft.h"
#include <stdlib.h>

char	**ft_split(char const *s, char c)
{
	char	*cur;
	char	*tmp;
	char	**result;
	int		count;

	count = 0;
	tmp = (char *)s;
	while (*tmp)
		if (*tmp++ == c)
			count++;
	if (!(result = (char **)malloc(count + 1 * sizeof(char *))))
		return (0);
	tmp = (char *)s;
	while (cur = ft_strchr(tmp, c))
	{

	}
}
