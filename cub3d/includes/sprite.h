#ifndef SPRITE_H
# define SPRITE_H

# include <stdlib.h>
# include <math.h>
#include <stdio.h>

typedef struct	s_sprite
{
	int		x;
	int		y;
	double	dist;
}				t_sprite;

int		set_sprite(t_sprite **sprite, int col, int row, int num);
void	draw_target(char **dst, int *drawpoint, int leng, int leng2
, double *ratio);
int     check_vaild(double *cur, double *dir, double target_dist, double dist);
int     check_fov(double *dir, double *cur, double dist, double fov);

void	set_sprite_dist(int num, t_sprite **target
, double *player_pos);
void	sort_sprite(t_sprite ***sprite, int size);
void	trans_location(double *location, double *dir, double *plane);
void	set_draw_point(int *resolution, double *location, int *drawpoint);
void	set_ratio(int *size, int *point, int *leng_x, double *ratio);

#endif