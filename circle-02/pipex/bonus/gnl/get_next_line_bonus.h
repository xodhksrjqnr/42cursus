/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taewan <taewan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/07 13:35:07 by taewakim          #+#    #+#             */
/*   Updated: 2021/08/19 05:00:42 by taewan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# define BUFFER_SIZE 10

# include <unistd.h>
# include <stdlib.h>

typedef struct s_fdlist
{
	char			*save;
	int				fd;
	struct s_fdlist	*next;
}	t_fdlist;
int					get_next_line(int fd, char **line);
char				*ft_strchr_g(const char *s);
char				*ft_strdup_g(const char *s, size_t len);
char				*ft_strjoin_g(char *s1, char *s2);
size_t				ft_strlen_g(const char *s);
t_fdlist			*ft_newfd(int fd);

#endif
