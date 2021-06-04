#include "sprite.h"

int		init_sprite(t_sprite **sprite, int col, int row, int num)
{
	sprite[num] = malloc(sizeof(t_sprite));
	if (!sprite[num])
		return (0);
	sprite[num]->x = row;
	sprite[num]->y = col;
	return (1);
}

int		check_fov(t_sprite *target, double *dir, double fov, double *cur)
{
	double	angle;
	double	dist;

	dist = sqrt(pow(cur[0], 2) + pow(cur[1], 2));
	if (dist < 0.5)
		return (0);
	angle = dir[0] * cur[0] + dir[1] * cur[1];
	angle /= sqrt(pow(dir[0], 2) + pow(dir[1], 2)) * dist;
	angle = fabs(acos(angle) * PI);
	if (angle > fov + 50)
		return (0);
	target->active = 1;
	return (1);
}

int		check_active(t_sprite *target, double dist, int x)
{
	if (!target->active)
		return (0);
	if (target->dist > dist)
		return (0);
	if (x < target->point[0] || x > target->point[1])
		return (0);
	return (1);
}

char	*set_adr_x(t_sprite *target, int x, char *adr, int bpp)
{
	int	value;

	value = (int)((x - target->point[0] + target->leng_x) * *target->ratio);
	return (adr + value * bpp);
}

char	*set_adr_y(char *ref, t_sprite *target, int y, int leng)
{
	return (ref + (int)((y - target->point[2]) * target->ratio[1]) * leng);
}
