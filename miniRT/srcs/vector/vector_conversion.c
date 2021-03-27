#include "libvec.h"

void	rotation_trans(t_vec *v, char axle)
{
	float	tmp;
	float	s_value;
	float	c_value;

	tmp = 0;
	s_value = sin(rotation_value);
	c_value = cos(rotation_value);
	if (axle == 'x')
	{
		tmp = (c_value * v->y) - (s_value * v->z);
		v->z = (s_value * v->y) + (c_value * v->z);
		v->y = tmp;
	}
	else if (axle == 'y')
	{
		tmp = (c_value * v->z) - (s_value * v->x);
		v->x = (s_value * v->z) + (c_value * v->x);
		v->z = tmp;
	}
	else
	{
		tmp = (c_value * v->x) - (s_value * v->y);
		v->y = (s_value * v->x) + (c_value * v->y);
		v->x = tmp;
	}
}

void	scaling_trans(t_vec *v, float x, float y, float z)
{
	v->x *= x;
	v->y *= y;
	v->z *= z;
}
