#include "parse.h"

int resize_col(char ***target, int max)
{
    char    **save;
    int     i;

    save = *target;
    *target = malloc(sizeof(char *) * (max + 1));
    if (!*target)
        return (error_check('p', 4));
    i = 0;
    while (i < max)
    {
        *(*target + i) = *(save + i);
        i++;
    }
    *(*target + max) = 0;
    free(save);
    return (1);
}

static int  around_check(char **map, int row, int col, int max)
{
    int i;
    int j;
    int end;

    j = -1;
    end = 2;
    if (!col)
        j = 0;
    if (col == max - 1)
        end = 1;
    while (j < end)
    {
        i = -1;
        while (i < 2)
        {
            if (map[col + j][row + i] == ' ')
                return (0);
            i++;
        }
        j++;
    }
    return (1);
}

static int  map_validation(t_parse *data)
{
    int     row;
    int     col;

    col = 0;
    while (col < data->cursize)
    {
        row = 0;
        while (row < data->maxlength + 2)
        {
            if (find_chr("02WENS", data->worldMap[col][row]))
            {
                if (!around_check(data->worldMap, row, col, data->cursize))
                    return (error_check('p', 6));
                if (data->worldMap[col][row] != '0' && data->worldMap[col][row] != '2')
                {
                    data->location[0] = row;
                    data->location[1] = col;
                    data->worldMap[col][row] = '0';
                }
            }
            row++;
        }
        col++;
    }
    return (1);
}

int resize_row(t_parse *data)
{
    char    *save;
    int     i;
    char    **tmp;

    tmp = data->worldMap;
    while (*tmp)
    {
        save = malloc(data->maxlength + 3);
        if (!save)
            return (error_check('p', 4));
        *save = ' ';
        i = 0;
        while (*(*tmp + i))
        {
            *(save + 1 + i) = *(*tmp + i);
            i++;
        }
        while (i < data->maxlength + 1)
            *(save + 1 + i++) = ' ';
        *(save + 1 + i) = 0;
        free(*tmp);
        *tmp = save;
        tmp++;
    }
    return (map_validation(data));
}