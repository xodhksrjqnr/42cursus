/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taewakim <taewakim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/31 12:14:43 by taewakim          #+#    #+#             */
/*   Updated: 2021/01/05 03:29:09 by taewakim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char		*add_string(char *s1, char *s2)
{
	char	*result;

	if (!(result = ft_strjoin(s1, s2)))
		return (0);
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
		if (!(*line = ft_strdup(*save, len)))
			return (-1);
		if (!(tmp = ft_strdup(*save + len + 1, ft_strlen(*save) - len - 1)))
			return (-1);
		free(*save);
		*save = tmp;
		return (1);
	}
	if (!(*line = add_string(*line, *save)))
		return (-1);
	*save = 0;
	return (0);
}

static int		check_line(char *buff, int len, char **save, int size)
{
	if (!(*save = ft_strdup(buff + len + 1, size - len - 1)))
		return (-1);
	return (1);
}

int				get_next_line(int fd, char **line)
{
	char			*buff;
	static char		*save;
	int				len;
	int				size;

	if (fd < 0 || !line || BUFFER_SIZE <= 0 || !(*line = ft_strdup("", 0))
			|| !(buff = (char *)malloc(BUFFER_SIZE + 1)))
		return (-1);
	if (save)
		if ((size = check_save(&save, line)) != 0)
			return (size);
	buff[BUFFER_SIZE] = 0;
	while ((size = read(fd, buff, BUFFER_SIZE)) > 0)
	{
		len = ft_strchr(buff, size) - buff;
		if (!(save = ft_strdup(buff, len)))
			return (-1);
		if (!(*line = add_string(*line, save)))
			return (-1);
		save = 0;
		if (buff[len] == '\n')
			return (check_line(buff, len, &save, size));
	}
	return (size);
}
