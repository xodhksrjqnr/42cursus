/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_utils_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taewan <taewan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/19 04:42:04 by taewan            #+#    #+#             */
/*   Updated: 2021/08/19 17:43:14 by taewan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	redirection_in(t_pipex_info *cmd_info)
{
	int	fd;

	fd = open(cmd_info->infile, O_RDONLY);
	if (fd < 0)
		exit_program(cmd_info, strerror(FILE_OPEN_ERROR));
	if (dup2(fd, STDIN_FILENO) == -1)
	{
		close(fd);
		exit_program(cmd_info, "dup is failed");
	}
	close(fd);
}

void	redirection_out(t_pipex_info *cmd_info)
{
	int	fd;

	if (!cmd_info->h_flag)
		fd = open(cmd_info->outfile, O_RDWR | O_CREAT | O_TRUNC, 0644);
	else
		fd = open(cmd_info->outfile, O_RDWR | O_CREAT | O_APPEND, 0644);
	if (fd < 0)
		exit_program(cmd_info, strerror(FILE_OPEN_ERROR));
	if (dup2(fd, STDOUT_FILENO) == -1)
	{
		close(fd);
		exit_program(cmd_info, "dup is failed");
	}
	close(fd);
}

void	connect_pipe(int *fd, int io, t_pipex_info *cmd_info)
{
	if (dup2(fd[io], io) == -1)
	{
		close(fd[0]);
		close(fd[1]);
		exit_program(cmd_info, "dup is failed");
	}
	close(fd[0]);
	close(fd[1]);
}

void	run_cmd(t_pipex_info *cmd_info, int target_cmd)
{
	const char	*cur_cmd_path;
	char *const	*cur_cmd_data;

	if (target_cmd < 0)
		target_cmd = 0;
	cur_cmd_path = cmd_info->cmd_path[target_cmd];
	cur_cmd_data = cmd_info->cmd_data[target_cmd];
	if (execve(cur_cmd_path, cur_cmd_data, cmd_info->envp) == -1)
		exit_program(cmd_info, "execve is failed");
}
