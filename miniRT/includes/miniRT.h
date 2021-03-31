#ifndef MINIRT_H
# define MINIRT_H

# include <stdio.h>
# include "mlx.h"
# include "set_utils.h"

typedef struct	s_RT
{
	void	*mlx;
	void	*window;
	/*void	*image;
	char	*img_adr;
	int	bpp;
	int	line_length;
	int	endian;*/
}	t_RT;

#endif
