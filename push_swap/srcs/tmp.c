#include "push_swap.h"

void print_tmp(t_elem *s1, t_elem *s2, char flag)
{
	t_elem  *save;
    t_elem  *t1;
    t_elem  *t2;

    t1 = s1;
    t2 = s2;
    if (flag)
    {
        t1 = s2;
        t2 = s1;
    }
    printf("a : ");
    if (t1)
    {
        save = t1;
        printf("%d ", save->value);
        save = save->next;
        while (save != t1 && save)
        {
            printf("%d ", save->value);
            save = save->next;
        }
    }
    printf("\n");
    printf("b : ");
    if (t2)
    {
        save = t2;
        printf("%d ", save->value);
        save = save->next;
        while (save != t2 && save)
        {
            printf("%d ", save->value);
            save = save->next;
        }
    }
    printf("\n");
}

void    check(char *buff, t_elem **s1, t_elem **s2)
{
    if (buff[0] == 'r' && buff[1] == 'r' && buff[2] == 'r')
    {
        reverse_rotate_stack(s1, 1);
        reverse_rotate_stack(s2, 2);
    }
    else if (buff[0] == 'r' && buff[1] == 'r' && buff[2] == 'a')
        reverse_rotate_stack(s1, 1);
    else if (buff[0] == 'r' && buff[1] == 'r' && buff[2] == 'b')
        reverse_rotate_stack(s2, 2);
    else if (buff[0] == 'r' && buff[1] == 'r')
    {
        rotate_stack(s1, 1);
        rotate_stack(s2, 2);
    }
    else if (buff[0] == 'r' && buff[1] == 'a')
        rotate_stack(s1, 1);
    else if (buff[0] == 'r' && buff[1] == 'b')
        rotate_stack(s2, 2);
    else if (buff[0] == 'p' && buff[1] == 'a')
        move_elem(s2, s1, 1);
    else if (buff[0] == 'p' && buff[1] == 'b')
        move_elem(s1, s2, 2);
    else if (buff[0] == 's' && buff[1] == 's')
    {
        swap_stack(s1, 1);
        swap_stack(s2, 2);
    }
    else if (buff[0] == 's' && buff[1] == 'a')
        swap_stack(s1, 1);
    else if (buff[0] == 's' && buff[1] == 'b')
        swap_stack(s2, 2);
}