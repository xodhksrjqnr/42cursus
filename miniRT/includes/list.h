#ifndef LIST_H
# define LIST_H

# include "libvec.h"

//resolution
typedef struct	s_r
{
	int	x;
	int	y;
}	t_r;

t_r	*init_r(void);
int	parse_R(char *line, t_list

//ambient
typedef struct	s_a
{
	float		range;
	unsigned int	color;
}	t_a;

t_a	*init_a(void);

//camera
typedef struct	s_c
{
	float	x;
	float	y;
	float	z;
	t_vec	*v;
	int	fov;
	void	*next;
}	t_c;

t_c	*init_c(void);
void	free_c(t_c *c);

//light
typedef struct	s_l
{
	float		x;
	float		y;
	float		z;
	float		range;
	unsigned int	color;
	void		*next;
}	t_l;

t_l	*init_l(void);

//sphere
typedef struct	s_sp
{
	float		x;
	float		y;
	float		z;
	float		r;
	unsigned int	color;
	void		*next;
}	t_sp;

t_sp	*init_sp(void);

//plane
typedef struct	s_pl
{
	float		x;
	float		y;
	float		z;
	t_vec		*v;
	unsigned int	color;
	void		*next;
}	t_pl;

t_pl	*init_pl(void);
void	free_pl(t_ql *ql);

//square
typedef struct	s_sq
{
	float		x;
	float		y;
	float		z;
	t_vec		*v;
	unsigned int	color;
	void		*next;
}	t_sq;

t_sq	*init_sq(void);
void	free_sq(t_sq *sq);

//cylinder
typedef struct	s_cy
{
	float		x;
	float		y;
	float		z;
	t_vec		*v
	float		r;
	float		h;
	unsigned int	color;
	void		*next;
}	t_cy;

t_cy	*init_cy(void);
void	free_cy(t_cy *cy);

//triangle
typedef struct	s_tr
{
	float		x1;
	float		y1;
	float		z1;
	float		y2;
	float		z2;
	float		x3;
	float		y3;
	float		z3;
	unsigned int	color;
	void		*next;
	t_tr;
}

t_tr	*init_tr(void);
void	free_tr(t_tr *tr);

#endif
