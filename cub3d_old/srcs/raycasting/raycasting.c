/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taewakim <taewakim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/04 20:51:53 by taewakim          #+#    #+#             */
/*   Updated: 2021/06/12 00:07:42 by taewakim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting.h"

static void			draw_sprite(t_cub3d *cub, int x, t_sprite **sprite
, char *dst)
{
	t_texture	*t;
	int			y;
	char		*ref;
	char		*ref2;
	char		*tmp;

	t = cub->texture[4];
	while (*sprite)
	{
		if (check_active(*sprite, cub->dda->walldist, x))
		{
			ref = set_adr_x(*sprite, x, t->adr, t->bpp);
			y = (*sprite)->point[2];
			tmp = dst + y * cub->leng;
			while (y < (*sprite)->point[3])
			{
				ref2 = set_adr_y(ref, *sprite, y, t->leng);
				if (*(unsigned int *)ref2)
					*(unsigned int *)tmp = *(unsigned int *)ref2;
				tmp += cub->leng;
				y++;
			}
		}
		sprite++;
	}
}

static void			set_sprite(t_sprite **sprite, t_player *player
, t_cub3d *cub)
{
	int			i;
	double		cur[2];
	t_texture	*texture;

	texture = cub->texture[4];
	i = -1;
	while (sprite[++i])
	{
		set_sprite_dist(sprite[i], player->pos);
		sprite[i]->active = 0;
		cur[0] = sprite[i]->y + 0.5 - player->pos[0];
		cur[1] = sprite[i]->x + 0.5 - player->pos[1];
		if (!check_fov(sprite[i], player->dir, player->fov, cur))
			continue ;
		trans_location(cur, player->dir, player->plane);
		set_draw_point(cub->data->resol, cur, sprite[i]->point);
		set_ratio(texture->size, sprite[i]);
		if (*sprite[i]->point > (int)(cub->data->resol[0] * 0.2))
			sprite[i]->leng_x = 0;
	}
	sort_sprite(&sprite);
}

static void			my_pixel_put(t_cub3d *cub, char *dst, char *ref)
{
	int	y;
	int	flag;
	int	*color;
	int	*point;

	y = 0;
	point = cub->dda->point;
	color = cub->data->color;
	while (y < cub->data->resol[1])
	{
		if (point[0] <= y && y <= point[1])
			*(unsigned int *)dst = t_color(ref, y - point[0], cub->dda->cur);
		else
		{
			flag = 1;
			if (y > point[1])
				flag = 0;
			*(unsigned int *)dst = (unsigned int)color[flag];
		}
		dst += cub->leng;
		y++;
	}
}

int					ray_casting(t_cub3d *cub, t_player *player, t_parse *data)
{
	int		x;
	char	*dst;

	cub->image = mlx_new_image(cub->mlx, data->resol[0], data->resol[1]);
	cub->adr = mlx_get_data_addr(cub->image, &(cub->bpp), &(cub->leng)
	, &(cub->endian));
	cub->bpp /= 8;
	set_sprite(data->sprite, player, cub);
	x = -1;
	dst = cub->adr;
	while (++x < data->resol[0])
	{
		set_dda_value(cub->dda, player, data->resol[0], x);
		hit_wall(cub->dda, data->worldmap, player->pos, data->sprite);
		draw_point(cub->dda, data);
		my_pixel_put(cub, dst, select_texture(cub->texture, cub->dda));
		draw_sprite(cub, x, data->sprite, dst);
		dst += cub->bpp;
	}
	mlx_put_image_to_window(cub->mlx, cub->window, cub->image, 0, 0);
	mlx_destroy_image(cub->mlx, cub->image);
	return (1);
}
