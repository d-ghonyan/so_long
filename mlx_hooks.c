#include "so_long.h"

//w = 13, a = 0, s = 1, d = 2

void	move_up(t_mlx *mlx)
{
	
}

int	key_hook(int keycode, t_mlx *mlx)
{
	ft_printf(YELLOW "%d" COLOR_RESET, keycode);
	if (keycode == 53)
	{
		exit(EXIT_SUCCESS);
	}
	if (keycode == 13)
	{
		int	posx;
		int	posy;

		// if (mlx->img->player->img)
		// {
		// 	posx = mlx->img->player->posx;
		// 	posy = mlx->img->player->posy;
		// 	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->img->exit->img, posx, posy);
		// }
		// else
		// 	posx = posy = 0;

		mlx_destroy_image(mlx->mlx_ptr, mlx->img->player->img);
		mlx->img->player->img = NULL;
	}
}

int	mouse_hook(int button, int x, int y, void *param)
{

}

int	hook(void *param)
{
	exit (EXIT_SUCCESS);
}
