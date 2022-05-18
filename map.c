#include "so_long.h"

int	line_count(char *s)
{
	int		line_count;
	int		fd;
	char	*line;

	line_count = 0;
	fd = open(s, O_RDONLY);
	if (fd < 0)
	{
		perror("Can't open the map");
		exit (EXIT_FAILURE);
	}
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		ft_printf("%s\n", line);
		line_count++;
		free(line);
	}
	ft_printf("%d\n", line_count);
	close(fd);
	return (line_count);
}

char	**parse_map(char *filename)
{
	int		i;
	int		count;
	int		map;
	char	**line_arr;

	count = line_count(filename);
	line_arr = (char **)malloc(sizeof (*line_arr) * (count + 1));
	perror_exit_cond("Can't allocate memory at parse_map", !line_arr);
	map = open(filename, O_RDONLY);
	if (map < 0)
		free_stuff_and_exit(line_arr, NULL, "Can't open the map");
	i = 0;
	while (1)
	{
		line_arr[i] = get_next_line(map);
		ft_printf("%s", line_arr[i]);
		if (!line_arr[i])
			break ;
		i++;
	}
	close(map);
	//ft_printf("%d %d\n", i, count);
	if (i == 0 || i < count)
		free_stuff_and_exit(line_arr, NULL, "get_next_line failed");
	line_arr[i] = NULL;
	return (line_arr);
}

int	check_file_extension(char *s)
{
	int	i;

	if (ft_strlen(s) < 4)
		return (0);
	i = ft_strlen(s) - 4;
	return (ft_strncmp(&s[i], ".ber", 4));
}
