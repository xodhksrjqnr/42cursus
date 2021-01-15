#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stddef.h>

int		check_flags(const char *s, int *flags);
int		check_num(const char *s, int *num);
void	make_format(char type, int *flags, int num, int *count);

void	*ft_memset(void *s, int c, size_t n);
void	ft_bzero(void *s, size_t n);
int		ft_atoi(const char *s);

#endif
