/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taewan <taewan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/19 04:42:17 by taewan            #+#    #+#             */
/*   Updated: 2021/08/22 18:31:41 by taewan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

static char	**div_awk(char *cmd)
{
	char	**result;
	int		i;
	int		flag[2];

	i = -1;
	flag[0] = -1;
	flag[1] = -1;
	while (*(cmd + ++i))
	{
		if (*(cmd + i) == '\'' || *(cmd + i) == '\"')
		{
			if ((flag[0] == -1 && flag[1] == -1)
				|| (flag[(*(cmd + i) - 34) / 5] == 1))
			{
				flag[(*(cmd + i) - 34) / 5] *= -1;
				*(cmd + i) = 127;
			}
			continue ;
		}
		if (flag[0] == -1 && flag[1] == -1 && *(cmd + i) == ' ')
			*(cmd + i) = 127;
	}
	result = ft_split(cmd, 127);
	free(cmd);
	return (result);
}

static char	**div_cmd(const char *cmd)
{
	char	*tmp;

	if (!*cmd)
		return (ft_split(cmd, ' '));
	if (ft_strlen(cmd) >= 3)
	{
		if (!ft_strncmp(cmd, "awk ", 4))
		{
			tmp = ft_strdup(cmd);
			if (!tmp)
				return (0);
			return (div_awk(tmp));
		}
	}
	return (ft_split(cmd, ' '));
}

static void	init_envp(char **envp, t_pipex_info *cmd_info)
{
	cmd_info->envp = envp;
	while (ft_strncmp(*envp, "PATH=", 5))
		envp++;
	cmd_info->env = ft_split(*envp + 5, ':');
	if (!cmd_info->env)
		exit_program(cmd_info, strerror(MALLOC_ERROR));
}

static void	invalid_cmd(t_pipex_info *cmd_info, int curIndex)
{
	char	*tmp_str;
	int		i;

	if (!access(cmd_info->cmd_data[curIndex][0], R_OK))
	{
		cmd_info->cmd_path[curIndex] = cmd_info->cmd_data[curIndex][0];
		return ;
	}
	i = -1;
	while (cmd_info->env[++i])
	{
		tmp_str = ft_strjoin("/", cmd_info->cmd_data[curIndex][0]);
		cmd_info->cmd_path[curIndex] = ft_strjoin(cmd_info->env[i], tmp_str);
		if (tmp_str)
			free(tmp_str);
		if (!cmd_info->cmd_path[curIndex])
			exit_program(cmd_info, strerror(MALLOC_ERROR));
		if (!access(cmd_info->cmd_path[curIndex], R_OK))
			return ;
		free(cmd_info->cmd_path[curIndex]);
	}
	write(2, "command not found\n", 18);
	cmd_info->cmd_path[curIndex] = ft_strdup("");
	if (!cmd_info->cmd_path[curIndex])
		exit_program(cmd_info, strerror(MALLOC_ERROR));
}

void	init(char **cmd_arr, t_pipex_info *cmd_info, int numOfCmd, char **envp)
{
	int	i;
	int	cmdIsZero;

	cmdIsZero = 0;
	init_info(cmd_info, cmd_arr, numOfCmd);
	check_heredoc(cmd_info, cmd_arr[2]);
	numOfCmd -= cmd_info->h_flag;
	init_envp(envp, cmd_info);
	if (!numOfCmd)
		cmdIsZero = 1;
	cmd_info->cmd_path = ft_calloc(numOfCmd + 1 + cmdIsZero, sizeof(char *));
	cmd_info->cmd_data = ft_calloc(numOfCmd + 1 + cmdIsZero, sizeof(char **));
	if (!cmd_info->cmd_data || !cmd_info->cmd_path)
		exit_program(cmd_info, strerror(MALLOC_ERROR));
	i = -1;
	while (++i < numOfCmd + cmdIsZero)
	{
		if (cmdIsZero)
			cmd_info->cmd_data[i] = div_cmd("cat");
		else
			cmd_info->cmd_data[i] = div_cmd(cmd_arr[i + 2 + cmd_info->h_flag]);
		if (!cmd_info->cmd_data[i])
			exit_program(cmd_info, strerror(MALLOC_ERROR));
		invalid_cmd(cmd_info, i);
	}
}
