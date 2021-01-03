/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taewakim <taewakim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/31 12:14:43 by taewakim          #+#    #+#             */
/*   Updated: 2021/01/03 03:58:26 by taewakim         ###   ########.fr       */
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

int				get_next_line(int fd, char **line)
{
	char			buff[BUFFER_SIZE + 1];
	char			*result;
	char			*add;
	static char		*save;
	size_t			len;

	if (fd < 0 || !line || !(result = (char *)malloc(1))
			|| BUFFER_SIZE <= 0)
		return (-1);
	*result = 0;
	buff[BUFFER_SIZE] = 0;
	while (read(fd, buff, BUFFER_SIZE) > 0)
	{
		len = ft_strchr(buff) - buff;
		add = ft_strdup(buff, len);
		if (save)
		{
			add = add_string(save, add);
			save = 0;
		}
		result = add_string(result, add);
		if (len != BUFFER_SIZE || buff[BUFFER_SIZE - 1] == '\n')
		{
			*line = result;
			if (len != BUFFER_SIZE)
				save = ft_strdup(buff + len + 1, BUFFER_SIZE - len);
			return (1);
		}
	}
	return (0);
}
