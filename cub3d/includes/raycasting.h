#ifndef RAYCASTING_H
# define RAYCASTING_H

# include "parse.h"
# include "player.h"
# include "mlx.h"

# include <stdio.h>

typedef struct s_cub3d
{
    void    **texture;
    void    *mlx;
    void    *window;
    void    *image;
    char    *adr;
    int     bpp;
    int     leng;
    int     endian;
    t_player    *player;
    t_parse     *data;
}   t_cub3d;

typedef struct  s_dda
{
    int     map[2];
    double  sideDist[2];
    double  deltaDist[2];
    double  step[2];
    double  perpWallDist;
}   t_dda;

typedef struct s_texture
{
    void    *image;
    char    *adr;
    int     bpp;
    int     leng;
    int     endian;
    double  ratio;
}   t_texture;


int    ray_casting(char **worldMap, t_cub3d *cub3d);

//key
int    key_press(int keycode, t_cub3d *cub3d);
int    key_release(int keycode, t_cub3d *cub3d);
int    active_apply(t_cub3d *cub3d);

//map
void            draw_point(int height, int screen_height, int *point);

//texture
void    set_image(t_cub3d *cub3d);
//int     draw_texture(int x, int y, int bpp, int leng);

#endif