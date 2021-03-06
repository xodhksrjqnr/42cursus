/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taewakim <taewakim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/04 20:52:06 by taewakim          #+#    #+#             */
/*   Updated: 2021/06/12 02:13:55 by taewakim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main_bonus.h"

static void		error_print(t_cub3d *cub3d, char *message)
{
	free_cub3d(cub3d);
	printf("Error\nmessage : %s\n", message);
	exit(1);
}

static void		run_program(t_cub3d *cub3d)
{
	mlx_hook(cub3d->window, KEY_PRESS, 0, key_press, cub3d);
	mlx_hook(cub3d->window, KEY_RELEASE, 0, key_release, cub3d);
	mlx_hook(cub3d->window, XICON_PRESS, 0, x_icon, cub3d);
	mlx_hook(cub3d->window, MOUSE_MOVE, 0, mouse_pos, cub3d);
	mlx_loop_hook(cub3d->mlx, active_apply, cub3d);
	mlx_loop(cub3d->mlx);
}

int				main(int argc, char **argv)
{
	t_cub3d cub3d;
	char	*err_message;

	if (argc != 2)
		error_print(0, "Invalid argument");
	err_message = setting_program(&cub3d, *(argv + 1));
	if (err_message)
		error_print(&cub3d, err_message);
	printf("complete parse\n");
	if (!ray_casting(&cub3d, cub3d.player, cub3d.data))
		error_print(&cub3d, "raycasting malloc error");
	run_program(&cub3d);
}
