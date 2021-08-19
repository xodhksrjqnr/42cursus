/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taewan <taewan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/19 04:41:45 by taewan            #+#    #+#             */
/*   Updated: 2021/08/19 15:39:04 by taewan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

int	main(int argc, char **argv, char **envp)
{
	t_pipex_info	cmd_info;

	invalid(&argc, argv + 1);
	init(argv, &cmd_info, argc, envp);
	run_program(&cmd_info, argc - 1 - cmd_info.h_flag);
	return (0);
}
