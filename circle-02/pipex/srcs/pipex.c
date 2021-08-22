/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taewan <taewan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/19 04:29:52 by taewan            #+#    #+#             */
/*   Updated: 2021/08/22 17:43:40 by taewan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **envp)
{
	t_pipex_info	cmd_info;

	invalid(argc, argv + 1);
	init(argv, &cmd_info, argc - 3, envp);
	run_program(&cmd_info, argc - 4);
	return (0);
}
