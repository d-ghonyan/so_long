#include "so_long.h"

t_mlx	*mlx_init_stuff(void)
{
	t_mlx	*mlx;

	mlx.mlx_ptr = mlx_init();
	mlx.win_ptr = mlx_new_window(mlx.mlx_ptr, 400, 400, "Hello");
	mlx_key_hook(mlx.win_ptr, &key_hook, &mlx);
	mlx_hook(mlx.win_ptr, 17, 0, &destroy_hook, &mlx);
	// png = mlx_xpm_file_to_image(mlx.mlx_ptr, "skybox.xpm", &width, &height);
	// wooden = mlx_xpm_file_to_image(mlx.mlx_ptr, "wooden.xpm", &width, &height);
	black_hole = mlx_xpm_file_to_image(mlx.mlx_ptr, "blackHole.xpm", &width, &height);

	for (int i = 0; i < 400; i += width)
		for (int j = 0; j < 400; j += height)
			mlx_put_image_to_window(mlx.mlx_ptr, mlx.win_ptr, black_hole, i, j);

	//ft_printf("%d %d\n", width, height);
	//mlx_put_image_to_window(mlx.mlx_ptr, mlx.win_ptr, wooden, 0, 0);
	// image = mlx_new_image(mlx.mlx_ptr, 50, 50);
	mlx_loop(mlx.mlx_ptr);
}

int	calculate_stuff()
