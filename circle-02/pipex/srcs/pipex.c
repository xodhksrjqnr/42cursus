/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taewan <taewan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/19 04:29:52 by taewan            #+#    #+#             */
/*   Updated: 2021/08/19 18:48:37 by taewan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **envp)
{
	t_pipex_info	cmd_info;

	if (argc != 5)
		exit_program(NULL, strerror(ARGUMENT_ERROR));
	if (access(*(argv + 1), R_OK))
	{
		*(argv + 1) = ft_strdup("/dev/null");
		if (!*(argv + 1))
			exit_program(NULL, strerror(MALLOC_ERROR));
	}
	init(argv, &cmd_info, argc - 3, envp);
	run_program(&cmd_info, argc - 4);
	return (0);
}
