/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   invalid.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taewan <taewan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/19 17:37:55 by taewan            #+#    #+#             */
/*   Updated: 2021/08/19 17:37:56 by taewan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	invalid(int *argc, char **infile)
{
	int	h_flag;

	if (*argc < 3)
		exit_program(NULL, strerror(ARGUMENT_ERROR));
	h_flag = ft_strncmp(*infile, "here_doc", 9);
	if (*argc < 4 && !h_flag)
		exit_program(NULL, strerror(ARGUMENT_ERROR));
	if (access(*infile, R_OK) && h_flag)
	{
		*infile = ft_strdup("/dev/null");
		if (!*infile)
			exit_program(NULL, strerror(MALLOC_ERROR));
	}
	*argc -= 3;
}
