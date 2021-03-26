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
