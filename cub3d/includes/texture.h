#ifndef TEXTURE_H
# define TEXTURE_H

# include "mlx.h"
# include <math.h>
# include <stdlib.h>

typedef struct	s_texture
{
	void	*image;
	char	*adr;
	int		bpp;
	int		leng;
	int		endi;
	int		size[2];
	double	ratio[2];
}				t_texture;

t_texture		**set_texture(void *mlx, char **list);
unsigned int	t_color(char *ref, int y, t_texture *texture);
void			free_texture(t_texture **texture, void *mlx);

#endif
