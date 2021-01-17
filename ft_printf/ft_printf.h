#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include "./libft/libft.a"

typedef struct	s_list
{
	char		type;
	char		minus;
	char		zero;
	char		dot;
	char		star;
	int			len;
	int			first;
	int			second;
	char		*next;
}				t_list;
t_list			*make_parse(const char *s);
int				err_check(const char *s);
int				print_c(t_list *list, va_list ap);
int				print_s(t_list *list, va_list ap);
int				print_p(t_list *list, va_list ap);
int				print_x(t_list *list, va_list ap);
int				print_d(t_list *list, va_list ap);

#endif
