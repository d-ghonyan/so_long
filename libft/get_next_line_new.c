#include "libft.h"
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

static char	*ft_realloc(char *s, int size)
{
	int		i;
	char	*res;

	i = 0;
	if (!s)
	{
		res = (char *)malloc(sizeof (*res) + 1);
		if (!res)
			return (NULL);
		res[1] = '\0';
		return (res);
	}
	res = malloc((ft_strlen(s) + size + 1) * sizeof (*res));
	if (!res)
		return (NULL);
	while (s[i])
	{
		res[i] = s[i];
		i++;
	}
	free(s);
	res[i] = '\0';
	return (res);
}

char	*get_next_line_new(int fd)
{
	char	*s;
	int		a;
	int		i;

	a = 1;
	i = 0;
	s = NULL;
	while (a != 0)
	{
		s = ft_realloc(s, 1);
		if (!s)
			return (NULL);
		a = read(fd, &s[i], 1);
		printf("%s", s);
		if (a == -1)
		{
			free(s);
			return (NULL);
		}
		if (a == EOF || s[i] == '\n')
		{
			if (s[i] == '\n')
				i++;
			break ;
		}
		i++;
	}
	//printf("%s", s);
	//s[i] = '\0';
	return (s);
}
