#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

int		get_next_line(int fd, char **line);
char	*ft_strchr(const char *s, size_t len);
char	*ft_strdup(const char *s, size_t len);
char	*ft_strjoin(const char *s1, const char *s2);
size_t	ft_strlen(const char *s);

#endif
