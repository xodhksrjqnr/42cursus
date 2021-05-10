#include "raycasting.h"

static t_cub3d	*setting_program(void)
{
	t_cub3d	*cub3d;
	int			*tmp;
	int			size_x;
	int			size_y;

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

static void	run_program(t_cub3d *cub3d)
{
	mlx_hook(cub3d->window, 2, 1L << 0, key_press, cub3d);
	mlx_hook(cub3d->window, 3, 1L << 1, key_release, cub3d);
	mlx_put_image_to_window(cub3d->mlx, cub3d->window, cub3d->texture[0]->image, 0, 0);
	mlx_loop_hook(cub3d->mlx, active_apply, cub3d);
	mlx_loop(cub3d->mlx);
}

int	main(void)
{
	t_cub3d *cub3d;

	cub3d = setting_program();
	if (!cub3d)
		return (0);
	ray_casting(cub3d, cub3d->player, cub3d->data);
	run_program(cub3d);
}