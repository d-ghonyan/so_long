#include "so_long.h"

void	parse_map(char *filename)
{
	int	map;

	map = open(filename, O_RDONLY);
	if (map < 0)
	{
		perror("failed to open map");
		exit(EXIT_FAILURE);
	}
}