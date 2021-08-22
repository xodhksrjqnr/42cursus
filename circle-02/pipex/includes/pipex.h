/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taewan <taewan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/19 04:43:46 by taewan            #+#    #+#             */
/*   Updated: 2021/08/22 16:59:41 by taewan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# define PIPE_ERROR 32
# define FILE_OPEN_ERROR 23
# define ARGUMENT_ERROR 22
# define MALLOC_ERROR 12
# define PROCESS_ERROR 10
# define FILE_ERROR 2

# define CHILD 0

# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include "../libft/libft.h"

typedef struct s_pipex_info
{
	char	***cmd_data;
	char	**cmd_path;
	char	**env;
	char	*infile;
	char	*outfile;
	char	**envp;
}	t_pipex_info;

void	init(char **cmd_arr, t_pipex_info *cmd_info, int numOfCmd, char **envp);
void	init_info(t_pipex_info *cmd_info, char **cmd_arr, int num);
void	run_program(t_pipex_info *cmd_info, int numOfPipe);
void	invalid(int argc, char **infile);
void	exit_program(t_pipex_info *cmd_info, const char *message);
void	free_pipex(t_pipex_info *target);

void	redirection_in(t_pipex_info *cmd_info);
void	redirection_out(t_pipex_info *cmd_info);
void	connect_pipe(int *fd, int io, t_pipex_info *cmd_info);
void	run_cmd(t_pipex_info *cmd_info, int target_cmd);

#endif