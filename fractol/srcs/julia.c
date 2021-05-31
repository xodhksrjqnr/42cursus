#include "main.h"

int	julia(double r, double i, t_data *d)
{
	int		j;
	double	tmp;

	j = 0;
	while (j < d->max && r * r + i * i < 4)
	{
		tmp = r;
		r = tmp * tmp - i * i + d->cr;
		i = 2 * tmp * i + d->ci;
		j++;
	}
	return (j);
}
