#include "philo.h"

int	main(int ac, char **av)
{
	long	*input;

	input = malloc(5 * sizeof(long));
	if (!input)
	{
		printf("malloc error\n");
		return (0);
	}
	if (setting(ac, av, input))
		running(input);
	return (0);
}
