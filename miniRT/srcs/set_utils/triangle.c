#include "list.h"

t_tr	*init_tr(void)
{
	t_tr	*tr;

	tr = malloc(sizeof(tr));
	if (!tr)
		return (0);
	tr->x1 = 0;
	tr->y1 = 0;
	tr->z1 = 0;
	tr->x2 = 0;
	tr->y2 = 0;
	tr->z2 = 0;
	tr->x3 = 0;
	tr->y3 = 0;
	tr->z3 = 0;
	tr->color = 0;
	tr->next = 0;
	return (tr);
}

static t_tr	*find_tr_end(t_tr **tr)
{
	t_tr	*save;

	save = *tr;
	if (!*tr)
	{
		*tr = init_tr();
		return (*tr);
	}
	while (save->next)
		save = save->next;
	save->next = init_tr();
	return (save->next);
}

int	parse_tr(char *line, t_tr **tr)
{
	t_tr	*cur;

	cur = find_tr_end(tr);
	if (!cur)
		return (0);
	line += 2;
	if (!cal_loca(&line, &(cur->x1), &(cur->y1), &(cur->z1)))
		return (0);
	if (!cal_loca(&line, &(cur->x2), &(cur->y2), &(cur->z2)))
		return (0);
	if (!cal_loca(&line, &(cur->x3), &(cur->y3), &(cur->z3)))
		return (0);
	if (!cal_color(&line, &(cur->color)))
		return (0);
	return (1);
}
