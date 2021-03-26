#include "libvec.h"

t_vec	*init_vec(void)
{
	t_vec	*v;

	v = (t_vec *)malloc(sizeof(t_vec));
	if (!v)
		return (0);
	v->x = 0;
	v->y = 0;
	v->z = 0;
	v->state = 0;
	return (v);
}

void	add_vec(t_vec *v1, t_vec *v2)
{
	v1->x += v2->x;
	v1->y += v2->y;
	v1->z += v2->z;
}

void	sub_vec(t_vec *v1, t_vec *v2)
{
	v1->x -= v2->x;
	v1->y -= v2->y;
	v1->z -= v2->z;
}
