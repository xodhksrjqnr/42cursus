#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# include <unistd.h>
# include <fcntl.h>
# include "../../libft/libft.h"

# define CHILD 0

char    redirection_in(char *file);
char    redirection_out(char *file);
char	connect_pipe(int *fd, int io);
char    free_split(char **target);
char	run_cmd(char *cmd, char **path);

#endif