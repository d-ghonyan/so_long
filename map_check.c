#include "so_long.h"

int	map_check(char **map)
{
	int	i;
	
	i = 0;
	while (map[0][i])
	{
			perror_exit_cond("map isn't surrounded by walls",
				map[0][i] != 1 && map[]);
			i++;
	}
}

static int	ptr_arr_len(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
		i++;
	return (i);
}