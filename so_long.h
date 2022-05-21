/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dghonyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 19:47:41 by dghonyan          #+#    #+#             */
/*   Updated: 2022/05/21 19:47:46 by dghonyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H

# define SO_LONG_H

# include "mlx/mlx.h"
# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

# include "colors.h"
# include "libft/libft.h"
# include "ft_printf/ft_printf.h"

typedef struct s_pos {
	int	x;
	int	y;
}	t_pos;

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
	t_img		**floor;
	t_img		**collects;	
	t_img		*exit;
	t_img		*walls;
	t_player	*player;
	//char		**map;
	void		*mlx_ptr;
	void		*win_ptr;
	int			win_size_w;
	int			win_size_h;
}	t_mlx;

void		mlx_init_stuff(char **map);

int			is_allowed(char **map, char *allowed);

int			at_least_one(char **s);

int			check_file_extension(char *s);

int			map_check(char **map);

char		**parse_map(char *filename);

void		perror_exit_cond(char *errmsg, int cond);

void		free_stuff_and_exit(char **arr, char *s, char *errmsg);

void		free_stuff_and_exit_cond(char **arr, char *s, char *errmsg, int cond);

void		free_ptr_arr(char **arr);

void		draw_floor(t_mlx *mlx, char **map);

void		draw_walls(t_mlx *mlx, char **map);

t_img		**allocate_floor(void *mlx_ptr, char **map);

t_pos		get_player_position(char **map);

t_player	*allocate_player(void *mlx_ptr);

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
