#include "player.h"

t_player    *set_player(int *location, char dir)
{
    t_player    *player;
    double      seta;

    player = malloc(sizeof(t_player));
    if (!player)
        return (0);
    player->pos[0] = (double)*(location + 1);
    player->pos[1] = (double)*location;
    player->dir[0] = -1;
    player->dir[1] = 0;
    player->plane[0] = 0;
    player->plane[1] = 0.66;
    player->fov = fabs(atan(player->plane[1]) * 180 / 3.14);
    seta = 0;
    if (dir == 'W')
        seta = 90;
    else if (dir == 'S')
        seta = 180;
    else if (dir == 'E')
        seta = -90;
    eyesight_lr(player, seta);
    return (player);
}

void    eyesight_lr(t_player *player, double seta)
{
    double  tmp;

    seta *= 1 * 3.14 / 180;
    tmp = player->dir[0];
    player->dir[0] = player->dir[0] * cos(seta) - player->dir[1] * sin(seta);
    player->dir[1] = tmp * sin(seta) + player->dir[1] * cos(seta);
    tmp = player->plane[0];
    player->plane[0] = player->plane[0] * cos(seta) - player->plane[1] * sin(seta);
    player->plane[1] = tmp * sin(seta) + player->plane[1] * cos(seta);
}

void    move_ws(t_player *player, char **worldmap, double flag)
{
    flag *= 0.13;
    if((worldmap[(int)(player->pos[0] + player->dir[0] * flag)][(int)player->pos[1]]) == '0')
        player->pos[0] += player->dir[0] * flag;
    if((worldmap[(int)(player->pos[0])][(int)(player->pos[1] + player->dir[1] * flag)]) == '0')
        player->pos[1] += player->dir[1] * flag;
}

void    move_ad(t_player *player, char **worldmap, double flag)
{
    double  tmpX;
    double  tmpY;
    double  seta;

    seta = 90 * 3.14 / 180;
    tmpX = player->dir[0] * cos(seta) - player->dir[1] * sin(seta);
    tmpY = player->dir[0] * sin(seta) + player->dir[1] * cos(seta);
    flag *= 0.13;
    if((worldmap[(int)(player->pos[0] + tmpX * flag)][(int)player->pos[1]]) == '0')
        player->pos[0] += tmpX * flag;
    if((worldmap[(int)(player->pos[0])][(int)(player->pos[1] + tmpY * flag)]) == '0')
        player->pos[1] += tmpY * flag;
}