#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <fcntl.h>
# include "../libft/libft.h"

# define CHILD 0

char    redirection_in(char *file);
char    redirection_out(char *file);
void	connect_pipe(int *fd, int io);
void	run_cmd(char *cmd);

#endif