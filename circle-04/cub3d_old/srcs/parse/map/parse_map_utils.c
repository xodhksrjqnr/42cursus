/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taewakim <taewakim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/04 20:53:13 by taewakim          #+#    #+#             */
/*   Updated: 2021/06/04 21:00:23 by taewakim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

int			resize_col(char ***target, int max)
{
	char	**save;
	int		i;

	save = *target;
	*target = malloc(sizeof(char *) * (max + 1));
	if (!*target)
		return (error_check('p', 4));
	i = 0;
	while (i < max)
	{
		*(*target + i) = *(save + i);
		i++;
	}
	*(*target + max) = 0;
	free(save);
	return (1);
}

static int	around_check(char **map, int row, int col, int max)
{
	int	i;
	int	j;
	int	end;

	j = -1;
	end = 2;
	if (!col)
		j = 0;
	if (col == max - 1)
		end = 1;
	while (j < end)
	{
		i = -1;
		while (i < 2)
		{
			if (map[col + j][row + i] == ' ')
				return (0);
			i++;
		}
		j++;
	}
	return (1);
}

static int	map_validation(t_parse *data, int col, int row, int i)
{
	while (++col < data->cursize)
	{
		row = -1;
		while (++row < data->maxlength + 2)
		{
			if (find_chr("02WENS", data->worldmap[col][row]))
			{
				if (!around_check(data->worldmap, row, col, data->cursize))
					return (error_check('p', 6));
				if (!find_chr("02", data->worldmap[col][row]))
				{
					data->location[0] = row;
					data->location[1] = col;
					data->worldmap[col][row] = '0';
				}
				if (data->worldmap[col][row] == '2')
					if (!set_sprite(data->sprite, col, row, i++))
						return (0);
			}
		}
	}
	return (1);
}

int			resize_row(t_parse *data)
{
	char	*save;
	int		i;
	char	**tmp;

	tmp = data->worldmap;
	while (*tmp)
	{
		save = malloc(data->maxlength + 3);
		if (!save)
			return (error_check('p', 4));
		*save = ' ';
		i = 0;
		while (*(*tmp + i))
		{
			*(save + 1 + i) = *(*tmp + i);
			i++;
		}
		while (i < data->maxlength + 1)
			*(save + 1 + i++) = ' ';
		*(save + 1 + i) = 0;
		free(*tmp);
		*tmp = save;
		tmp++;
	}
	return (map_validation(data, -1, 0, 0));
}
