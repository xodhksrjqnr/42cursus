#include "pipex_bonus.h"

char    free_split(char **target)
{
    while (*target)
        free(*target++);
    free(target);
    return (0);
}

char    redirection_out(char *file, int flag)
{
    int fd;

    if (flag == 1)
        fd = open(file, O_RDWR | O_CREAT, 0644);
    else
        fd = open(file, O_RDWR | O_CREAT | O_APPEND, 0644);
    if (fd < 0)
        return (0);
    if (dup2(fd, STDOUT_FILENO) == -1)
        return (0);
    close(fd);
    return (1);
}

char    redirection_in(char *file)
{
    int fd;

    fd = open(file, O_RDONLY);
    if (fd < 0)
        return (0);
    if (dup2(fd, STDIN_FILENO) == -1)
        return (0);
    close(fd);
    return (1);
}

char	connect_pipe(int *fd, int io)
{
	if (dup2(fd[io], io) == -1)
        return (0);
	close(fd[0]);
	close(fd[1]);
    return (1);
}

char	run_cmd(char *cmd, char **env_path)
{
	char	**cmd_data;
	char	*path;

	cmd_data = ft_split(cmd, ' ');
	if (!cmd_data)
		return (0);
	path = 0;
	while (*env_path)
	{
		if (path)
			free(path);
		path = ft_strjoin(*env_path++, cmd_data[0]);
		if (!path)
			return (free_split(cmd_data));
		if (!access(path, F_OK))
            break ;
	}
	if (!*env_path)
		return (free_split(cmd_data));
	if (execve((const char *)path, (char *const *)cmd_data, 0) == -1)
    {
        free(path);
		return (free_split(cmd_data));
    }
    return (1);
}
