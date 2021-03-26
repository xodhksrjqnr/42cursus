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
	sq->color = 0;
	sq->next = 0;
	return (0);
}
