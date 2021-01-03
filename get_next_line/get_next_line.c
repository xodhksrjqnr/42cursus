/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taewakim <taewakim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/31 12:14:43 by taewakim          #+#    #+#             */
/*   Updated: 2021/01/03 20:04:54 by taewakim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char		*add_string(char *s1, char *s2)
{
	char	*result;

	result = ft_strjoin(s1, s2);
	free(s1);
	free(s2);
	return (result);
}

static int		check_save(char **save, char **line)
{
	int		len;
	char	*tmp;

	tmp = ft_strchr(*save, ft_strlen(*save));
	if (*tmp)
	{
		len = tmp - *save;
		*line = ft_strdup(*save, len);
		tmp = ft_strdup(*save + len + 1, ft_strlen(*save) - len - 1);
		free(*save);
		*save = tmp;
		return (1);
	}
	return (0);
}

int				get_next_line(int fd, char **line)
{
	char			buff[BUFFER_SIZE + 1];
	static char		*save;
	int				len;
	int				size;

	if (fd < 0 || !line || BUFFER_SIZE <= 0 || !(*line = ft_strdup("", 0)))
		return (-1);
	if (save)
	{
		if (check_save(&save, line))
			return (1);
		*line = add_string(*line, save);
		save = 0;
	}
	buff[BUFFER_SIZE] = 0;
	while ((size = read(fd, buff, BUFFER_SIZE)) > 0)
	{
		len = ft_strchr(buff, size) - buff;
		*line = add_string(*line, ft_strdup(buff, len));
		if (buff[len] == '\n')
		{
			save = ft_strdup(buff + len + 1, size - len - 1);
			return (1);
		}
	}
	return (size);
}
