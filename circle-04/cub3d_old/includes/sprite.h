/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taewakim <taewakim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/04 20:55:06 by taewakim          #+#    #+#             */
/*   Updated: 2021/06/04 20:55:07 by taewakim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPRITE_H
# define SPRITE_H

# include <stdlib.h>
# include <math.h>
# define PI 180 / 3.14

typedef struct	s_sprite
{
	int		x;
	int		y;
	int		active;
	int		leng_x;
	int		point[4];
	double	dist;
	double	ratio[2];
}				t_sprite;

int				init_sprite(t_sprite **sprite, int col, int row, int num);
int				check_fov(t_sprite *target, double *dir, double fov
, double *cur);
int				check_active(t_sprite *target, double dist, int x);
char			*set_adr_x(t_sprite *target, int x, char *adr, int bpp);
char			*set_adr_y(char *ref, t_sprite *target, int y, int leng);

void			set_sprite_dist(t_sprite *target, double *player_pos);
void			sort_sprite(t_sprite ***sprite);
void			trans_location(double *location, double *dir, double *plane);
void			set_draw_point(int *resolution, double *location
, int *drawpoint);
void			set_ratio(int *size, t_sprite *sprite);

#endif
