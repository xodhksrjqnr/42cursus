#include "list.h"

static t_sp	*init_sp(void)
{
	t_sp	*sp;

	sp = malloc(sizeof(t_sp));
	if (!sp)
		return (0);
	sp->x = 0;
	sp->y = 0;
	sp->z = 0;
	sp->r = 0;
	sp->color = 0;
	sp->next = 0;
	return (sp);
}

void	free_sp(t_sp *sp)
{
	t_sp	*save;

	while (sp)
	{
		save = sp->next;
		free(sp);
		sp = save;
	}
}

static t_sp	*find_sp_end(t_sp **sp)
{
	t_sp	*save;

	save = *sp;
	if (!*sp)
	{
		*sp = init_sp();
		return (*sp);
	}
	while (save->next)
		save = save->next;
	save->next = init_sp();
	return (save->next);
}

int	parse_sp(char *line, t_sp **sp)
{
	t_sp	*cur;

	cur = find_sp_end(sp);
	if (!cur)
		return (0);
	line += 2;
	if (!cal_loca(&line, &(cur->x), &(cur->y), &(cur->z)))
		return (0);
	while (*line == ' ')
		line++;
	list_atoi_f(&line, &(cur->r));
	if (cur->r < 0)
		return (0);
	if (!cal_color(&line, &(cur->color)))
		return (0);
	return (1);
}
