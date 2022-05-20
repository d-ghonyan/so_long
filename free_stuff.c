#include "so_long.h"

void	perror_exit_cond(char *errmsg, int cond)
{
	if (cond)
	{
		perror(errmsg);
		exit (EXIT_FAILURE);
	}
}

void	free_stuff_and_exit(char **arr, char *s, char *errmsg)
{
	if (errmsg)
		perror (errmsg);
	if (arr)
		free_ptr_arr(arr);
	free(s);
	exit (EXIT_FAILURE);
}

void	free_stuff_and_exit_cond(char **arr, char *s, char *errmsg, int cond)
{
	if (cond)
	{
		if (errmsg)
			perror (errmsg);
		if (arr)
			free_ptr_arr(arr);
		if (s)
			free(s);
		exit (EXIT_FAILURE);
	}
}

void	free_ptr_arr(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}
