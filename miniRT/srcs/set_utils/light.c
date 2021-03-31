#include "list.h"

static t_l	*init_l(void)
{
	t_l	*l;

	l = malloc(sizeof(t_l));
	if (!l)
		return (0);
	l->x = 0;
	l->y = 0;
	l->z = 0;
	l->range = 0;
	l->color = 0;
	l->next = 0;
	return (l);
}

void	free_l(t_l *l)
{
	t_l	*save;

	while (l)
	{
		save = l->next;
		free(l);
		l = save;
	}
}

static t_l	*find_l_end(t_l **l)
{
	t_l	*save;

	save = *l;
	if (!*l)
	{
		*l = init_l();
		return (*l);
	}
	while (save->next)
		save = save->next;
	save->next = init_l();
	return (save->next);
}

int	parse_l(char *line, t_l **l)
{
	t_l	*cur;

	cur = find_l_end(l);
	if (!cur)
		return (0);
	line++;
	if (!cal_loca(&line, &(cur->x), &(cur->y), &(cur->z)))
		return (0);
	while (*line == ' ')
		line++;
	list_atoi_f(&line, &(cur->range));
	if (*line != ' ' || !(cur->range >= 0.0 && cur->range <= 1.0))
		return (0);
	if (!(cal_color(&line, &(cur->color))))
		return (0);
	return (1);
}
