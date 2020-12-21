#include <stddef.h>

void	ft_bzero(void *s, size_t n)
{
	size_t		count;

	count = 0;
	while (count < n)
	{
		*((unsigned char *)s + count) = 0;
		count++;
	}
}
