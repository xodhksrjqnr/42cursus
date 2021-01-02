/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taewakim <taewakim@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/31 12:14:43 by taewakim          #+#    #+#             */
/*   Updated: 2021/01/02 15:18:33 by taewakim         ###   ########.fr       */
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

	if (fd <= 0 || !line || result = (char *)malloc(1))
		return (-1);
	*result = 0;
	while (read(fd, buff, BUFFER_SIZE))
	{
		len = ft_strchr(buff) - buff + 1;
		add = ft_strdup(buff, len);
		if (save)
			add = add_string(save, add);
		result = add_string(result, add);
		if (len != BUFFER_SIZE)
		{
			*line = result;
			save = ft_strdup(buff + len, BUFFER_SIZE - len);
			return (1);
		}
	}
	return (0);
}
