#ifndef CUB3D_H
# define CUB3D_H

# include "raycasting.h"

char	ft_strcmp(char *target);
char	*setting_program(t_cub3d **cub3d, char *map_path);
char	*map_path_str(char *str);
char	*make_bitmap_file(t_cub3d *cub3d);
void	free_cub3d(t_cub3d *cub3d);

#endif
