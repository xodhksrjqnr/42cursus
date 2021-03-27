#include "list.h"

t_r	*init_r(void)
{
	t_r	*R;

	R = malloc(sizeof(t_r));
	if (!R)
		return (0);
	R->x = 0;
	R->y = 0;
	return (R);
}

int	parse_R(char *line, t_r **R)
{
	if (*R)
		return (0);
	*R = init_r();
	if (!*R)
		return (0);
	line++;
	while (*line == ' ')
		line++;
	while (*line >= '0' && *line <= '9')
		(*R)->x = (*R)->x * 10 + *line++ - 48;
	while (*line == ' ')
		line++;
	while (*line >= '0' && *line <= '9')
		(*R)->y = (*R)->y * 10 + *line++ - 48;
	if (*line)
		return (0);
	return (1);
}
