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
