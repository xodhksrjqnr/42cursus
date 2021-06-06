/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taewakim <taewakim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/04 20:54:42 by taewakim          #+#    #+#             */
/*   Updated: 2021/06/04 21:30:01 by taewakim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H

# include <fcntl.h>
# include "get_next_line.h"
# include <math.h>
# include <stdio.h>

typedef struct	s_parse
{
	int			resol[2];// [0] = x, [1] = y
	int			col_size;
	int			map_width;
	int			location[2];
	int			color[2];
	int			col_max;
	char		direction;
	char		**worldmap;
	char		**texture; // texture[0] = NO, [1] = SO, [2] = WE, [3] = EA, [4] = S
}				t_parse;

char			*parse(t_parse **data, char *map_path, unsigned char check);
void			free_data(t_parse *data);

char			*set_identifier(t_parse *data, char *line, int flag);

char			*set_map(t_parse *data, char *line);
char			*resize_map(t_parse *data, unsigned char check);
char			*map_validation(t_parse *data, int max);

int				parse_atoi(char **line, int *target);
int				check_length(char *line);
int				new_array(char **target, char **line);
char			find_chr(const char *str, char target);
char			*new_chr_array(char chr, int size);

void			data_print(t_parse *data);

#endif
