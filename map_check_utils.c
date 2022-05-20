int	is_allowed(char *s, char c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int	at_least_one(char **s)
{
	int	p;
	int	e;
	int	c;
	int	i;
	int	j;

	i = 0;
	p = 0;
	e = 0;
	c = 0;
	while (s[i])
	{
		j = 0;
		while (s[i][j])
		{
			
			if (s[i][j] == 'P')
				p++;
			else if (s[i][j] == 'E')
				e++;
			else if (s[i][j] == 'C')
				c++;
			j++;
		}
		i++;
	}
	yay(p, e, c);
	return (e != 0 && p != 0 && c != 0);
}

static void	yay(int p, int c, int e)
{
	if (p == 0)
		ft_printf(BLUE "you forgot the player\n" COLOR_RESET);
	else if (c == 0)
		ft_printf(YELLOW "you forgot the collectables\n" COLOR_RESET);
	else if (e == 0)
		ft_printf(CYAN "you forgot the exit\n" COLOR_RESET);
}
