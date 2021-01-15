#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

int		check_flags(const char *s, int *flags);
int		check_num(const char *s, int *num);
int		make_format(char type, int *flags, int num, int *count, va_list ap);
int		print_c(int *flags, int num, int *count, va_list ap);

void	*ft_memset(void *s, int c, size_t n);
void	ft_bzero(void *s, size_t n);
int		ft_atoi(const char *s);

#endif
