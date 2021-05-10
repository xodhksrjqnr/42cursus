#ifndef PLAYER_H
# define PLAYER_H

# include <stdlib.h>
# include <math.h>

typedef struct	s_player
{
	double	fov;
	double	pos[2];//0 = y, 1 = x
	double	dir[2];//0 = y, 1 = x
	double	plane[2];//0 = y, 1 = x
	int		key[6];
}				t_player;

t_player	*set_player(int *location, char dir);
void		eyesight_lr(t_player *player, double seta);
void		move_ws(t_player *player, char **worldmap, double flag);
void		move_ad(t_player *player, char **worldmap, double flag);

#endif