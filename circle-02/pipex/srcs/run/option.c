#include "pipex.h"

int	option(int num, char *infile)
{
	if (num == 1 && !ft_strncmp(infile, "/dev/urandom", 13))
		return (WNOWAIT);
	return (0);
}
