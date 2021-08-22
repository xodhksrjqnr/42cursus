/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   invalid.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taewan <taewan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/22 17:10:33 by taewan            #+#    #+#             */
/*   Updated: 2021/08/22 17:10:34 by taewan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	invalid(int argc, char **infile)
{
	if (argc != 5)
		exit_program(NULL, strerror(ARGUMENT_ERROR));
	if (access(*infile, R_OK))
	{
		*infile = ft_strdup("/dev/null");
		if (!*infile)
			exit_program(NULL, strerror(MALLOC_ERROR));
	}
}
