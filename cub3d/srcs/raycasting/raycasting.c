#include "raycasting.h"

static void  set_dda_value(t_dda *dda, t_player *player, int resolution, int x)
{
    int i;

    i = 0;
    while (i < 2)
    {
        dda->map[i] = (int)(player->pos[i]);
        dda->point[i] = 0;
        dda->ray[i] = player->dir[i] + (player->plane[i] * ((2 * x / (double)resolution) - 1));
        dda->deltaDist[i] = fabs(1 / dda->ray[i]);
        dda->step[i] = -1;
        dda->sideDist[i] = player->pos[i] - dda->map[i];
        if (dda->ray[i] >= 0)
        {
            dda->step[i] = 1;
            dda->sideDist[i] = (-1 * dda->sideDist[i]) + 1.0;
        }
        dda->sideDist[i] *= dda->deltaDist[i];
        i++;
    }
    dda->side = 0;
}

static void hit_wall(t_dda *dda, char **worldmap, double *pos)
{
    int side;

    side = 0;
    while (worldmap[(int)dda->map[0]][(int)dda->map[1]] != '1')
    {
      if (dda->sideDist[1] < dda->sideDist[0])
        side = 1;
      else
        side = 0;
      dda->sideDist[side] += dda->deltaDist[side];
      dda->map[side] += dda->step[side];
    }
    dda->perpWallDist = (dda->map[side] - pos[side] + (1 - dda->step[side]) / 2) / dda->ray[side];
    dda->wallX = pos[1 - side] + dda->perpWallDist * dda->ray[1 - side];
    dda->wallX -= floor(dda->wallX);
    dda->side = side;
}

static void draw_sprite(t_cub3d *cub3d, t_player *player, int i, int x, double dist)
{
  int     lengX;
  int     point[4];//0,1 = x_s,x_e 2,3 = y_s,y_e
  double  cur[2];//0 = y, 1 = x
  double  ratio[2];
  char    *dst[2];

  while (--i >= 0)
  {
    cur[0] =  cub3d->data->sprite[i]->y - player->pos[0];
    cur[1] =  cub3d->data->sprite[i]->x - player->pos[1];
    if (!check_fov(player->dir, cur, cub3d->data->sprite[i]->dist - dist, player->fov))
      continue ;
    trans_location(cur, player->dir, player->plane);
    set_draw_point(cub3d->data->resolution, cur, point);
    if (x < point[0] || x > point[1])
      continue ;
    set_ratio(cub3d->texture[4]->size, point, &lengX, ratio);
    if (*point > cub3d->data->resolution[0] / 2)
        lengX = 0;
    *dst = cub3d->adr + x * cub3d->bpp / 8;
    *(dst + 1) = cub3d->texture[4]->adr + (int)((x - *point + lengX) * *ratio) * cub3d->texture[4]->bpp / 8;
    draw_target(dst, point, cub3d->leng, cub3d->texture[4]->leng, ratio);
  }
}

static void my_mlx_pixel_put(t_cub3d *cub3d, int x, char *ref, t_dda *dda)
{
  int     count;
  int     *color;
  char    *dst;
  char    *dst2;

  dst = cub3d->adr + x * (cub3d->bpp / 8);
  count = -1;
  while (++count < cub3d->data->resolution[1])
  {
    dst2 = dst + count * cub3d->leng;
    if (dda->point[0] <= count && count <= dda->point[1])
      *(unsigned int *)dst2 = texture_color(ref, count - dda->point[0], dda->cur);
    else
    {
      color = cub3d->data->color[1];
      if (count > dda->point[1])
        color = cub3d->data->color[0];
      *(unsigned int *)dst2 = (unsigned int)(color[0] + color[1] + color[2]);
    }
  }
  draw_sprite(cub3d, cub3d->player, cub3d->data->sprite_num, x, dda->perpWallDist);
}

int ray_casting(t_cub3d *cub3d, t_player *player, t_parse *data)
{
  int   x;
  t_dda *dda;

  dda = malloc(sizeof(t_dda));
  if (!dda)
      return (0);
  cub3d->image = mlx_new_image(cub3d->mlx, data->resolution[0], data->resolution[1]);
  cub3d->adr = mlx_get_data_addr(cub3d->image, &(cub3d->bpp), &(cub3d->leng), &(cub3d->endian));
  set_sprite_dist(cub3d->data->sprite_num, cub3d->data->sprite, cub3d->player->pos);
  sort_sprite(&cub3d->data->sprite, cub3d->data->sprite_num);
  x = 0;
  while (x < data->resolution[0])
  {
    set_dda_value(dda, player, data->resolution[0], x);
    hit_wall(dda, data->worldmap, player->pos);
    draw_point(dda, data);
    my_mlx_pixel_put(cub3d, x, select_texture(cub3d->texture, &dda), dda);
    x++;
  }
  mlx_put_image_to_window(cub3d->mlx, cub3d->window, cub3d->image, 0, 0);
  mlx_destroy_image(cub3d->mlx, cub3d->image);
  free(dda);
  return (1);
}