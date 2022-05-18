#include "so_long.h"

void	parse_map(char *filename)
{
	int		i;
	int		map;
	int		map_other;
	//int		line_len;
	int		line_count;
	char	*line;

	i = 0;
	line_count = 0;
	map = open(filename, O_RDONLY);
	map_other = open(filename, O_RDONLY);
	if (map < 0 || map_other < 0)
	{
		perror("failed to open the map");
		exit(EXIT_FAILURE);
	}
	while (1)
	{
		line = get_next_line(map_other);
		if (!line)
			break ;
		line_count++;
		free(line);
	}
	ft_printf("%d", line_count);
}

int	check_file_extension(char *s)
{
	int	i;

	if (ft_strlen(s) < 4)
		return (0);
	i = ft_strlen(s) - 4;
	return (ft_strncmp(&s[i], ".ber", 4));
}
