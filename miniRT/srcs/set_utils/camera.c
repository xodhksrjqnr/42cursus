#include "list.h"

t_c	*init_c(void)
{
	t_c	*c;

	c = malloc(sizeof(c));
	if (!c)
		return (0);
	c->v = init_vec();
	if (!(c->v))
	{
		free(c);
		return (0);
	}
	c->x = 0;
	c->y = 0;
	c->z = 0;
	c->fov = 0;
	c->next = 0;
	return (c);
}

static t_c	*find_c_end(t_c **c)
{
	t_c	*save;

	save = *c;
	if (!*c)
	{
		*c = init_c();
		return (*c);
	}
	while (save->next)
		save = save->next;
	save->next = init_c();
	return (save->next);
}

int	parse_c(char *line, t_c *c)
{
	t_c	*cur;

	cur = find_c_end(&c);
	if (!cur)
		return (0);
	line++;
	if (!cal_loca(&line, &(cur->x), &(cur->y), &(cur->z)))
		return (0);
	if (!cal_loca(&line, &(cur->v->x), &(cur->v->y), &(cur->v->z)))
		return (0);
	if (!(cur->v->x >= -1.0 && cur->v->x <= 1.0))
		return (0);
	if (!(cur->v->y >= -1.0 && cur->v->y <= 1.0))
		return (0);
	if (!(cur->v->z >= -1.0 && cur->v->z <= 1.0))
		return (0);
	cur->v->state = 1;
	while (*line == ' ')
		line++;
	list_atoi_f(&line, &(cur->fov));
	if (!(cur->fov >= 0 && cur->fov <= 180))
		return (0);
	return (1);
}
