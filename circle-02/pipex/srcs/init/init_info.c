#include "pipex_bonus.h"

void	init_info(t_pipex_info *cmd_info)
{
	cmd_info->cmd_data = 0;
	cmd_info->cmd_path = 0;
	cmd_info->env = 0;
	cmd_info->infile = 0;
	cmd_info->outfile = 0;
	cmd_info->envp = 0;
}