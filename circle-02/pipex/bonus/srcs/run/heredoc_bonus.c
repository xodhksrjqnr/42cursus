#include "pipex_bonus.h"

void	check_heredoc(t_pipex_info *cmd_info, char *limiter)
{
	if (!ft_strncmp(cmd_info->infile, "here_doc", 9))
	{
		cmd_info->limiter = limiter;
		cmd_info->h_flag = 1;
	}
}

void	heredoc(t_pipex_info *cmd_info)
{
	char	*line;
	int		result;
	int		fd[2];

	if (pipe(fd) == -1)
		exit_program(NULL, strerror(PIPE_ERROR));
	while (1)
	{
		write(1, "heredoc> ", 9);
		result = get_next_line(0, &line);
		if ((!result && !*line))
			break ;
		if (result < 0)
			exit_program(NULL, "gnl is failed");
		if (!ft_strncmp(line, cmd_info->limiter, ft_strlen(cmd_info->limiter) + 1))
			break ;
		write(fd[1], line, ft_strlen(line));
		write(fd[1], "\n", 1);
		free(line);
	}
	free(line);
	connect_pipe(fd, STDIN_FILENO, cmd_info);
}
