#ifndef RAYCASTING_H
# define RAYCASTING_H

# include "parse.h"
# include "player.h"
# include "texture.h"

typedef struct s_cub3d
{
    void    *mlx;
    void    *window;
    void    *image;
    char    *adr;
    int     bpp;
    int     leng;
    int     endian;
    t_texture   **texture;
    t_player    *player;
    t_parse     *data;
}   t_cub3d;

typedef struct  s_dda
{
    int         map[2]; //아래 요소들 전부 0 = y, 1 = x
    int         point[2];
    int         side;
    double      ray[2];
    double      wallX;
    double      sideDist[2];
    double      deltaDist[2];
    double      step[2];
    double      perpWallDist;
    t_texture   *cur;
}   t_dda;

int    ray_casting(t_cub3d *cub3d, t_player *player, t_parse *data);

//key
int    key_press(int keycode, t_cub3d *cub3d);
int    key_release(int keycode, t_cub3d *cub3d);
int    active_apply(t_cub3d *cub3d);

//wall
void   draw_point(t_dda *dda, t_parse *data);
char   *select_texture(t_texture **texture, t_dda **dda);

#endif