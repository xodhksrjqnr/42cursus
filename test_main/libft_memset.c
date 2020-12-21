#include <stdio.h>
#include <string.h>

void	*ft_memset(void *s, int c, size_t n);

int		main(void)
{
	char	test[] = "0123456789";
	int		test2[] = {1, 2, 3, 4, 5};
	int		count;

	printf("%s\n", test);
	memset(test, 'a', 10 * sizeof(char));
	printf("%s\n", test);
	ft_memset(test, 'b', 10 * sizeof(char));
	printf("%s\n", test);

	count = 0;
	while (count < 5)
		printf("%d ", test2[count++]);
	printf("\n");
	memset(test2, 0, 3 * sizeof(int));
	count = 0;
	while (count < 5)
		printf("%d ", test2[count++]);
	printf("\n");
	ft_memset(test2, 1, 3 * sizeof(int));
	count = 0;
	while (count < 5)
		printf("%d ", test2[count++]);
	printf("\n");
	return (0);
}
