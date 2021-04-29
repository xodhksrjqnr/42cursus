#include "error.h"

static char    error_type(int flag)
{
    if (!flag)
        printf("malloc error!!");
    else if (flag == 1)
        printf("invalid rule in .cub file!!");
    return (0);
}

static void    parse_error(int errno)
{
    if (!errno)
        printf("%c (location : init_parse)\n", error_type(0));
    else if (errno == 1)
        printf("fcntl error!! (location : get_next_line)\n");
    else if (errno == 2 || errno == 3)
        printf("%c (location : parse_identifier)\n", error_type(errno - 2));
    else if (errno == 4 || errno == 5)
        printf("%c (location : resize_map)\n", error_type(errno - 4));
    else if (errno == 6)
        printf("%c (location : map_validation)\n", error_type(1));
}

int error_check(char flag, int errno)
{
    if (flag == 'p')
    {
        printf("Parsing failed : ");
        parse_error(errno);
    }
    return (0);
}