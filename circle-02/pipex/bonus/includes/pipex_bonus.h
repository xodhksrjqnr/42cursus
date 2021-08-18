#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# include <unistd.h>
# include <fcntl.h>
# include "../../libft/libft.h"
# include "get_next_line_bonus.h"

# include <stdio.h>

# define CHILD 0

char    redirection_in(char *file);
char    redirection_out(char *file, int flag);
char	connect_pipe(int *fd, int io);
char    free_split(char **target);
char	run_cmd(char *cmd, char **path);

char	heredoc_read_stdin(char *limiter, int leng);

#endif