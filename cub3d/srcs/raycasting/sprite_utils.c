#include "sprite.h"

void    set_sprite_dist(int num, t_sprite **target, double *player_pos)
{
    int     i;
    double  rayx;
    double  rayy;

    i = 0;
    while (i < num)
    {
        rayy = (double)target[i]->y - player_pos[0];
        rayx = (double)target[i]->x - player_pos[1];
        target[i]->dist = sqrt(pow(rayy, 2) + pow(rayx, 2));
        i++;
    }
}

void    sort_sprite(t_sprite ***sprite, int size)
{
    int         i;
    int         j;
    int         min;
    t_sprite    *tmp;

    i = -1;
    while (++i < size - 1)
    {
        j = i;
        min = i;
        while (++j < size)
            if ((*(*sprite + j))->dist < (*(*sprite + min))->dist)
                min = j;
        tmp = *(*sprite + i);
        *(*sprite + i) = *(*sprite + min);
        *(*sprite + min) = tmp;
    }
}

void    trans_location(double *location, double *dir, double *plane)
{
    double  invDet;
    double  tmp;

    invDet = 1.0 / ((plane[1] * dir[0] - dir[1] * plane[0]));
    tmp = location[1];
    location[1] = invDet * (dir[0] * (double)location[1] - dir[1] * (double)location[0]);
    location[0] = invDet * (-plane[0] * (double)tmp + plane[1] * (double)location[0]);
}

void    set_draw_point(int *resolution, double *location, int *drawpoint)
{
    int     i;
    int     leng;
    int     screen_leng;

    i = 0;
    while (i < 4)
    {
        screen_leng = (int)(resolution[0] / 2) * (1 + location[1] / location[0]);
        if (i == 2)
            screen_leng = resolution[1] / 2;
        leng = abs((int)(resolution[1] / location[0]));
        drawpoint[i] = -leng / 2 + screen_leng;
        if(drawpoint[i] < 0)
            drawpoint[i] = 0;
        drawpoint[i + 1] = leng / 2 + screen_leng;
        if(drawpoint[i + 1] >= resolution[i / 2])
            drawpoint[i + 1] = resolution[i / 2] - 1;
        i += 2;
    }
}

void    set_ratio(int *size, int *point, int *leng_x, double *ratio)
{
    ratio[1] = (double)size[1] / (double)(point[3] - point[2] + 1);
    *leng_x = (int)((double)(point[3] - point[2] + 1) * (double)size[0] / (double)size[1]);
    ratio[0] = (double)size[0] / (double)*leng_x;
    *leng_x -= point[1] - point[0] + 1;
}