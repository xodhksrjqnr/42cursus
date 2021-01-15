#include "ft_printf.h"
#include <stdio.h>

int		check_flags(const char *s, int *flags)
{
	int		count;

	count = 0;
	while (*s == '-' || *s == '0' || *s == '.' || *s == '*')
	{
		if (*s == '-')
			*flags += 1;
		else if (*s == '0')
			*(flags + 1) += 1;
		else if (*s == '.')
			*(flags + 2) += 1;
		else if (*s == '*')
			*(flags + 3) += 1;
		count++;
		s++;
	}
	return (count);
}

int		check_num(const char *s, int *num)
{
	int		count;

	count = 0;
	*num = ft_atoi(s);
	while (*s >= '0' && *s <= '9')
	{
		s++;
		count++;
	}
	return (count);
}

void	make_format(char type, int *flags, int num, int *count)
{
	printf("\ntype : %c, '-' : %d, '0' : %d, '.' : %d, '*' : %d, num : %d\n",
			type, flags[0], flags[1], flags[2], flags[3], num);
	count = 0;
	/*
	if (type == 'c')
	else if (type == 's')
	else if (type == 'p')
	else if (type == 'd' || type == 'i')
	else if (type == 'u')
	else if (type == 'x')
	else if (type == 'X')*/
}
