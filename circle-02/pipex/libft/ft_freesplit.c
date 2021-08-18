#include "libft.h"

void	free_split(char **target)
{
	int	i;

	i = 0;
	while (*(target + i))
		free(*(target + i++));
	free(target);
}