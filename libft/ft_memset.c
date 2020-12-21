#include <stddef.h>

void	*ft_memset(void *s, int c, size_t n)
{
	size_t		count;

	count = 0;
	while (count < n)
	{
		*((unsigned char *)s + count) = (unsigned char)c;
		count++;
	}
	return (s);
}
