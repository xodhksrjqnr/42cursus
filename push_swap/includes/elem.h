#ifndef ELEM_H
# define ELEM_H

# include <stdlib.h>

typedef struct s_elem
{
    int             value;
    struct s_elem   *next;
    struct s_elem   *prev;
}              t_elem;

t_elem         *new_elem(int num);
t_elem         *sub_elem(t_elem **stack);
void           add_elem(t_elem **stack, t_elem **new_elem);

#endif