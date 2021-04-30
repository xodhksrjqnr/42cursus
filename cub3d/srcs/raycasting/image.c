#include "raycasting.h"

static void    set_clean_image(t_cub3d *cub3d)
{
    char    *adr;
    char    *dst;
    int     *tmp;
    int     x;
    int     y;

    tmp = cub3d->data->resolution;
    cub3d->texture[0] = mlx_new_image(cub3d->mlx, *tmp, *(tmp + 1));
    adr = mlx_get_data_addr(cub3d->texture[0], &(cub3d->bpp), &(cub3d->leng), &(cub3d->endian));
    y = 0;
    while (y < *(tmp + 1))
    {
        x = 0;
        while (x < *tmp)
        {
            dst = adr + x * (cub3d->bpp / 8) + y * cub3d->leng;
            *(unsigned int*)dst = 0;
            x++;
        }
        y++;
    }
}

void    set_image(t_cub3d *cub3d)
{
    int i;
    int sizeX;
    int sizeY;

    cub3d->texture = malloc(sizeof(void *) * 5);
    set_clean_image(cub3d);
    i = 1;
    while (i < 5)
    {
        cub3d->texture[i] = mlx_png_file_to_image(cub3d->mlx, cub3d->data->texture[i - 1], &sizeX, &sizeY);
        i++;
    }
}