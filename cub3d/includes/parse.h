#ifndef PARSE_H
# define PARSE_H

# include <fcntl.h>
# include "error.h"
# include "get_next_line.h"
# include "sprite.h"

typedef struct	s_parse
{
	int			resolution[2];// [0] = x, [1] = y
	int			cursize;
	int			maxsize;
	int			maxlength;
	int			sprite_num;
	int			location[2];
	char		direction;
	char		**worldmap;
	char		**texture; // texture[0] = NO, [1] = SO, [2] = WE, [3] = EA, [4] = S
	int			color[2][3]; // color[0] = floor, [1] = ceilling
	t_sprite	**sprite;
}				t_parse;

t_parse	*init_parse(void);
t_parse	*parse(void);

//parse_identifier
int		set_identifier(t_parse *data, char *line, int flag);

//parse_map
int		set_map(t_parse *data, char *line);
int		resize_col(char ***target, int max);
int		resize_row(t_parse *data);
t_parse	*resize_map(t_parse *data);

//parse_utils_basic
int		parse_atoi(char **line, int flag, int *target);
int		check_length(char *line);
int		new_array(char **target, char **line);
char	find_chr(const char *str, char target);
char	*new_space_array(int size);

#endif