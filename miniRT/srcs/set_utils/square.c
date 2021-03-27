#include "list.h"

t_sq	*init_sq(void)
{
	t_sq	*sq;

	sq = malloc(sizeof(sq));
	if (!sq)
		return (0);
	sq->v = init_vec();
	if (!(sq->v))
	{
		free(sq);
		return (0);
	}
	sq->x = 0;
	sq->y = 0;
	sq->z = 0;
	sq->length = 0;
	sq->color = 0;
	sq->next = 0;
	return (0);
}

static t_sq	*find_sq_end(t_sq **sq)
{
	t_sq	*save;

	save = *sq;
	if (!*sq)
	{
		*sq = init_sq();
		return (*sq);
	}
	while (save->next)
		save = save->next;
	save->next = init_sq();
	return (save->next);
}

int	parse_sq(char *line, t_sq *sq)
{
	t_sq	*cur;

	cur = find_sq_end(&sq);
	if (!cur)
		return (0);
	line++;
	if (!cal_loca(&line, &(cur->x), &(cur->y), &(cur->z)))
		return (0);
	if (!cal_loca(&line, &(cur->v->x), &(cur->v->y), &(cur->v->z)))
		return (0);
	if (!(cur->v->x >= -1 && cur->v->x <= 1))
		return (0);
	if (!(cur->v->y >= -1 && cur->v->y <= 1))
		return (0);
	if (!(cur->v->z >= -1 && cur->v->z <= 1))
		return (0);
	while (*line == ' ')
		line++;
	list_atoi_f(&line, &(cur->length));
	if (cur->length < 0)
		return (0);
	if (!cal_color(&line, &(cur->color)))
		return (0);
	return (1);
}
