#include "parse.h"

static int	around_check(char **map, int col, int row)
{
	int	i;
	int	j;

	i = -2;
	while (++i < 2)
	{
		j = -2;
		while (++j < 2)
			if (map[col + i][row + j] == ' ')
				return (0);
	}
	return (1);
}

static char	*set_elem(t_parse *data, int col, int row, int *i)
{
	char	cur;

	cur = data->worldmap[col][row];
	if (cur == ' ' || cur == '1')
		return (0);
	else if (cur == '2')
	{
		if (!init_sprite(data->sprite, col, row, *i))
			return ("sprite malloc failed");
		(*i)++;
	}
	else if (cur != '0')
	{
		if (data->direction)
			return ("reduplication error");
		data->direction = cur;
		data->location[0] = row;
		data->location[1] = col;
		data->worldmap[col][row] = '0';
	}
	if (!around_check(data->worldmap, col, row))
		return ("invalid map");
	return (0);
}

char		*map_validation(t_parse *data, int max)
{
	int		col;
	int		row;
	int		i;
	char	*error;

	col = 0;
	i = 0;
	while (++col < data->col_size + 1)
	{
		row = 0;
		while (++row < max - 1)
		{
			if (!find_chr(" 012WENS", data->worldmap[col][row]))
				return ("invalid map");
			error = set_elem(data, col, row, &i);
			if (error)
				return (error);
		}
	}
	return (0);
}
