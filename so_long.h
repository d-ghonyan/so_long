#ifndef SO_LONG_H

# define SO_LONG_H

# include <mlx.h>
# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

# include "colors.h"
# include "libft/libft.h"
# include "ft_printf/ft_printf.h"

typedef struct s_chars {
	int	p;
	int	c;
	int	e;
}	t_chars;

typedef struct s_player {
	int		w;
	int		h;
	int		posx;
	int		posy;
	void	*img;
}	t_player;

typedef struct s_wall {
	int		w;
	int		h;
	void	*img;
}	t_wall;

typedef struct s_empty {
	int		w;
	int		h;
	void	*img;
}	t_empty;

typedef struct s_collect {
	int		w;
	int		h;
	void	*img;
}	t_collect;

typedef struct s_exit {
	int		w;
	int		h;
	void	*img;
}	t_exit;

typedef struct s_images {
	t_player	*player;
	t_wall		*wall;
	t_empty		*empty;
	t_collect	*collect;
	t_exit		*exit;
}	t_images;

typedef struct s_mlx {
	void		*mlx_ptr;
	void		*win_ptr;
	t_images	*img;
}	t_mlx;

void	mlx_init_stuff(char **map);

int		is_allowed(char **map, char *allowed);

int		at_least_one(char **s);

int		check_file_extension(char *s);

int		map_check(char **map);

char	**parse_map(char *filename);

void	perror_exit_cond(char *errmsg, int cond);

void	free_stuff_and_exit(char **arr, char *s, char *errmsg);

void	free_stuff_and_exit_cond(char **arr, char *s, char *errmsg, int cond);

void	free_ptr_arr(char **arr);

//HOOKS
int		key_hook(int keycode, t_mlx *mlx);
int		mouse_hook(int button, int x, int y, void *param);
int		hook(void *param);
//HOOKS

#endif
