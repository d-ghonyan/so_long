#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include "so_long.h"

typedef struct s_mlx {
	void	*mlx_ptr;
	void	*win_ptr;
}	t_mlx;

int	key_hook(int keycode, t_mlx mlx)
{
	(void)mlx;
	if (keycode == 53)
	{
		exit(EXIT_SUCCESS);
	}
	ft_printf("%d\n", keycode);
	return (0);
}

int	destroy_hook(t_mlx mlx)
{
	(void)mlx;
	exit(EXIT_SUCCESS);
	/// TODO free things maybe
	return (0);
}

void	check_args(int argc, char *filename)
{
	char	*dot;

	if (argc < 2)
	{
		ft_printf(RED "Not enough arguments" COLOR_RESET);
		exit (EXIT_FAILURE);
	}
	if (argc > 2)
	{
		ft_printf(RED "Too many arguments" COLOR_RESET);
		exit (EXIT_FAILURE);
	}
	if (check_file_extension(filename))
	{
		ft_printf(RED "Wrong file extension, must be .ber\n" COLOR_RESET);
		exit (EXIT_FAILURE);
	}
}

int	main(int argc, char **argv)
{
	void	*black_hole;
	int width = 50, height = 50;
	t_mlx	mlx;

	
	//ft_printf(CYAN "%d\n", check_file_extension(argv[1]));
	check_args(argc, argv[1]);
	// parse_map(argv[1]);
	// mlx.mlx_ptr = mlx_init();
	// mlx.win_ptr = mlx_new_window(mlx.mlx_ptr, 400, 400, "Hello");
	// mlx_key_hook(mlx.win_ptr, &key_hook, &mlx);
	// mlx_hook(mlx.win_ptr, 17, 0, &destroy_hook, &mlx);
	// // png = mlx_xpm_file_to_image(mlx.mlx_ptr, "skybox.xpm", &width, &height);
	// // wooden = mlx_xpm_file_to_image(mlx.mlx_ptr, "wooden.xpm", &width, &height);
	// black_hole = mlx_xpm_file_to_image(mlx.mlx_ptr, "blackHole.xpm", &width, &height);

	// for (int i = 0; i < 400; i += width)
	// 	for (int j = 0; j < 400; j += height)
	// 		mlx_put_image_to_window(mlx.mlx_ptr, mlx.win_ptr, black_hole, i, j);

	// //ft_printf("%d %d\n", width, height);
	// //mlx_put_image_to_window(mlx.mlx_ptr, mlx.win_ptr, wooden, 0, 0);
	// // image = mlx_new_image(mlx.mlx_ptr, 50, 50);
	// mlx_loop(mlx.mlx_ptr);
}
