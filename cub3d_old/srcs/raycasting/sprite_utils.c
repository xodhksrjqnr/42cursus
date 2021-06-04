/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taewakim <taewakim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/04 20:52:33 by taewakim          #+#    #+#             */
/*   Updated: 2021/06/04 20:52:33 by taewakim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sprite.h"

void	set_sprite_dist(t_sprite *target, double *player_pos)
{
	double	rayx;
	double	rayy;

	rayy = (double)target->y - player_pos[0];
	rayx = (double)target->x - player_pos[1];
	target->dist = pow(rayy, 2) + pow(rayx, 2);
}

void	sort_sprite(t_sprite ***sprite)
{
	int			i;
	int			j;
	int			size;
	int			max;
	t_sprite	*tmp;

	size = 0;
	while ((*sprite)[size])
		size++;
	i = -1;
	while (++i < size - 1)
	{
		j = i;
		max = i;
		while (++j < size)
			if ((*(*sprite + j))->dist > (*(*sprite + max))->dist)
				max = j;
		if (max == i)
			continue ;
		tmp = *(*sprite + i);
		*(*sprite + i) = *(*sprite + max);
		*(*sprite + max) = tmp;
	}
}

void	trans_location(double *location, double *dir, double *plane)
{
	double	invdet;
	double	tmp;

	invdet = 1.0 / (plane[1] * dir[0] - dir[1] * plane[0]);
	tmp = location[1];
	location[1] = invdet * (dir[0] * location[1] - dir[1] * location[0]);
	location[0] = invdet * (-plane[0] * tmp + plane[1] * location[0]);
}

void	set_draw_point(int *resolution, double *location, int *drawpoint)
{
	int	i;
	int	leng;
	int	s_leng;

	i = 0;
	while (i < 4)
	{
		s_leng = (int)(resolution[0] / 2) * (1 + location[1] / location[0]);
		if (i == 2)
			s_leng = resolution[1] / 2;
		leng = abs((int)(resolution[1] / location[0]));
		drawpoint[i] = -leng * 0.5 + s_leng;
		if (drawpoint[i] < 0)
			drawpoint[i] = 0;
		drawpoint[i + 1] = leng * 0.5 + s_leng;
		if (drawpoint[i + 1] >= resolution[i / 2])
			drawpoint[i + 1] = resolution[i / 2] - 1;
		i += 2;
	}
}

void	set_ratio(int *size, t_sprite *sprite)
{
	int		tmp;
	int		*point;
	int		*leng_x;
	double	*ratio;

	point = sprite->point;
	leng_x = &sprite->leng_x;
	ratio = sprite->ratio;
	ratio[1] = (double)size[1] / (double)(point[3] - point[2] + 1);
	*leng_x = (int)((point[3] - point[2] + 1) * size[0] / (double)size[1]);
	ratio[0] = (double)size[0] / (double)*leng_x;
	if (point[1] - point[0] > *leng_x)
	{
		tmp = (point[1] - point[0] - *leng_x) * 0.5;
		point[0] += tmp;
		point[1] -= tmp;
	}
	*leng_x -= point[1] - point[0] + 1;
	if (*leng_x < 0)
		*leng_x = 0;
}
