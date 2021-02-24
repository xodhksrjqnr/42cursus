#include "mlx.h"

int	main()
{
	void	*mlx_ptr;
	void	*win_ptr;
	int		x;
	int		y;

	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, 500, 500, "띄울_창_타이틀");
	x = 0;
	y = 0;
	while (y++ < 100)
	{
		while (x++ < 100)
			mlx_pixel_put(mlx_ptr, win_ptr, x, y, 0x0000FF00);
		x = 0;
	}
	mlx_loop(mlx_ptr);
}
