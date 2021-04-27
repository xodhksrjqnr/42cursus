#ifndef PLAYER_H
# define PLAYER_H

# include <stdlib.h>
# include <math.h>

typedef struct s_player
{
    double  pos[2];
    double  dir[2];
    double  plane[2];
    int     key[6];
}   t_player;

t_player    *set_player(int *location, char dir);
void        eyesight_LR(t_player *player, double seta);
void        move_WS(t_player *player, char **worldMap, double flag);
void        move_AD(t_player *player, char **worldMap, double flag);

#endif