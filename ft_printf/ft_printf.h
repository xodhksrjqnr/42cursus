#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>

typedef struct		s_list
{
	char			type;
	char			left;
	char			zero;
	char			dot;
	char			wild;
	int				width;
}					t_list;
t_list				*newformat(void);

#endif
