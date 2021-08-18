#include "pipex_bonus.h"

static char	**setting_path(char **env)
{
	char	**path;
	char	*tmp;
	int		i;

	while (ft_strncmp(*env, "PATH=", 5))
		env++;
	path = ft_split(*env + 5, ':');
	if (!path)
		return (0);
	i = 0;
	while (*(path + i))
	{
		tmp = ft_strjoin(*(path + i), "/");
		if (!tmp)
		{
			free_split(path);
			return (0);
		}
		free(*(path + i));
		*(path + i++) = tmp;
	}
	return (path);
}

static char	child_pipe(int pipe_num, char **cmd, int *prev_fd, char **path)
{
	pid_t	pid;
	int		fd[2];
	int		status;

	if (!pipe_num)
	{
		if (!connect_pipe(prev_fd, STDOUT_FILENO))
			return (0);
		return (run_cmd(*cmd, path));
	}
	if (pipe(fd) == -1)
		return (0);
	pid = fork();
	if (pid == -1)
		return (0);
	else if (pid == CHILD)
		return (child_pipe(pipe_num - 1, cmd - 1, fd, path));
	if (waitpid(pid, &status, 0) == -1)
		return (0);
	if (!connect_pipe(prev_fd, STDOUT_FILENO) || !connect_pipe(fd, STDIN_FILENO))
		return (0);
	return (run_cmd(*cmd, path));
}

static char	pipex(int argc, char **argv, char **path, int flag)
{
	pid_t	pid;
	int		fd[2];
	int		status;

	if (flag == 2)
	{
		if (!heredoc_read_stdin(*argv, ft_strlen(*argv)) || pipe(fd) == -1)
			return (0);
	}
	else if (!redirection_in(argv[0]) || pipe(fd) == -1)
		return (0);
	pid = fork();
	if (pid == -1)
		return (0);
	else if (pid == CHILD)
		return (child_pipe(argc - 4, argv + argc - 3, fd, path));
	if (waitpid(pid, &status, 0) == -1)
		return (free_split(path));
	if (!redirection_out(argv[argc - 1], flag) || !connect_pipe(fd, STDIN_FILENO))
		return (0);
	return (run_cmd(*(argv + argc - 2), path));
}

int     	main(int argc, char **argv, char **env)
{
	char	**path;
	int		heredoc_flag;

	if (argc < 5)
		return (EXIT_FAILURE);
	path = setting_path(env);
	if (!path)
		return (EXIT_FAILURE);
	heredoc_flag = 1;
	if (!ft_strncmp(*(argv + 1), "here_doc", 9))
		heredoc_flag++;
	if (pipex(argc - heredoc_flag, argv + heredoc_flag, path, heredoc_flag))
		return (EXIT_SUCCESS);
	return (EXIT_FAILURE);
}
