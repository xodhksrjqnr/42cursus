#include "miniRT.h"

static int	set_object_data(t_list *list)
{
	int	fd;
	char	*line;
	int	result;

	if (!list)
		return (0);
	fd = open("../scenes/test.rt", O_RDONLY);
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
	if (fd != -1)
		close(fd);
	if (result == -1)
		return (0);
	return (1);
}

//static void	make_image();

//static void	start_program();

int	main(void)
{
	void	*mlx;
	void	*image;
	t_list	*list;

	mlx = mlx_init();
	list = init_list();
	set_object_data(list);
	//make_image();
	//start_program();
	return (0);
}
