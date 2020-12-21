#include <stddef.h>

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	size_t		count;

	count = 0;
	while (count < n)
	{
		*((unsigned char *)dest) = *((unsigned char *)src + count);
		dest++;
		if (*((unsigned char *)src + count) == c)
			return (dest);
		count++;
	}
	return (0);
}
//내장 memccpy의 경우 결과가 다르게 나옴 ex) c 문자가 src에 존재하지 않을 때
