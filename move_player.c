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
	mlx_destroy_image(mlx->mlx_ptr, mlx->player->img);
	
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->floor[0]->img, mlx->player->posx, mlx->player->posy);
	mlx->player->posy -= mlx->player->h;
	mlx->player->img = mlx_xpm_file_to_image(mlx->mlx_ptr, PLAYER_IMG, &((mlx->player)->w), &((mlx->player)->h));
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->player->img, (mlx->player)->posx, (mlx->player)->posy);
}

void	move_down(t_mlx *mlx)
{
	mlx_destroy_image(mlx->mlx_ptr, mlx->player->img);
	
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->floor[0]->img, mlx->player->posx, mlx->player->posy);
	mlx->player->posy += mlx->player->h;
	mlx->player->img = mlx_xpm_file_to_image(mlx->mlx_ptr, PLAYER_IMG, &((mlx->player)->w), &((mlx->player)->h));
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->player->img, (mlx->player)->posx, (mlx->player)->posy);
	
}

void	move_left(t_mlx *mlx)
{
	mlx_destroy_image(mlx->mlx_ptr, mlx->player->img);
	
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->floor[0]->img, mlx->player->posx, mlx->player->posy);
	mlx->player->posx -= mlx->player->w;
	mlx->player->img = mlx_xpm_file_to_image(mlx->mlx_ptr, PLAYER_IMG, &((mlx->player)->w), &((mlx->player)->h));
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->player->img, (mlx->player)->posx, (mlx->player)->posy);
}

void	move_right(t_mlx *mlx)
{
	mlx_destroy_image(mlx->mlx_ptr, mlx->player->img);
	
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->floor[0]->img, mlx->player->posx, mlx->player->posy);
	mlx->player->posx += mlx->player->w;
	mlx->player->img = mlx_xpm_file_to_image(mlx->mlx_ptr, PLAYER_IMG, &((mlx->player)->w), &((mlx->player)->h));
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->player->img, (mlx->player)->posx, (mlx->player)->posy);
}
