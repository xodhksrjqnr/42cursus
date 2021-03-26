#ifndef SET_UTILS_H
# define SET_UTILS_H

# include <fcntl.h>
# include "list.h"
# include "get_next_line.h"

typedef struct	s_list
{
	t_r	*R;
	t_a	*A;
	t_c	*c;
	t_l	*l;
	t_sp	*sp;
	t_pl	*pl;
	t_sq	*sq;
	t_cy	*cy;
	t_tr	*tr;
}	t_list;

t_list	*init_list(void);
void	check_object(char *line, t_list *list);
void	list_free(t_list *list);

#endif
