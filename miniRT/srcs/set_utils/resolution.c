#include "list.h"

static t_r	*init_r(void)
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
	list_atoi(&line, &(*R->x));
	if (*line != ' ')
		return (0);
	while (*line == ' ')
		line++;
	list_atoi(&line, &(*R->y));
	if (*line != ' ')
		return (0);
	return (1);
}
