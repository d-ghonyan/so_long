#include "libft.h"
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

static void	perror_exit_cond(char *errmsg, int cond)
{
	if (cond)
	{
		perror(errmsg);
		exit (EXIT_FAILURE);
	}
}

static char	*ft_strjoin_for_read(char *s, char c)
{
	size_t	i;
	char	*res;

	i = 0;
	res = (char *)malloc(sizeof (*res) * (ft_strlen(s) + 2));
	if (!res)
		return (NULL);
	while (i < ft_strlen(s))
	{
		res[i] = s[i];
		i++;
	}
	free(s);
	res[i] = c;
	res[i + 1] = '\0';
	return (res);
}

static void	free_ptr_arr(char **arr)
{
	while (*arr)
	{
		free(*arr);
		arr++;
	}
	free(arr);
}

static void	free_stuff_and_exit(char **arr, char *s, char *errmsg)
{
	if (errmsg)
		perror (errmsg);
	if (arr)
		free_ptr_arr(arr);
	free(s);
	exit (EXIT_FAILURE);
}


char	*get_next_line_new(int fd)
{
	char	*s;
	char	c;
	int		a;

	s = NULL;
	while (1)
	{
		a = read(fd, &c, 1);
		if (a == -1)
			free_stuff_and_exit(NULL, s, "read() failed at gnl_new()");
		if (a == 0)
			return (s);
		if (c == '\n')
			return (s);
		s = ft_strjoin_for_read(s, c);
		perror_exit_cond("strjoin() failed at gnl_new()", !s);
	}
	return (NULL);
}
