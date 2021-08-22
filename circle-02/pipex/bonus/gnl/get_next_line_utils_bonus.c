/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taewan <taewan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/31 12:15:10 by taewakim          #+#    #+#             */
/*   Updated: 2021/08/22 19:08:04 by taewan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen_g(const char *s)
{
	size_t	count;

	count = 0;
	while (*s++)
		count++;
	return (count);
}

char	*ft_strchr_g(const char *s)
{
	if (!s)
		return (0);
	while (*s && *s != '\n')
		s++;
	return ((char *)s);
}

char	*ft_strdup_g(const char *s, size_t len)
{
	char	*result;
	size_t	count;

	if (!s)
		return (0);
	result = (char *)malloc(len + 1);
	if (!result)
		return (0);
	result[len] = 0;
	count = 0;
	while (count < len)
		*(result + count++) = *s++;
	return (result);
}

char	*ft_strjoin_g(char *s1, char *s2)
{
	size_t	size;
	size_t	count;
	char	*result;
	char	*tmp;

	if (!s1 || !s2)
		return (0);
	size = ft_strlen_g(s1) + ft_strlen_g(s2) + 1;
	result = (char *)malloc(size);
	if (!result)
		return (0);
	result[size - 1] = 0;
	tmp = result;
	count = 0;
	while (*(s1 + count))
		*tmp++ = *(s1 + count++);
	count = 0;
	while (*(s2 + count))
		*tmp++ = *(s2 + count++);
	free(s1);
	free(s2);
	return (result);
}

t_fdlist	*ft_newfd(int fd)
{
	t_fdlist	*new;

	new = malloc(sizeof(t_fdlist));
	if (!new)
		return (0);
	new->save = 0;
	new->fd = fd;
	new->next = 0;
	return (new);
}
