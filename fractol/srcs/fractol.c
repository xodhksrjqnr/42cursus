#include "main.h"

static void	draw(int max, int flag, char *dst)
{
	unsigned int	color;

	if (flag == max)
		color = 0x00000000;
	else
		color = (0x00ff0000 + 0x00000f00 * (int)(flag * 0.5));
	*(unsigned int *)dst = color;
}

static char	set_value(t_data *d, int key)
{
	double	num;

	num = 1;
	if (key == 4)
		num = 1.2;
	else if (key == 5)
		num = 0.8;
	d->zoom *= num;
	d->f_ratio *= num;
	d->ratio_x *= num;
	d->ratio_y *= num;
	d->r = -d->zoom * 0.5;
	d->i = -d->zoom * 0.5;
	d->image = mlx_new_image(d->mlx, d->w, d->h);
	if (!d->image)
		return (free_data(d));
	d->adr = mlx_get_data_addr(d->image, &(d->bpp), &(d->leng), &(d->endian));
	d->bpp /= 8;
	return (1);
}

void		fractol(t_data *d, int key, int x, int y)
{
	int			i;
	double		r;
	int			(*frac)(double, double, t_data *);

	if (!set_value(d, key))
		exit(1);
	frac = julia;
	if (d->fractol == 'M')
		frac = mandelbrot;
	while (++y < d->h)
	{
		x = -1;
		r = d->r;
		i = 0;
		while (++x < d->w)
		{
			draw(d->max, frac(r, d->i, d), d->adr + x * d->leng + y * d->bpp);
			r += d->ratio_x;
		}
		d->i += d->ratio_y;
	}
	mlx_put_image_to_window(d->mlx, d->window, d->image, 0, 0);
	mlx_destroy_image(d->mlx, d->image);
}
