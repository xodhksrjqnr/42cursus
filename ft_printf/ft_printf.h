#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <unistd.h>
#include <stdlib.h>

typedef struct	s_flags
{
	char		type;
	char		minus;
	char		zero;
	char		dot;
	int			first;
	int			second;
}				t_flags;
int				ft_printf(const char *s, ...);
int				check_combi(t_flags *cur);
int				print_form(t_flags cur, va_list ap, int *count);
void			print_percent(t_flags cur, int *count, char *tmp);
void			print_c(t_flags cur, char c, int *count, char *tmp);
void			print_s(t_flags cur, char *s, int *count, char *tmp);
void			print_p(t_flags cur, char *p, int *count, char *tmp);
void			print_num(t_flags cur, int n, int *count, char *tmp);
void			print_u(t_flags cur, int u, int *count, char *tmp);
void			print_x(t_flags cur, int x, int *count, char *tmp);

#endif
