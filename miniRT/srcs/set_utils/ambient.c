#include "list.h"

static t_a	*init_a(void)
{
	t_a	*A;

	A = malloc(sizeof(t_a));
	if (!A)
		return (0);
	A->range = 0;
	A->color = 0;
	return (A);
}

int	parse_A(char *line, t_a **A)
{
	if (*A)
		return (0);
	*A = init_a();
	if (!*A)
		return (0);
	line++;
	while (*line == ' ')
		line++;
	list_atoi_f(&line, &((*A)->range));
	if (!((*A)->range >= 0 && (*A)->range <= 1))
		return (0);
	if (!cal_color(&line, &((*A)->color)))
		return (0);
	return (1);
}
