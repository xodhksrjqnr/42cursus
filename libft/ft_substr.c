#include <stdlib.h>

char	*ft_substr(char const *s, unsigned int start, unsigned int len)
{
	char			*result;
	char			*tmp;
	unsigned int 	count;

	if (!(result = (char *)malloc(sizeof(char) * len + 1)))
		return (0);
	count = 0;
	while (count < start)
	{
		count++;
		s++;
	}
	tmp = result;
	while (count++ < len)
		*tmp++ = *s++;
	*tmp = 0;
	return (result);
}
