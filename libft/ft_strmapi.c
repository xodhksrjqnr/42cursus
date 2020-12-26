#include "libft.h"
#include <stdlib.h>

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t		len;
	size_t		count;
	char		*result;

	if (!s)
		return (0);
	len = ft_strlen(s);
	if (!(result = (char *)malloc(len + 1)))
		return (0);
	result[len] = 0;
	count = 0;
	while (count < len)
	{
		*(result + count) = f(count, *(s + count));
		count++;
	}
	return (result);
}
