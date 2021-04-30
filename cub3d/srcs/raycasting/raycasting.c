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
    while (worldMap[(int)dda_value->map[0]][(int)dda_value->map[1]] == '0')
    {
      if (dda_value->sideDist[0] < dda_value->sideDist[1])
        side = 0;
      else
        side = 1;
      dda_value->sideDist[side] += dda_value->deltaDist[side];
      dda_value->map[side] += dda_value->step[side];
    }
    return (side);
}

static void my_mlx_pixel_put(t_cub3d *cub3d, t_dda *dda_value, t_texture *texture, int x, double wallX)
{
  char    *dst;
  int     count;
  int     point[2];
  int     *tmp;
  double  ratio;
  char    *ref;

  tmp = cub3d->data->resolution;
  draw_point((int)(*tmp / dda_value->perpWallDist), *(tmp + 1), point);
  ratio = (double)32 / (double)(*(point + 1) - *point + 1);
  count = 0;
  dst = cub3d->adr + x * (cub3d->bpp / 8);
  ref = texture->adr + (int)((int)wallX * ratio) * (texture->bpp / 8);
  while (count < *(tmp + 1))
  {
    if (count < point[0])
      *(unsigned int *)(dst + count * cub3d->leng) = 0x00F0F0F0;
    else if (count >= point[1])
      *(unsigned int *)(dst + count * cub3d->leng) = 0x00FF00FF;
    else
      *(unsigned int *)(dst + count * cub3d->leng) = *(unsigned int *)(ref + (int)(count * ratio) * texture->leng);
    count++;
  }
}

int ray_casting(char **worldMap, t_cub3d *cub3d)
{
  int     side;
  int     i;
  double  ray[2];
  t_dda   *dda_value;
  t_texture *texture;
  double  wallX;

  dda_value = malloc(sizeof(t_dda));
  if (!dda_value)
      return (0);
  texture = malloc(sizeof(t_texture));
  if (!texture)
      return (0);
  texture->adr = mlx_get_data_addr(cub3d->texture[1], &texture->bpp, &texture->leng, &texture->endian);
  i = 0;
  while (i < cub3d->data->resolution[0])
  {
    ray[0] = cub3d->player->dir[0] + (cub3d->player->plane[0] * ((2 * i / (double)cub3d->data->resolution[0]) - 1));
    ray[1] = cub3d->player->dir[1] + (cub3d->player->plane[1] * ((2 * i / (double)cub3d->data->resolution[0]) - 1));
    set_dda_value(dda_value, ray, cub3d->player);
    side = hit_wall(dda_value, worldMap);
    dda_value->perpWallDist = (dda_value->map[side] - cub3d->player->pos[side] + (1 - dda_value->step[side]) / 2) / ray[side];
    if (!side)
      wallX = cub3d->player->pos[1] + dda_value->perpWallDist * ray[1];
    else
      wallX = cub3d->player->pos[0] + dda_value->perpWallDist * ray[0];
    wallX -= floor(wallX);
    my_mlx_pixel_put(cub3d, dda_value, texture, i, wallX);
    i++;
  }
  mlx_put_image_to_window(cub3d->mlx, cub3d->window, cub3d->image, 0, 0);
  free(dda_value);
  return (1);
}