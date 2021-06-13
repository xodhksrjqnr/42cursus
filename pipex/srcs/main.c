#include "pipex.h"
#include <stdio.h>

static char	pipex(int argc, char **argv)
{
	// pid_t	pid;

	argc = 0;
	redirection_in(*argv);
	
	// redirection_out(*(++argv));
	return (0);
}

int     main(int argc, char **argv)
{
	if (!pipex(argc, ++argv))
		return (0);
	return (0);
}