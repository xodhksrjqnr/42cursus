#include "push_swap.h"

static char	check_argv(char **argv, t_elem **elem)
{
	int			flag;
	long long	count;

	flag = 1;
	if (**argv == '-')
	{
		flag = -1;
		(*argv)++;
	}
	count = 0;
	while ('0' <= **argv && **argv <= '9')
		count = count * 10 + *(*argv)++ - 48;
	if (!(**argv == ' ' || !**argv)
	|| count < -2147483648 || count > 2147483647)
		return (0);
	*elem = new_elem((int)count * flag);
	if (!*elem)
		return (0);
	return (1);
}

int			setting_program(t_elem **stack_a, int argc, char **argv)
{
	t_elem	*tmp;
	int		i;

	if (argc < 2)
		return (0);
	argv++;
	i = 0;
	while (*argv)
	{
		while (**argv == ' ')
			(*argv)++;
		if (!**argv)
		{
			argv++;
			continue ;
		}
		if (!check_argv(argv, &tmp))
			return (0);
		add_elem(stack_a, &tmp);
		i++;
		if (**argv == ' ')
			continue ;
		argv++;
	}
	return (i);
}