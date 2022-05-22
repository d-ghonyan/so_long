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

void	move_up(t_mlx *mlx)
{
	if (mlx->map[mlx->player->i - 1][mlx->player->j] == 'C')
	{
		draw_single_floor(mlx);
		redraw_exit(mlx);
		mlx->player->posy -= mlx->floor->h;
		mlx->player->i -= 1;
		draw_single_floor(mlx);
		mlx->map[mlx->player->i][mlx->player->j] = '0';
		mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr,
			mlx->player->img, (mlx->player)->posx, (mlx->player)->posy);
			//return (1);
	}
	else
	{
		draw_single_floor(mlx);
		redraw_exit(mlx);
		mlx->player->posy -= mlx->floor->h;
		mlx->player->i -= 1;
		if (mlx->map[mlx->player->i][mlx->player->j] == 'E'
			&& !get_count(mlx->map, 'C'))
			hook(mlx);
		mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr,
			mlx->player->img, (mlx->player)->posx, (mlx->player)->posy);
	}
}

void	move_down(t_mlx *mlx)
{
	if (mlx->map[mlx->player->i + 1][mlx->player->j] == 'C')
	{
		draw_single_floor(mlx);
		redraw_exit(mlx);
		mlx->player->posy += mlx->floor->h;
		mlx->player->i += 1;
		draw_single_floor(mlx);
		mlx->map[mlx->player->i][mlx->player->j] = '0';
		mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr,
			mlx->player->img, (mlx->player)->posx, (mlx->player)->posy);
	}
	else
	{
		draw_single_floor(mlx);
		redraw_exit(mlx);
		mlx->player->posy += mlx->floor->h;
		mlx->player->i += 1;
		if (mlx->map[mlx->player->i][mlx->player->j] == 'E'
			&& !get_count(mlx->map, 'C'))
			hook(mlx);
		mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr,
			mlx->player->img, (mlx->player)->posx, (mlx->player)->posy);
	}
}

void	move_left(t_mlx *mlx)
{
	if (mlx->map[mlx->player->i][mlx->player->j - 1] == 'C')
	{
		draw_single_floor(mlx);
		redraw_exit(mlx);
		mlx->player->posx -= mlx->floor->w;
		mlx->player->j -= 1;
		draw_single_floor(mlx);
		mlx->map[mlx->player->i][mlx->player->j] = '0';
		mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr,
			mlx->player->img, (mlx->player)->posx, (mlx->player)->posy);
	}
	else
	{
		draw_single_floor(mlx);
		redraw_exit(mlx);
		mlx->player->posx -= mlx->floor->w;
		mlx->player->j -= 1;
		if (mlx->map[mlx->player->i][mlx->player->j] == 'E'
			&& !get_count(mlx->map, 'C'))
			hook(mlx);
		mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr,
			mlx->player->img, (mlx->player)->posx, (mlx->player)->posy);
	}
}

void	move_right(t_mlx *mlx)
{
	if (mlx->map[mlx->player->i][mlx->player->j + 1] == 'C')
	{
		draw_single_floor(mlx);
		redraw_exit(mlx);
		mlx->player->posx += mlx->floor->w;
		mlx->player->j += 1;
		draw_single_floor(mlx);
		mlx->map[mlx->player->i][mlx->player->j] = '0';
		mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr,
			mlx->player->img, (mlx->player)->posx, (mlx->player)->posy);
	}
	else
	{
		draw_single_floor(mlx);
		redraw_exit(mlx);
		mlx->player->posx += mlx->floor->w;
		mlx->player->j += 1;
		if (mlx->map[mlx->player->i][mlx->player->j] == 'E'
			&& !get_count(mlx->map, 'C'))
			hook(mlx);
		mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr,
			mlx->player->img, (mlx->player)->posx, (mlx->player)->posy);
	}
}
