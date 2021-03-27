#ifndef LIST_H
# define LIST_H

# include <stdio.h>
# include "libvec.h"

//utils
int	list_atoi(char **line, unsigned int *num);
int	cal_color(char **line, unsigned int *color);
void	list_atoi_f(char **line, float *num);
int	cal_loca(char **line, float *x, float *y, float *z);

//resolution
typedef struct	s_r
{
	int	x;
	int	y;
}	t_r;

t_r	*init_r(void);
int	parse_R(char *line, t_r **R);

//ambient
typedef struct	s_a
{
	float		range;
	unsigned int	color;
}	t_a;

t_a	*init_a(void);
int	parse_A(char *line, t_a **A);

//camera
typedef struct	s_c
{
	float	x;
	float	y;
	float	z;
	t_vec	*v;
	float	fov;
	void	*next;
}	t_c;

t_c	*init_c(void);
//void	free_c(t_c *c);
int	parse_c(char *line, t_c *c);

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
//void	free_l(t_l *l);
int	parse_l(char *line, t_l *l);

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
//void	free_sp(t_sp *sp);
int	parse_sp(char *line, t_sp *sp);

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
//void	free_pl(t_pl *pl);
int	parse_pl(char *line, t_pl *pl);

//square
typedef struct	s_sq
{
	float		x;
	float		y;
	float		z;
	float		length;
	t_vec		*v;
	unsigned int	color;
	void		*next;
}	t_sq;

t_sq	*init_sq(void);
//void	free_sq(t_sq *sq);
int	parse_sq(char *line, t_sq *sq);

//cylinder
typedef struct	s_cy
{
	float		x;
	float		y;
	float		z;
	t_vec		*v;
	float		r;
	float		h;
	unsigned int	color;
	void		*next;
}	t_cy;

t_cy	*init_cy(void);
//void	free_cy(t_cy *cy);
int	parse_cy(char *line, t_cy *cy);

//triangle
typedef struct	s_tr
{
	float		x1;
	float		y1;
	float		z1;
	float		x2;
	float		y2;
	float		z2;
	float		x3;
	float		y3;
	float		z3;
	unsigned int	color;
	void		*next;
}	t_tr;

t_tr	*init_tr(void);
//void	free_tr(t_tr *tr);
int	parse_tr(char *line, t_tr *tr);

#endif
