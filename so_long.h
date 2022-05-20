#ifndef SO_LONG_H

# define SO_LONG_H

//# include <mlx.h>
# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

# include "colors.h"
# include "libft/libft.h"
# include "ft_printf/ft_printf.h"

int		check_file_extension(char *s);

int		map_check(char **map);

char	**parse_map(char *filename);

void	perror_exit_cond(char *errmsg, int cond);

void	free_stuff_and_exit(char **arr, char *s, char *errmsg);

void	free_stuff_and_exit_cond(char **arr, char *s, char *errmsg, int cond);

void	free_ptr_arr(char **arr);

#endif
