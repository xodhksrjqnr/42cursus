#include "pipex_bonus.h"

int	main(int argc, char **argv, char **envp)
{
	t_pipex_info	cmd_info;

	//if (argc != 5)
	//	exit_program(NULL, strerror(ARGUMENT_ERROR));
	if (access(*(argv + 1), R_OK) && ft_strncmp(*(argv + 1), "here_doc", 9))
	{
		*(argv + 1) = ft_strdup("/dev/null");
		if (!*(argv + 1))
			exit_program(NULL, strerror(MALLOC_ERROR));
	}
	init(argv, &cmd_info, argc - 3, envp);
	run_program(&cmd_info, argc - 4 - cmd_info.h_flag);
	return (0);
}