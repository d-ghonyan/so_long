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

void	draw_single_floor(t_mlx *mlx)
{
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->floor[0]->img,
		mlx->floor[first_where(mlx->floor, mlx->player->i,
			mlx->player->j)]->posx,
		mlx->floor[first_where(mlx->floor, mlx->player->i,
			mlx->player->j)]->posy);
}

void	redraw_exit(t_mlx *mlx)
{
	if (mlx->map[mlx->player->i][mlx->player->j] == 'E')
		mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr,
			mlx->exit->img, mlx->exit->posx, mlx->exit->posy);
}
