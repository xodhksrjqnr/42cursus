#include <stdio.h>
#include <string.h>

void	*ft_memcpy(void *dest, const void *src, size_t n);

int		main(void)
{
	char	dest[] = "aaa bbb ccc ddd";
	char	dest1[] = "aaa bbb ccc ddd";
	char	src[] = "111111";
	char	src1[] = "111111";
	int		count;

	printf("%s\n", dest);
	memcpy(dest, src, 10 * sizeof(char));
	count = 0;
	while (count < 15)
		printf("%c", dest[count++]);
	printf("\n");
	ft_memcpy(dest1, src1, 10 * sizeof(char));
	count = 0;
	while (count < 15)
		printf("%c", dest1[count++]);
	printf("\n");
	return (0);
}
