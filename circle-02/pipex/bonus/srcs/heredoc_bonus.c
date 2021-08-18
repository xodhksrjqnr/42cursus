#include "pipex_bonus.h"

char	heredoc_read_stdin(char *limiter, int leng)
{
	char	*line;
	int		result;
	int		fd[2];

	if (pipe(fd) == -1)
		return (0);
	while (1)
	{
		write(1, "pipe heredoc> ", 14);
		result = get_next_line(0, &line);
		if ((!result && !*line))
			break ;
		if (result < 0)
			return (0);
		if (!ft_strncmp(line, limiter, leng + 1))
			break ;
		write(fd[1], line, ft_strlen(line));
		write(fd[1], "\n", 1);
		free(line);
	}
	free(line);
	write(fd[1], "^Z", 1);
	if (!connect_pipe(fd, STDIN_FILENO))
		return (0);
	return (1);
}
