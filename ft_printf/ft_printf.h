#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

typedef struct		s_list
{
	char			type;
	char			left;
	char			zero;
	char			dot;
	char			star;
	int				width;
	char			*next;
}					t_list;
t_list				*newformat(void);

#endif
