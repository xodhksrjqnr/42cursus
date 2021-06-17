#include "pipex.h"

static void	child_pipe(int pipe_num, char **cmd, int prev_fd)
{
	pid_t	pid;
	int		fd[2];
	int		status;

	if (!pipe_num)
	{
		dup2(prev_fd, STDOUT_FILENO);
		close(prev_fd);
		run_cmd(*cmd);
	}
	pipe(fd);
	pid = fork();
	if (pid == CHILD)
	{
		if (pipe_num)
			child_pipe(pipe_num - 1, cmd - 1, fd[1]);
	}
	else
	{
		waitpid(pid, &status, 0);
		dup2(prev_fd, STDOUT_FILENO);
		close(prev_fd);
		connect_pipe(fd, STDIN_FILENO);
		run_cmd(*cmd);
	}
}

static void	pipex(int pipe_num, char *in_file, char *out_file, char **cmd)
{
	pid_t	pid;
	int		fd[2];
	int		status;

	if (!redirection_in(in_file))
		exit(1);
	pipe(fd);
	pid = fork();
	if (pid == CHILD)
	{
		if (pipe_num)
			child_pipe(pipe_num - 1, cmd - 1, fd[1]);
	}
	else
	{
		waitpid(pid, &status, 0);
		if (!redirection_out(out_file))
			exit(1);
		connect_pipe(fd, STDIN_FILENO);
		run_cmd(*cmd);
	}
}

int     	main(int argc, char **argv)
{
	pipex(argc - 4, *(argv + 1), *(argv + argc - 1), argv + argc - 2);
	return (0);
}