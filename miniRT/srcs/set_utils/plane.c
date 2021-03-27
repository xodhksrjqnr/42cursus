#include "list.h"

t_pl	*init_pl(void)
{
	t_pl	*pl;

	pl = malloc(sizeof(pl));
	if (!pl)
		return (0);
	pl->v = init_vec();
	if (!(pl->v))
	{
		free(pl);
		return (0);
	}
	pl->x = 0;
	pl->y = 0;
	pl->z = 0;
	pl->color = 0;
	pl->next = 0;
	return (pl);
}

static t_pl	*find_pl_end(t_pl **pl)
{
	t_pl	*save;

	save = *pl;
	if (!*pl)
	{
		*pl = init_pl();
		return (*pl);
	}
	while (save->next)
		save = save->next;
	save->next = init_pl();
	return (save->next);
}

int	parse_pl(char *line, t_pl *pl)
{
	t_pl	*cur;

	cur = find_pl_end(&pl);
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
	if (!cal_color(&lien, &(cur->color)))
		return (0);
	return (1);
}
