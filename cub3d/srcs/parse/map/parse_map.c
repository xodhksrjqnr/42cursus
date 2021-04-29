#include "parse.h"

static int     map_line_check(t_parse *data, char *line)
{
    char    *save;
    char    chr;

    chr = 0;
    save = line;
    while ((*line >= 48 && *line <= 50) || *line == ' ' || (chr = find_chr("WESN", *line)))
    {
        if (data->direction && chr)
            break ;
        else if (!data->direction && chr)
        {
            data->direction = chr;
            chr = 0;
        }
        line++;
    }
    if (*line)
    {
        free(save);
        return (error_check('p', 5));
    }
    if (line - save > data->maxlength)
        data->maxlength = line - save;
    return (1);
}

int set_map(t_parse *data, char *line)
{
    if (!*line && !data->maxlength)
    {
        free(line);
        return (1);
    }
    if (!map_line_check(data, line))
        return (0);
    if (data->cursize == data->maxsize)
    {
        if (!resize_col(&data->worldMap, data->maxsize))
            return (0);
        data->maxsize += 5;
    }
    *(data->worldMap + data->cursize++) = line;
    return (1);
}

t_parse *resize_map(t_parse *data)
{
    if (!resize_col(&data->worldMap, data->cursize))
        return (0);
    if (!resize_row(data))
        return (0);
    return (data);
}