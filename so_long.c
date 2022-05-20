#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include "so_long.h"

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
//	void	*black_hole;
//	char	**map;
//	int width = 50, height = 50;
//	t_mlx	mlx;

//	int i = 10;
//	int f1 = open("maps/map1.ber", O_RDONLY);
//	int f2 = open("maps/map1.ber", O_RDONLY);
//	int f3 = open("maps/map1.ber", O_RDONLY);
	char **map = parse_map("maps/map1.ber");

	free_stuff_and_exit_cond(map, NULL, NULL, !map_check(map));
//	while (*map)
//		ft_printf("%s ", *(map++));
	//get_next_line_new(f1);
//	i = 10;
//	while (i--)
//	{
//		ft_printf(CYAN "%s", get_next_line(f2));
//	}
//	check_args(argc, argv[1]);
//	line_count(argv[1]);
//	line_count(argv[1]);
//	line_count(argv[1]);
//	int fd = open("maps/map1.ber", O_RDONLY);
//	while (i--)
//		ft_printf("%s", get_next_line(fd));
	//map = parse_map(argv[1]);
//	while (*map)
//	{
//		ft_printf("%s", *map);
//		map++;
//	}
	//
}
