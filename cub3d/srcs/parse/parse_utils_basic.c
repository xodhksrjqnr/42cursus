#include "parse.h"

int    parse_atoi(char **line, int flag, int *target)
{
    int i;

    i = 0;
    while (**line >= '0' && **line <= '9' && i < 3)
    {
        if (flag == 1)
            i++;
        *target = (*target * 10) + **line - 48;
        (*line)++;
    }
    if (!flag)
    {
        while (**line == ' ')
            (*line)++;
    }
    else
    {
        if (**line == ',')
        {
            (*line)++;
            return (1);
        }
    }
    return (0);
}

int check_length(char *line)
{
    int length;

    length = 0;
    while (*line++)
        length++;
    return (length);
}

int new_array(char **target, char **line)
{
    int tmp;

    *target = malloc(check_length(*line) + 1);
    if (!*target)
        return (error_check('p', 2));
    tmp = 0;
    while (**line && **line != ' ')
    {
        *(*target + tmp++) = **line;
        (*line)++;
    }
    *(*target + tmp) = 0;
    return (1);
}

char    find_chr(const char *str, char target)
{
    while (*str)
    {
        if (*str == target)
            return (target);
        str++;
    }
    return (0);
}

char    *new_space_array(int size)
{
    char    *cur;
    int     i;

    cur = malloc(size + 1);
    if (!cur)
        return (0);
    i = 0;
    while (i < size)
        *(cur + i++) = ' ';
    *(cur + i) = 0;
    return (cur);
}