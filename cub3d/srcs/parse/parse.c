#include "parse.h"

t_parse     *init_parse(void)
{
    t_parse *data;
    int     i;

    data = malloc(sizeof(t_parse));
    if (!data)
        return (0);
    data->texture = malloc(sizeof(char *) * 5);
    data->worldmap = malloc(sizeof(char *) * 21);
    if (!data->texture || !data->worldmap)
        return (0);
    i = 0;
    while (i < 21)
        *(data->worldmap + i++) = 0;
    data->direction = 0;
    data->location[0] = 0;
    data->location[1] = 0;
    data->resolution[0] = 0;
    data->resolution[1] = 0;
    data->sprite_num = 0;
    data->cursize = 0;
    data->maxsize = 20;
    data->maxlength = 0;
    return (data);
}

static int check_flag(char *line)
{
    while (*line == ' ')
        line++;
    if (*line == 'N' && *(line + 1) == 'O' && *(line + 2) == ' ')
        return (0);
    else if (*line == 'S' && *(line + 1) == 'O' && *(line + 2) == ' ')
        return (1);
    else if (*line == 'W' && *(line + 1) == 'E' && *(line + 2) == ' ')
        return (2);
    else if (*line == 'E' && *(line + 1) == 'A' && *(line + 2) == ' ')
        return (3);
    else if (*line == 'S' && *(line + 1) == ' ')
        return (4);
    else if (*line == 'R' && *(line + 1) == ' ')
        return (5);
    else if (*line == 'F' && *(line + 1) == ' ')
        return (6);
    else if (*line == 'C' && *(line + 1) == ' ')
        return (7);
    return (8);
}

static int set_data(t_parse *data, char *line, char *check)
{
    int     flag;

    flag = check_flag(line);
    if (flag >= 0 && flag <= 7)
    {
        if ((*check >> flag & 1) == 1)
            return (error_check('p', 3));
        else
            *check += (unsigned int)pow(2, flag);
        return (set_identifier(data, line, flag));
    }
    else if (flag == 8)
        return (set_map(data, line));
    return (1);
}

t_parse *parse(void)
{
    t_parse *data;
    int     fd;
    int     result;
    char    check;
    char    *line;

    data = init_parse();
    if (!data)
        return (0);
    fd = open("./cubfile/test.cub", O_RDONLY);
    check = 0;
    while (1)
    {
        result = get_next_line(fd, &line);
        if (result == -1)
            return (0);//error_check('p', 1));
        if (!result && !*line)
            break ;
        if (!set_data(data, line, &check))
            return (0);
    }
    if (!*line)
        free(line);
    return (resize_map(data));
}