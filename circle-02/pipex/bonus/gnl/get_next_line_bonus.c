/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taewan <taewan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/07 13:33:52 by taewakim          #+#    #+#             */
/*   Updated: 2021/08/19 05:55:51 by taewan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static int	find_fd(int fd, t_fdlist **fdl, t_fdlist **cur)
{
	t_fdlist	*tmp;

	tmp = *fdl;
	if (!*fdl)
	{
		*fdl = ft_newfd(fd);
		*cur = *fdl;
	}
	else
	{
		while (tmp->fd != fd && tmp->next)
			tmp = tmp->next;
		if (tmp->fd == fd)
			*cur = tmp;
		else
		{
			tmp = ft_newfd(fd);
			tmp->next = *fdl;
			*fdl = tmp;
			*cur = tmp;
		}
	}
	if (!*cur)
		return (0);
	return (1);
}

static void	remove_curfd(int fd, t_fdlist **fdl)
{
	t_fdlist	*pre;
	t_fdlist	*tmp;

	pre = 0;
	tmp = *fdl;
	while (tmp->fd != fd)
	{
		pre = tmp;
		tmp = tmp->next;
	}
	if (pre)
	{
		pre->next = tmp->next;
		if (tmp->save)
			free(tmp->save);
		free(tmp);
	}
	else
	{
		tmp = (*fdl)->next;
		if ((*fdl)->save)
			free((*fdl)->save);
		free(*fdl);
		*fdl = tmp;
	}
}

static int	set_result(char **line, t_fdlist *cur, int size,
		t_fdlist **fdl)
{
	char	*div;
	char	*tmp;

	div = ft_strchr_g(cur->save);
	if (size == -1 || !div)
		return (-1);
	tmp = cur->save;
	*line = ft_strdup_g(cur->save, div - cur->save);
	if (!*line)
		return (-1);
	if (!*(cur->save) || !*div)
	{
		cur->save = 0;
		free(tmp);
		remove_curfd(cur->fd, fdl);
		return (0);
	}
	cur->save = ft_strdup_g(div + 1, ft_strlen_g(div + 1));
	if (!cur->save)
		return (-1);
	free(tmp);
	return (1);
}

static char	*check_validation(int fd, char **line, t_fdlist **cur,
	t_fdlist *fdlist)
{
	char	*buff;

	if (fd < 0 || BUFFER_SIZE <= 0 || !line || !(find_fd(fd, &fdlist, cur)))
		return (0);
	buff = (char *)malloc(BUFFER_SIZE + 1);
	if (!buff)
		return (0);
	if (!(*cur)->save)
		(*cur)->save = ft_strdup_g("", 0);
	return (buff);
}

int	get_next_line(int fd, char **line)
{
	static t_fdlist		*fdlist;
	t_fdlist			*cur;
	char				*buff;
	char				*tmp;
	int					size;

	buff = check_validation(fd, line, &cur, fdlist);
	if (!buff)
		return (-1);
	size = read(fd, buff, BUFFER_SIZE);
	while (size > 0)
	{
		buff[size] = 0;
		cur->save = ft_strjoin_g(cur->save, ft_strdup_g(buff, size));
		tmp = ft_strchr_g(cur->save);
		if (!tmp)
			return (-1);
		if (*tmp)
			break ;
		size = read(fd, buff, BUFFER_SIZE);
	}
	free(buff);
	if (size == -1)
		remove_curfd(cur->fd, &fdlist);
	return (set_result(line, cur, size, &fdlist));
}
