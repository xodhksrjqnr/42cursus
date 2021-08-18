#include "pipex_bonus.h"

void	exit_program(t_pipex_info *cmd_info, const char *message)
{
	size_t	messageLen;

	free_pipex(cmd_info);
	messageLen = ft_strlen(message);
	write(2, message, messageLen);
	write(2, "\n", 1);
	exit(1);
}