#include "parse.h"

static int  set_wall_texture_path(t_parse *data, char *line, int flag)
{
    if (!new_array(data->texture + flag, &line))
        return (error_check('p', 2));
    if ((int)*line)
        return (error_check('p', 3));
    return (1);
}

static int  set_resolution(t_parse *data, char *line)
{
    parse_atoi(&line, 0, data->resolution);
    parse_atoi(&line, 0, data->resolution + 1);
    if (!data->resolution[0] || !data->resolution[1] || (int)*line)
        return (error_check('p', 3));
    return (1);
}

static int  set_color(t_parse *data, char *line, int flag)
{
    int tmp;

    tmp = 0;
    tmp += parse_atoi(&line, 1, &(data->color[flag - 6][0]));
    tmp += parse_atoi(&line, 1, &(data->color[flag - 6][1]));
    tmp += parse_atoi(&line, 1, &(data->color[flag - 6][2]));
    if (tmp != 2 || (int)*line)
        return (error_check('p', 3));
    return (1);
}

int set_identifier(t_parse *data, char *line, int flag)
{
    char    *save;
    int     result;

    save = line;
    result = 0;
    while (*line != ' ')
        line++;
    while (*line == ' ')
        line++;
    if (flag >= 0 && flag <= 4)
        result = set_wall_texture_path(data, line, flag);
    else if (flag == 5)
        result = set_resolution(data, line);
    else if (flag == 6 || flag == 7)
        result = set_color(data, line, flag);
    free(save);
    return (result);
}