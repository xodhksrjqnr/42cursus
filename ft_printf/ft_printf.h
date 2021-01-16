#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>

# include <stdarg.h>
# include <unistd.h>

typedef struct	s_list
{
	char		type;
	char		miner;
	char		zero;
	char		dot;
	int			first;
	int			second;
	int			star;
	int			len;
	char		*next;
}				t_list;

#endif
