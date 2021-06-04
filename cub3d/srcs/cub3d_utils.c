#include "cub3d.h"

char	ft_strcmp(char *target)
{
	char	*stand;

	stand = "--save";
	while (*stand && *target)
	{
		stand++;
		target++;
	}
	if (!*stand && !*target)
		return (1);
	return (0);
}

char	*map_path_str(char *str)
{
	int		i;
	char	*stand;
	char	*new_str;

	stand = "./cubfile/";
	i = 0;
	while (*(str + i))
		i++;
	new_str = malloc(11 + i);
	if (!new_str)
		return (0);
	i = 0;
	while (*stand)
		*(new_str + i++) = *stand++;
	while (*str)
		*(new_str + i++) = *str++;
	*(new_str + i) = 0;
	return (new_str);
}
