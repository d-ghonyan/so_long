#include "so_long.h"

static void	yay(int p, int c, int e)
{
	if (p == 0)
		ft_printf(BLUE "you forgot the player\n" COLOR_RESET);
	else if (c == 0)
		ft_printf(YELLOW "you forgot the collectables\n" COLOR_RESET);
	else if (e == 0)
		ft_printf(CYAN "you forgot the exit\n" COLOR_RESET);
}

static int	is_in_set(char *set, char c)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int	is_allowed(char **map, char *allowed)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (!is_in_set(allowed, map[i][j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	at_least_one(char **s)
{
	int		i;
	int		j;
	t_chars	chars;

	i = 0;
	chars.p = 0;
	chars.e = 0;
	chars.c = 0;
	while (s[i])
	{
		j = 0;
		while (s[i][j])
		{
			if (s[i][j] == 'P')
				chars.p += 1;
			else if (s[i][j] == 'E')
				chars.e += 1;
			else if (s[i][j] == 'C')
				chars.c += 1;
			j++;
		}
		i++;
	}
	yay(chars.p, chars.e, chars.c);
	return (chars.e != 0 && chars.p != 0 && chars.c != 0);
}
