#include "so_long.h"

//w = 13, a = 0, s = 1, d = 2
//left = 123 up = 126 down = 125 right = 124

static void	call_move(int keycode, t_mlx *mlx)
{
	if ((keycode == 13 || keycode == 126)
		&& mlx->player->posy >= mlx->player->h)
	{
		move_up(mlx);
	}
	else if ((keycode == 1 || keycode == 125)
		&& mlx->player->posy <= mlx->win_size_h - mlx->player->h)
	{
		move_down(mlx);
	}
	else if ((keycode == 0 || keycode == 123)
		&& mlx->player->posx >= mlx->player->w)
	{
		move_left(mlx);
	}
	else if ((keycode == 2 || keycode == 124)
		&& mlx->player->posx <= mlx->win_size_w - mlx->player->w)
	{
		move_right(mlx);
	}
}

int	key_hook(int keycode, t_mlx *mlx)
{
	char		*s;
	char		*_s;
	static int	count = 0;

	s = ft_itoa(count);
	_s = ft_strjoin("Moves: ", s);
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr,
		mlx->imgs[0]->img, 0, 0);
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, 0, 0, 0x3264a8, _s);
	free(s);
	free(_s);
	if (keycode == 53)
	{
		exit(EXIT_SUCCESS);
	}
	call_move(keycode, mlx);
	count++;
}

int	hook(void *param)
{
	exit (EXIT_SUCCESS);
}
