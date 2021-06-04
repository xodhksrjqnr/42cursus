/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taewakim <taewakim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/04 20:52:47 by taewakim          #+#    #+#             */
/*   Updated: 2021/06/04 21:02:43 by taewakim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycasting.h"

unsigned int	set_color(char **worldmap, int x, int y, int side)
{
	unsigned int	color;

	if (worldmap[x][y] == '1')
		color = 0x00FF0000;
	else if (worldmap[x][y] == '2')
		color = 0x0000FF00;
	else
		color = 0x00FFFF00;
	if (side == 1)
		color *= 0.5;
	return (color);
}

int				draw_point(int height, int screen_height, int check)
{
	int point;

	if (!check)
	{
		point = (-height + screen_height) / 2;
		if (point < 0)
			point = 0;
		return (point);
	}
	point = (height + screen_height) / 2;
	if (point >= screen_height)
		point = screen_height - 1;
	return (point);
}
