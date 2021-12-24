#include "philo.h"

static int	convert(char *str, long *input, int cur)
{
	while ('0' <= *str && *str <= '9')
	{
		input[cur] = input[cur] * 10 + (*str - 48);
		str++;
	}
	if (!*str)
		return (1);
	return (0);
}

int	setting(int ac, char **av, long *input)
{
	char	*msg;
	int		i;

	msg = 0;
	i = 0;
	if (!(ac == 5 || ac == 6))
		msg = "invlid arguments";
	memset(input, 0, 5 * sizeof(long));
	while (*(++av) && !msg)
		if (!convert(*av, input, i++))
			msg = "invalid arguments";
	if (msg)
	{
		free(input);
		printf("%s\n", msg);
		return (0);
	}
	return (1);
}
