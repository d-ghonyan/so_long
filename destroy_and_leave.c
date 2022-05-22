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

static void	destroy_floor(t_mlx *mlx)
{
	int	i;

	i = 0;
	while (mlx->floor[i])
	{
		mlx_destroy_image(mlx->mlx_ptr, mlx->floor[i]->img);
		free(mlx->floor[i]);
		i++;
	}
	free(mlx->floor);
	exit (EXIT_SUCCESS);
}

static void	destroy_walls(t_mlx *mlx)
{
	int	i;

	i = 0;
	while (mlx->walls[i])
	{
		mlx_destroy_image(mlx->mlx_ptr, mlx->walls[i]->img);
		free(mlx->walls[i]);
		i++;
	}
	free(mlx->walls);
	exit (EXIT_SUCCESS);
}

static void	destroy_collect(t_mlx *mlx)
{
	int	i;

	i = 0;
	while (mlx->collect[i])
	{
		mlx_destroy_image(mlx->mlx_ptr, mlx->collect[i]->img);
		free(mlx->collect[i]);
		i++;
	}
	free(mlx->collect);
	exit (EXIT_SUCCESS);
}

void	destroy_and_leave(t_mlx *mlx)
{
	mlx_destroy_image(mlx->mlx_ptr, mlx->exit->img);
	mlx_destroy_image(mlx->mlx_ptr, mlx->player->img);
	free(mlx->exit);
	free(mlx->player);
	free_ptr_arr(mlx->map);
	destroy_floor(mlx);
	destroy_collect(mlx);
	destroy_walls(mlx);
	mlx_destroy_window(mlx->mlx_ptr, mlx->win_ptr);
	exit(EXIT_SUCCESS);
}
