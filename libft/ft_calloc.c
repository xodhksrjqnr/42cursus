#include <stdlib.h>

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*result;
	void	*tmp;
	size_t	count;

	if (!(result = malloc(nmemb * size)) || nmemb * size == 0)
		return (0);
	count = 0;
	tmp = result;
	while (count < nmemb * size)
	{
		*((unsigned char *)tmp + count) = 0;
		count++;
	}
	return (result);
}
