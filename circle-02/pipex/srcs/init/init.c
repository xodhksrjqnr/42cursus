/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taewan <taewan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/19 04:30:09 by taewan            #+#    #+#             */
/*   Updated: 2021/08/19 17:29:59 by taewan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

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
	i = 0;
	while (cmd_info->env[i])
	{
		tmp_str = ft_strjoin("/", cmd_info->cmd_data[curIndex][0]);
		if (!tmp_str)
			exit_program(cmd_info, strerror(MALLOC_ERROR));
		cmd_info->cmd_path[curIndex] = ft_strjoin(cmd_info->env[i], tmp_str);
		free(tmp_str);
		if (!cmd_info->cmd_path[curIndex])
			exit_program(cmd_info, strerror(MALLOC_ERROR));
		if (!access(cmd_info->cmd_path[curIndex], R_OK))
			return ;
		i++;
	}
	write(2, "command not found\n", 18);
}

void	init(char **cmd_arr, t_pipex_info *cmd_info, int numOfCmd, char **envp)
{
	int		i;

	init_info(cmd_info, cmd_arr, numOfCmd);
	init_envp(envp, cmd_info);
	cmd_info->cmd_path = ft_calloc(numOfCmd + 1, sizeof(char *));
	cmd_info->cmd_data = ft_calloc(numOfCmd + 1, sizeof(char **));
	if (!cmd_info->cmd_data || !cmd_info->cmd_path)
		exit_program(cmd_info, strerror(MALLOC_ERROR));
	i = 0;
	while (i < numOfCmd)
	{
		cmd_info->cmd_data[i] = div_cmd(cmd_arr[i + 2]);
		if (!cmd_info->cmd_data[i])
			exit_program(cmd_info, strerror(MALLOC_ERROR));
		invalid_cmd(cmd_info, i);
		i++;
	}
}
