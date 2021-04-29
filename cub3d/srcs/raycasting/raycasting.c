#include "raycasting.h"

static void  set_dda_value(t_dda *dda_value, double *ray, t_player *player)
{
    int i;

    i = 0;
    while (i < 2)
    {
        dda_value->map[i] = (int)(player->pos[i]);
        dda_value->deltaDist[i] = fabs(1 / ray[i]);
        dda_value->step[i] = -1;
        dda_value->sideDist[i] = player->pos[i] - dda_value->map[i];
        if (ray[i] >= 0)
        {
            dda_value->step[i] = 1;
            dda_value->sideDist[i] = (-1 * dda_value->sideDist[i]) + 1.0;
        }
        dda_value->sideDist[i] *= dda_value->deltaDist[i];
        i++;
    }
}

static int  hit_wall(t_dda *dda_value, char **worldMap)
{
    int side;

    side = 0;
    while (1)
    {
      if (dda_value->sideDist[0] < dda_value->sideDist[1])
        side = 0;
      else
        side = 1;
      dda_value->sideDist[side] += dda_value->deltaDist[side];
      dda_value->map[side] += dda_value->step[side];
      if (worldMap[(int)dda_value->map[0]][(int)dda_value->map[1]] != '0')
        break;
    }
    return (side);
}

static void my_mlx_pixel_put(t_cub3d *cub3d, t_dda *dda_value, int x)
{
  char    *dst;
  int     count;
  int     point[2];
  int     *tmp;
  t_img   box;

  tmp = cub3d->data->resolution;
  draw_point((int)(*tmp / dda_value->perpWallDist), *(tmp + 1), point);
  box.adr = mlx_get_data_addr(cub3d->texture[1], &box.bpp, &box.leng, &box.endian);
  box.ratio = 32 / (*(point + 1) - *point);
  count = 0;
  while (count < *(tmp + 1))
  {
    dst = cub3d->img->adr + draw_texture(cub3d->img, x, count);
    if (count < point[0])
      *(unsigned int *)dst = 0x00F0F0F0;
    else if (count >= point[1])
      *(unsigned int *)dst = 0x00FF00FF;
    else
      *(unsigned int *)dst = (unsigned int)draw_texture(&box, x, count);
    count++;
  }
}

int ray_casting(char **worldMap, t_cub3d *cub3d)
{
  int     side;
  int     i;
  double  ray[2];
  t_dda   *dda_value;

  dda_value = malloc(sizeof(t_dda));
  if (!dda_value)
      return (0);
  i = 0;
  while (i < cub3d->data->resolution[0])
  {
    ray[0] = cub3d->player->dir[0] + (cub3d->player->plane[0] * ((2 * i / (double)cub3d->data->resolution[0]) - 1));
    ray[1] = cub3d->player->dir[1] + (cub3d->player->plane[1] * ((2 * i / (double)cub3d->data->resolution[0]) - 1));
    set_dda_value(dda_value, ray, cub3d->player);
    side = hit_wall(dda_value, worldMap);
    dda_value->perpWallDist = (dda_value->map[side] - cub3d->player->pos[side] + (1 - dda_value->step[side]) / 2) / ray[side];
    my_mlx_pixel_put(cub3d, dda_value, i);
    i++;
  }
  mlx_put_image_to_window(cub3d->mlx, cub3d->window, cub3d->img->image, 0, 0);
  free(dda_value);
  return (1);
}