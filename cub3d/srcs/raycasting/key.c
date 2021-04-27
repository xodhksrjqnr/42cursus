#include "raycasting.h"

int key_press(int keycode, t_cub3d *cub3d)
{
    if (keycode == 53)
    {
      free(cub3d->player);
      free(cub3d);
      exit(0);
    }
    if (keycode >= 0 && keycode <= 2)
      cub3d->player->key[keycode] = 1;
    if (keycode == 13)
      cub3d->player->key[3] = 1;
    if (keycode == 123 || keycode == 124)
      cub3d->player->key[keycode - 119] = 1;
    return (0);
}

int  key_release(int keycode, t_cub3d *cub3d)
{
    if (keycode >= 0 && keycode <= 2)
      cub3d->player->key[keycode] = 0;
    if (keycode == 13)
      cub3d->player->key[3] = 0;
    if (keycode == 123 || keycode == 124)
      cub3d->player->key[keycode - 119] = 0;
    return (0);
}

int  active_apply(t_cub3d *cub3d)
{
    if (cub3d->player->key[0] == 1)
      move_AD(cub3d->player, cub3d->data->worldMap, 1);
    else if (cub3d->player->key[2] == 1)
      move_AD(cub3d->player, cub3d->data->worldMap, -1);
    if (cub3d->player->key[1] == 1)
      move_WS(cub3d->player, cub3d->data->worldMap, -1);
    else if (cub3d->player->key[3] == 1)
      move_WS(cub3d->player, cub3d->data->worldMap, 1);
    if (cub3d->player->key[4] == 1)
      eyesight_LR(cub3d->player, 1);
    else if (cub3d->player->key[5] == 1)
      eyesight_LR(cub3d->player, -1);
    ray_casting(cub3d->data->worldMap, cub3d);
    return (1);
}