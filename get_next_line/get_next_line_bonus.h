#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <unistd.h>
# include <stdlib.h>

typedef struct		s_fdlist
{
	char			*save;
	int				fd;
	struct s_fdlist *next;
}					t_fdlist;
int					get_next_line(int fd, char **line);
char				*ft_strchr(const char *s);
char				*ft_strdup(const char *s, size_t len);
char				*ft_strjoin(char *s1, char *s2);
size_t				ft_strlen(const char *s);
t_fdlist			*ft_newfd(int fd);

#endif
