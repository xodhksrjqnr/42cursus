/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taewakim <taewakim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/04 20:52:10 by taewakim          #+#    #+#             */
/*   Updated: 2021/06/04 21:05:00 by taewakim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting.h"

static t_cub3d	*setting_program(void)
{
	t_cub3d	*cub3d;
	int		*tmp;
	int		size_x;
	int		size_y;

	cub3d = malloc(sizeof(t_cub3d));
	cub3d->data = parse();
	if (!cub3d->data)
		return (0);
	tmp = cub3d->data->resolution;
	cub3d->mlx = mlx_init();
	mlx_get_screen_size(cub3d->mlx, &size_x, &size_y);
	if (*tmp > size_x)
		*tmp = size_x;
	if (*(tmp + 1) > size_y)
		*(tmp + 1) = size_y;
	cub3d->window = mlx_new_window(cub3d->mlx, *tmp, *(tmp + 1), "cub3d");
	cub3d->texture = set_texture(cub3d->mlx, cub3d->data->texture);
	cub3d->player = set_player(cub3d->data->location, cub3d->data->direction);
	return (cub3d);
}

static void		run_program(t_cub3d *c)
{
	mlx_hook(c->window, 2, 1L << 0, key_press, c);
	mlx_hook(c->window, 3, 1L << 1, key_release, c);
	mlx_put_image_to_window(c->mlx, c->window, c->texture[0]->image, 0, 0);
	mlx_loop_hook(c->mlx, active_apply, cub);
	mlx_loop(c->mlx);
}

int				main(void)
{
	t_cub3d *cub3d;

	cub3d = setting_program();
	if (!cub3d)
		return (0);
	ray_casting(cub3d, cub3d->player, cub3d->data);
	run_program(cub3d);
}
