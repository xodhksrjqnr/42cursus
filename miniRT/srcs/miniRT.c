#include "miniRT.h"

static int	set_object_data(t_list *list, char *filename)
{
	int	fd;
	char	*line;
	int	result;

	if (!list)
		return (0);
	fd = open(filename, O_RDONLY);
	result = get_next_line(fd, &line);
	if (!result)
		result = -1;
	while (result > 0)
	{
		if (!check_object(line, list))
		{
			result = -1;
			break ;
		}
		result = get_next_line(fd, &line);
	}
	free(line);
	if (fd != -1)
		close(fd);
	if (result == -1)
		return (0);
	return (1);
}

static void	make_image(t_RT *RT)
{
	RT->window = mlx_new_window(RT->mlx, 1000, 600, "test");
}

int	main(void)
{
	t_list	*list;
	t_RT	RT;

	RT.mlx = mlx_init();
	list = init_list();
	set_object_data(list, "scenes/test.rt");
	make_image(&RT);
	mlx_loop(RT.mlx);
	return (0);
}
