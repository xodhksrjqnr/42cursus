#include <unistd.h>

void	inter(char *str1, char *str2)
{
	int		check_box[95];
	int		count;

	count = 0;
	while (count < 95)
		check_box[count++] = 0;
	while (*str2)
		check_box[*str2++ - 32] = 1;
	while (*str1)
	{
		if (check_box[*str1 - 32] == 1)
			write(1, str1, 1);
		check_box[*str1++ - 32] = 0;
	}
}

int	main(int argc, char **argv)
{
	if (argc == 3)
		inter(*(argv + 1), *(argv + 2));
	write(1, "\n", 1);
	return (0);
}
