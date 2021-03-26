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
