#include <stdio.h>
#include <string.h>

void	*ft_memccpy(void *dest, const void *src, int c, size_t n);

int		main(void)
{
	char	dest[] = "hello world!";
	char	dest1[] = "hello world!";
	char	src[] = "you are the one";
	char	src1[] = "you are the one";
	void	*location;
	void	*location1;
	int		count = 16;
	char	tmp = 'w';

	printf("%s %s\n", dest, dest1);
	location = memccpy(dest, src, tmp, count * sizeof(char));
	location1 = ft_memccpy(dest1, src1, tmp, count * sizeof(char));
	printf("%s\n%s\n", dest, dest1);
	printf("%s\n%s\n", (char *)location, (char *)location1);
	printf("%s\n%s\n", dest, dest1);
	return (0);
}
