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

void	draw_floor(t_mlx *mlx, char **map)
{
	int	i;
	int	j;
	int	k;

	i = 1;
	k = 0;
	while (map[i + 1])
	{
		j = 1;
		while (map[i][j + 1])
		{
			if (map[i][j] != '1')
			{
				mlx_put_image_to_window(mlx->mlx_ptr,
					mlx->win_ptr, mlx->floor[k]->img,
					j * (mlx->floor[k])->w, i * (mlx->floor[k])->h);
				k++;
			}
			j++;
		}
		i++;
	}
}

void	draw_walls(t_mlx *mlx, char **map)
{
	int		i;
	int		j;
	int		k;

	k = 0;
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == '1')
			{
				mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr,
					mlx->walls[k]->img,
					j * mlx->walls[k]->w, i * mlx->walls[k]->h);
				k++;
			}
			j++;
		}
		i++;
	}
}

void	draw_collect(t_mlx *mlx, char **map)
{
	int		i;
	int		j;
	int		k;

	k = 0;
	i = 1;
	while (map[i + 1])
	{
		j = 1;
		while (map[i][j + 1])
		{
			if (map[i][j] == 'C')
			{
				mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr,
					mlx->collect[k]->img,
					mlx->collect[k]->posx, mlx->collect[k]->posy);
				k++;
			}
			j++;
		}
		i++;
	}
}

void	draw_exit(t_mlx *mlx)
{
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->exit->img,
		mlx->exit->posx, mlx->exit->posy);
}
