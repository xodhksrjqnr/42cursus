#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <fcntl.h>

char    redirection_in(char *file);
char    redirection_out(char *file);

#endif