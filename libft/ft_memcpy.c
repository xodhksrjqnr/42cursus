#include <stddef.h>

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t		count;

	count = 0;
	while (count < n)
	{
		*((unsigned char *)dest + count) = *((unsigned char *)src + count);
		count++;
	}
	return (dest);
}
