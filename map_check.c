#include "so_long.h"

static int	map_len_check(char **map)
{
	int		i;
	size_t	len;

	i = 0;
	while (map[i])
	{
		if (i == 0)
			len = ft_strlen(map[i]);
		if (len != ft_strlen(map[i]))
		{
			ft_printf(RED "map must be a rectangle\n" COLOR_RESET);
			return (0);
		}
		i++;
	}
	return (1);
}

static int	first_last(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] != '1')
			return (0);
		i++;
	}
	return (1);
}

static int	middle(char *s)
{
	return (s[0] == '1' && s[ft_strlen(s) - 1] == '1');
}

static int	map_chars_heck(char *s)
{
	int		i;
	int		j;
	char	*allowed;

	i = 0;
	j = 0;
	allowed = "01PEC";
	while (allowed[i])
	{
		while (s[j])
		{
			if (!is_allowed(s, allowed[i]))
			{
				ft_printf(RED "invalid characters in the map\n" COLOR_RESET);
				return (0);
			}
		}
	}
	return (at_least_one(s));
}

int	map_check(char **map)
{
	int	i;
	int	len;
 
	i = 0;
	if (!map_len_check(map))
		return (0);
	len = ptr_arr_len(map);
	while (map[i])
	{
		if ((i == 0 || i == len - 1) && !first_last(map[i]))
		{
			ft_printf(RED "map isn't surrounded by walls\n" COLOR_RESET);
			return (0);
		}
		else if ((i > 0 && i < len - 1) && !middle(map[i]))
		{
			ft_printf(MAGENTA "map isn't surrounded by walls\n" COLOR_RESET);
			return (0);
		}
		i++;
	}
	return (1);
}
