#include "sprite.h"
#include <stdio.h>

int    set_sprite(t_sprite **sprite, int col, int row, int num)
{

    *(sprite + num) = malloc(sizeof(t_sprite));;
    if (!*(sprite + num))
        return (0);
    (*(sprite + num))->x = row;
    (*(sprite + num))->y = col;
    return (1);
}

int     check_fov(double *dir, double *cur, double dist, double fov)
{
    double  angle;

    angle = dir[0] * cur[0] + dir[1] * cur[1];
    angle /= sqrt(pow(dir[0], 2) + pow(dir[1], 2)) * sqrt(pow(cur[0], 2) + pow(cur[1], 2));
    angle = (acos(angle) * 180 / 3.14);
    if (angle <= fov + 5 && dist <= 1)
        return (1);
    return (0);
}

void    draw_target(char **dst, int *drawpoint, int leng, int leng2, double *ratio)
{
    int     y;
    char    *ref;

    y = drawpoint[2];
    while (y < drawpoint[3])
    {
        ref = *(dst + 1) + (int)((y - drawpoint[2]) * ratio[1]) * leng2;
        if (*(unsigned int *)ref)
            *(unsigned int *)(*dst + y * leng) = *(unsigned int *)ref;
        y++;
    }
}