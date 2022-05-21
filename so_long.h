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

typedef struct s_img {
	void	*img;
	int		w;
	int		h;
}	t_img;

typedef struct s_player {
	void	*img;
	int		w;
	int		h;
	int		posx;
	int		posy;
}	t_player;

typedef struct s_mlx {
	t_img		**imgs;
	t_img		**walls;
	t_img		**collects;	
	t_img		*exit;
	t_player	*player;
	void		*mlx_ptr;
	void		*win_ptr;
	int			win_size_w;
	int			win_size_h;
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

//MOVE PLAYER
void	move_up(t_mlx *mlx);
void	move_down(t_mlx *mlx);
void	move_left(t_mlx *mlx);
void	move_right(t_mlx *mlx);
//MOVE PLAYER

#endif
