/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taewan <taewan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/19 04:42:23 by taewan            #+#    #+#             */
/*   Updated: 2021/08/19 04:42:23 by taewan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

static void	free_target(char ***target)
{
	int	i;

	i = 0;
	while (target[i])
		free_split(target[i++]);
	free(target);
}

void	free_pipex(t_pipex_info *target)
{
	if (!target)
		return ;
	if (target->cmd_data)
		free_target(target->cmd_data);
	if (target->cmd_path)
		free_split(target->cmd_path);
	if (target->env)
		free_split(target->env);
}
