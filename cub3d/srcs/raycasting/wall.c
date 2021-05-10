#include "raycasting.h"

void    draw_point(t_dda *dda, t_parse *data)
{
    int height;
    int screen_height;

    height = (int)(data->resolution[1] / dda->perpWallDist);
    screen_height = data->resolution[1];
    *dda->point = (-height + screen_height) / 2;
    *(dda->point + 1) = (height + screen_height) / 2;
}

char    *select_texture(t_texture **texture, t_dda **dda)
{
    t_texture   **cur;

    cur = &((*dda)->cur);
    *cur = texture[3];
    if (!((*dda)->side) && (*dda)->ray[0] < 0)
        *cur = texture[0];
    else if (!(*dda)->side && (*dda)->ray[0] > 0)
        *cur = texture[1];
    else if ((*dda)->side == 1 && (*dda)->ray[1] < 0)
        *cur = texture[2];
    (*cur)->ratio[1] = ((*cur)->size[1] - 1) / (double)((*dda)->point[1] - (*dda)->point[0] + 1);
    return ((*cur)->adr + (int)((*dda)->wallX * ((*cur)->size[0] - 1)) * ((*cur)->bpp / 8));
}