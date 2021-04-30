#include "raycasting.h"

static t_cub3d  *setting_program(void)
{
    t_cub3d *cub3d;
    int     *tmp;
    int     sizeX;
    int     sizeY;

    cub3d = malloc(sizeof(t_cub3d));
    cub3d->data = parse();
    tmp = cub3d->data->resolution;
    cub3d->mlx = mlx_init();
    mlx_get_screen_size(cub3d->mlx, &sizeX, &sizeY);
    if (*tmp > sizeX)
      *tmp = sizeX;
    if (*(tmp + 1) > sizeY)
      *(tmp + 1) = sizeY;
    cub3d->window = mlx_new_window(cub3d->mlx, *tmp, *(tmp + 1), "cub3d");
    set_image(cub3d);
    cub3d->image = mlx_new_image(cub3d->mlx, *tmp, *(tmp + 1));
    cub3d->adr = mlx_get_data_addr(cub3d->image, &(cub3d->bpp), &(cub3d->leng), &(cub3d->endian));
    cub3d->player = set_player(cub3d->data->location, cub3d->data->direction);
    return (cub3d);
}

static void run_program(t_cub3d *cub3d)
{
    mlx_hook(cub3d->window, 2, 1L<<0, key_press, cub3d);
    mlx_hook(cub3d->window, 3, 1L<<1, key_release, cub3d);
    mlx_put_image_to_window(cub3d->mlx, cub3d->window, cub3d->texture[0], 0, 0);
    mlx_loop_hook(cub3d->mlx, active_apply, cub3d);
    mlx_loop(cub3d->mlx);
}

int main(void)
{
    t_cub3d *cub3d;
    
    cub3d = setting_program();
    ray_casting(cub3d->data->worldMap, cub3d);
    run_program(cub3d);
}