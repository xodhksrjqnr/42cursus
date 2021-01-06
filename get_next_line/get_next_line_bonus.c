#include "get_next_line.h"

static int			find_fd(int fd, t_fdlist **fdl, t_fdlist **cur)
{
	if (!*fdl)
	{
		*fdl = ft_newfd(fd);
		*cur = *fdl;
	}
	else
	{
		while ((*fdl)->fd != fd && (*fdl)->next)
			*fdl = (*fdl)->next;
		if ((*fdl)->fd == fd)
			*cur = *fdl;
		else
		{
			*fdl = ft_newfd(fd);
			*cur = *fdl;
		}
	}
	if (!*cur)
		return (0);
	return (1);
}

static int			set_result(char **line, t_fdlist *cur, int size)
{
	char	*div;
	char	*tmp;

	if (size == -1 || !(div = ft_strchr(cur->save)))
		return (-1);
	tmp = cur->save;
	if (!*cur->save)
	{
		*line = ft_strdup("", 0);
		if (!(cur->save = ft_strdup("", 0)) || !*line)
			return (-1);
		free(tmp);
		return (0);
	}
	if (!(*line = ft_strdup(cur->save, div - cur->save)))
		return (-1);
	if (!*div)
	{
		cur->save = ft_strdup("", 0);
		free(tmp);
		return (((cur->save == 0) ? -1 : 0));
	}
	cur->save = ft_strdup(div + 1, ft_strlen(div + 1));
	free(tmp);
	return (((cur->save == 0) ? -1 : 1));
}

int					get_next_line(int fd, char **line)
{
	static t_fdlist		*fdlist;
	t_fdlist			*cur;
	char				*buff;
	char				*tmp;
	int					size;

	if (fd < 0 || BUFFER_SIZE <= 0 || !line || !(find_fd(fd, &fdlist, &cur))
			|| !(buff = (char *)malloc(BUFFER_SIZE + 1)))
		return (-1);
	while ((size = read(fd, buff, BUFFER_SIZE)) > 0)
	{
		buff[size] = 0;
		tmp = ft_strdup(buff, size);
		cur->save = ft_strjoin(cur->save, tmp);
		if (!(tmp = ft_strchr(cur->save)))
			return (-1);
		if (*tmp)
		{
			free(buff);
			return (set_result(line, cur, size));
		}
	}
	free(buff);
	return (set_result(line, cur, size));
}
