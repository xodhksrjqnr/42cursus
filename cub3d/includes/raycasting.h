#ifndef RAYCASTING_H
# define RAYCASTING_H

# include "parse.h"
# include "player.h"
# include "mlx.h"

# include <stdio.h>

typedef struct s_cub3d
{
    void    *mlx;
    void    *window;
    void    *image;
    char    *img_adr;
    int     bpp;
    int     line_leng;
    int     endian;
    t_player   *player;
    t_parse    *data;
}   t_cub3d;

typedef struct  s_dda
{
    int     map[2];
    double  sideDist[2];
    double  deltaDist[2];
    double  step[2];
    double  perpWallDist;
}   t_dda;

int    ray_casting(char **worldMap, t_cub3d *cub3d);

//key
int    key_press(int keycode, t_cub3d *cub3d);
int    key_release(int keycode, t_cub3d *cub3d);
int    active_apply(t_cub3d *cub3d);

//map
unsigned int    set_color(char **worldMap, int x, int y, int side);
int             draw_point(int height, int screen_height, int check);

#endif