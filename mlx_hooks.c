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

#include "so_long.h"

//w = 13, a = 0, s = 1, d = 2
//left = 123 up = 126 down = 125 right = 124

static void	call_move(int keycode, t_mlx *mlx)
{
	if ((keycode == 13 || keycode == 126)
		&& mlx->player->posy >= mlx->floor[0]->h
		&& (mlx->map)[mlx->player->i - 1][mlx->player->j] != '1'
		)
		move_up(mlx);
	else if ((keycode == 1 || keycode == 125)
		&& mlx->player->posy <= mlx->win_size_h - mlx->floor[0]->h
		&& (mlx->map)[mlx->player->i + 1][mlx->player->j] != '1'
		)
		move_down(mlx);
	else if ((keycode == 0 || keycode == 123)
		&& mlx->player->posx >= mlx->floor[0]->w
		&& (mlx->map)[mlx->player->i][mlx->player->j - 1] != '1'
		)
		move_left(mlx);
	else if ((keycode == 2 || keycode == 124)
		&& mlx->player->posx <= mlx->win_size_w - mlx->floor[0]->w
		&& (mlx->map)[mlx->player->i][mlx->player->j + 1] != '1'
		)
		move_right(mlx);
}

int	key_hook(int keycode, t_mlx *mlx)
{
	char		*s;
	static int	count = 1;

	if (keycode == 53)
		hook(mlx);
	s = ft_itoa(count);
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr,
		mlx->walls[0]->img, 0, 0);
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, 0, 0, 0xffffff, s);
	free(s);
	call_move(keycode, mlx);
	if ((keycode == 13 || keycode == 126)
		|| (keycode == 1 || keycode == 125)
		|| (keycode == 0 || keycode == 123)
		|| (keycode == 2 || keycode == 124))
	count++;
	return (0);
}

int	hook(t_mlx *mlx)
{
	destroy_and_leave(mlx);
	exit (EXIT_SUCCESS);
}
