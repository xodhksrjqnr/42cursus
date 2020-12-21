#include <strings.h>
#include <stdio.h>

void	ft_bzero(void *s, size_t n);

int		main(void)
{
	char	test[] = "abcdefghi";
	char	test2[] = "abcdefghi";
	int		test3[] = {1, 2, 3, 4, 5};
	int		test4[] = {1, 2, 3, 4, 5};
	int		count;

	printf("%s %s\n", test, test2);
	bzero(test, 5 * sizeof(char));
	count = 0;
	while (count < 9)
		printf("%c", test[count++]);
	printf(" ");
	ft_bzero(test2, 5 * sizeof(char));
	count = 0;
	while (count < 9)
		printf("%c", test2[count++]);
	printf("\n");

	count = 0;
	while (count < 5)
		printf("%d ", test3[count++]);
	printf("\n");
	bzero(test3, 3 * sizeof(int));
	count = 0;
	while (count < 5)
		printf("%d ", test3[count++]);
	printf("\n");
	count = 0;
	while (count < 5)
		printf("%d ", test4[count++]);
	printf("\n");
	ft_bzero(test4, 3 * sizeof(int));
	count = 0;
	while (count < 5)
		printf("%d ", test4[count++]);
	printf("\n");
	return (0);
}
