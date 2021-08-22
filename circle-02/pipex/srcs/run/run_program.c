/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_program.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taewan <taewan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/19 04:29:58 by taewan            #+#    #+#             */
/*   Updated: 2021/08/22 20:37:25 by taewan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	cmd_process(t_pipex_info *cmd_info, int target_cmd, int *prev_fd)
{
	pid_t	pid;
	int		fd[2];
	int		status;

	if (!target_cmd)
	{
		connect_pipe(prev_fd, STDOUT_FILENO, cmd_info);
		run_cmd(cmd_info, target_cmd);
	}
	if (pipe(fd) == -1)
		exit_program(cmd_info, strerror(PIPE_ERROR));
	pid = fork();
	if (pid == -1)
		exit_program(cmd_info, "Fork is failed");
	else if (pid == CHILD)
		cmd_process(cmd_info, target_cmd - 1, fd);
	if (waitpid(pid, &status, WNOHANG) == -1)
		exit_program(cmd_info, strerror(PROCESS_ERROR));
	connect_pipe(prev_fd, STDOUT_FILENO, cmd_info);
	connect_pipe(fd, STDIN_FILENO, cmd_info);
	run_cmd(cmd_info, target_cmd);
}

void	run_program(t_pipex_info *cmd_info, int target_cmd)
{
	pid_t	pid;
	int		fd[2];
	int		status;

	redirection_in(cmd_info);
	if (pipe(fd) == -1)
		exit_program(cmd_info, strerror(PIPE_ERROR));
	pid = fork();
	if (pid == -1)
		exit_program(cmd_info, "Fork is failed");
	else if (pid == CHILD)
		cmd_process(cmd_info, target_cmd - 1, fd);
	if (waitpid(pid, &status, WNOHANG) == -1)
		exit_program(cmd_info, strerror(PROCESS_ERROR));
	redirection_out(cmd_info);
	connect_pipe(fd, STDIN_FILENO, cmd_info);
	run_cmd(cmd_info, target_cmd);
}
