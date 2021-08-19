/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_info_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taewan <taewan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/19 04:42:13 by taewan            #+#    #+#             */
/*   Updated: 2021/08/19 17:28:14 by taewan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	init_info(t_pipex_info *cmd_info, char **cmd_arr, int num)
{
	cmd_info->cmd_data = 0;
	cmd_info->cmd_path = 0;
	cmd_info->env = 0;
	cmd_info->infile = cmd_arr[1];
	cmd_info->outfile = cmd_arr[num + 2];
	cmd_info->envp = 0;
	cmd_info->limiter = 0;
	cmd_info->h_flag = 0;
}
