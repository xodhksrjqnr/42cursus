#include "raycasting.h"

static void clear_image(t_cub3d *cub3d)
{
    char    *dst;
    int     x;
    int     y;

    y = 0;
    while (y < cub3d->data->resolution[1])
    {
      x = 0;
      while (x < cub3d->data->resolution[0])
      {
        dst = cub3d->img_adr + x * (cub3d->bpp / 8) + y * cub3d->line_leng;
        *(unsigned int*)dst = 0;
        x++;
      }
      y++;
    }
    mlx_put_image_to_window(cub3d->mlx, cub3d->window, cub3d->image, 0, 0);
}

static t_cub3d  *setting_program(void)
{
    t_cub3d *cub3d;
    int     *tmp;

    cub3d = malloc(sizeof(t_cub3d));
    cub3d->data = parse();
    tmp = cub3d->data->resolution;
    cub3d->mlx = mlx_init();
    cub3d->window = mlx_new_window(cub3d->mlx, *tmp, *(tmp + 1), "cub3d");
    cub3d->image = mlx_new_image(cub3d->mlx, *tmp, *(tmp + 1));
    cub3d->img_adr = mlx_get_data_addr(cub3d->image, &(cub3d->bpp), &(cub3d->line_leng), &(cub3d->endian));
    cub3d->player = set_player(cub3d->data->location, cub3d->data->direction);
    return (cub3d);
}

static void run_program(t_cub3d *cub3d)
{
    mlx_hook(cub3d->window, 2, 1L<<0, key_press, cub3d);
    mlx_hook(cub3d->window, 3, 1L<<1, key_release, cub3d);
    clear_image(cub3d);
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