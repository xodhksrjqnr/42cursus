#ifndef LIBVEC_H
# define LIBVEC_H

# include <math.h>
# include <stdlib.h>
# define rotation_value 15 * 3.14 / 180

typedef struct	s_vec
{
	float	x;
	float	y;
	float	z;
	char	state;
}		t_vec;

t_vec	*init_vec(void);
void	add_vec(t_vec *v1, t_vec *v2);
void	sub_vec(t_vec *v1, t_vec *v2);
void	rotation_trans(t_vec *v, char axle);
void	scaling_trans(t_vec *v, float x, float y, float z);

# endif