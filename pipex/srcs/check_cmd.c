#include "pipex.h"

static void	free_path_array(char **path)
{
	int	i;

	i = 0;
	while (i < 5)
	{
		if (path[i])
			free(path[i]);
		i++;
	}
}

static char	invalid_cmd(char **path, char *cmd)
{
	int		i;

	path[0] = ft_strjoin("/bin/", cmd);
	path[1] = ft_strjoin("/usr/bin/", cmd);
	path[2] = ft_strjoin("/usr/local/bin/", cmd);
	path[3] = ft_strjoin("/usr/sbin/", cmd);
	path[4] = ft_strjoin("/sbin/", cmd);
	i = 0;
	while (i < 5)
		if (!path[i++])
			return (0);
	return (1);
}

void	run_cmd(char *cmd)
{
	char	**chunk;
	char	*path[5];
	int		i;

	chunk = ft_split(cmd, ' ');
	if (!invalid_cmd(path, *chunk))
	{
		free_path_array(path);
		exit(1);
	}
	i = 0;
	while (i < 5)
		execve((const char *)path[i++], (char *const *)chunk, 0);
}