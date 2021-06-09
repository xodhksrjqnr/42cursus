#ifndef MAIN_BONUS_H
# define MAIN_BONUS_H

# define KEY_PRESS 2
# define KEY_RELEASE 3
# define XICON_PRESS 17

# include "raycasting_bonus.h"

char	*setting_program(t_cub3d **cub3d, char *map_path);
char	*map_path_str(char *str);
void	free_cub3d(t_cub3d *cub3d);

#endif
