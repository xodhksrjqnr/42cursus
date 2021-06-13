#include "pipex.h"

char    redirection_out(char *file)
{
    int fd;

    fd = open(file, O_RDWR | O_CREAT, 0644);
    if (fd < 0)
        return (0);
    dup2(fd, STDOUT_FILENO);
    close(fd);
    return (1);
}

char    redirection_in(char *file)
{
    int fd;

    fd = open(file, O_RDONLY);
    if (fd < 0)
        return (0);
    dup2(fd, STDIN_FILENO);
    close(fd);
    return (1);
}