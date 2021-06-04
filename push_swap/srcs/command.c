#include "push_swap.h"

void    swap_stack(t_elem **stack, char flag)
{
    t_elem  *tmp;

    if (!*stack)
        return ;
    else if (!(*stack)->next || *stack == (*stack)->next)
        return ;
    tmp = sub_elem(stack);
    *stack = (*stack)->next;
    add_elem(stack, &tmp);
    *stack = (*stack)->prev->prev;
    print_command("s", flag, 1);
}

void    move_elem(t_elem **stack_1, t_elem **stack_2, char flag)
{
    t_elem  *tmp;

    if (!*stack_1)
        return ;
    tmp = sub_elem(stack_1);
    add_elem(stack_2, &tmp);
    *stack_2 = (*stack_2)->prev;
    print_command("p", flag, 1);
}

void    rotate_stack(t_elem **stack, char flag)
{
    if (!*stack)
        return ;
    *stack = (*stack)->next;
    print_command("r", flag, 1);
}

void    reverse_rotate_stack(t_elem **stack, char flag)
{
    if (!*stack)
        return ;
    *stack = (*stack)->prev;
    print_command("rr", flag, 2);
}

void    print_command(char *command, char flag, int leng)
{
    if (!flag)
        return ;
    write(1, command, leng);
    if (flag == 1)
        write(1, "a", 1);
    else if (flag == 2)
        write(1, "b", 1);
    else if (flag == 3)
        write(1, command, 1);
    write(1, "\n", 1);
}