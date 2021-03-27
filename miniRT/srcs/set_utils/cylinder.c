#include "list.h"

t_cy	*init_cy(void)
{
	t_cy	*cy;

	cy = malloc(sizeof(cy));
	if (!cy)
		return (0);
	cy->v = init_vec();
	if (!(cy->v))
	{
		free(cy);
		return (0);
	}
	cy->x = 0;
	cy->y = 0;
	cy->z = 0;
	cy->r = 0;
	cy->h = 0;
	cy->color = 0;
	cy->next = 0;
	return (cy);
}

static t_cy	*find_cy_end(t_cy **cy)
{
	t_cy	*save;

	save = *cy;
	if (!*cy)
	{
		*cy = init_cy();
		return (*cy);
	}
	while (save->next)
		save = save->next;
	save->next = init_cy();
	return (save->next);
}

int	parse_cy(char *line, t_cy *cy)
{
	t_cy	*cur;

	cur = find_cy_end(&cy);
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
	list_atoi_f(&line, &(cur->r));
	while (*line == ' ')
		line++;
	list_atoi_f(&line, &(cur->h));
	if (cur->r < 0 || cur->h < 0)
		return (0);
	if (!cal_color(&line, &(cur->color)))
		return (0);
	return (0);
}
