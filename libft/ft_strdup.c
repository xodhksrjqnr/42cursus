#include <stdlib.h>

char	*ft_strdup(const char *s)
{
	char	*result;
	char	*tmp;
	int		size;

	size = 0;
	while (*(s + size))
		size++;
	if (!(result = (char *)malloc(sizeof(char) * size + 1)))
		return (0);
	tmp = result;
	while (*s)
		*tmp++ = *s++;
	*tmp = 0;
	return (result);
}
