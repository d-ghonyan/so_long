#include "so_long.h"

void	parse_map(char *filename)
{
	int		i;
	int		map;
	int		map_other;
	int		line_len;
	int		line_count;
	char	*line;

	i = 0;
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
	printf("%d")
}