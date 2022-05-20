#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include "so_long.h"

void	check_args(int argc, char *filename)
{
	char	*dot;

	if (argc < 2)
	{
		ft_printf(RED "Not enough arguments\n" COLOR_RESET);
		exit (EXIT_FAILURE);
	}
	if (argc > 2)
	{
		ft_printf(RED "Too many arguments\n" COLOR_RESET);
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
//	void	*black_hole;
//	char	**map;
//	int width = 50, height = 50;
//	t_mlx	mlx;

	char **map = parse_map("maps/map1.ber");

	check_args(argc, argv[1]);
	free_stuff_and_exit_cond(map, NULL, NULL, !map_check(map));
	mlx_init_stuff(map);
}
