#include "raycasting.h"

void draw_point(int height, int screen_height, int *point)
{
    *point = (-height + screen_height) / 2;
    if (*point < 0)
        *point = 0;
    *(point + 1) = (height + screen_height) / 2;
    if(*(point + 1) >= screen_height)
        *(point + 1) = screen_height - 1;
}