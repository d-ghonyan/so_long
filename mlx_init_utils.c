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

t_img	**allocate_floor(void *mlx_ptr, char **map)
{
	int		i;
	int		j;
	int		k;
	t_img	**floor;

	i = 0;
	k = 0;
	floor = malloc(sizeof (*floor) * (ft_strlen(map[0]) * ptr_arr_len(map) + 1));
	if (!floor)
		ft_printf(RED "OH NO" COLOR_RESET);
	while (map[i])
	{
		j = 0;
		while (map[i][j++])
		{
			floor[k] = malloc(sizeof (**floor));
			if (!floor[k])
				ft_printf(MAGENTA "OH NO AGAIN" COLOR_RESET);
			floor[k]->img = mlx_xpm_file_to_image(mlx_ptr, "images/0.xpm", &(floor[k]->w), &(floor[k]->h));
			k++;
		}
		i++;
	}
	floor[k] = NULL;
	return (floor);
}

void	draw_floor(t_mlx *mlx, char **map)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	k = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->floor[k]->img, j * (mlx->floor[k])->w, i * (mlx->floor[k])->h);
			k++;
			j++;
		}
		i++;
	}
}

void	draw_walls(t_mlx *mlx, char **map)
{
	int		i;
	int		j;
	int		x;
	int		y;
	void	*img;

	mlx->walls->img = mlx_xpm_file_to_image(mlx->mlx_ptr, "images/E.xpm", &x, &y);
	if (!img)
		ft_printf("mlx failed at draw_walls");
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == '1')
				mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->walls->img, j * x, i * y);
			j++;
		}
		i++;
	}
}

t_pos	get_player_position(char **map)
{
	int		i;
	int		j;
	t_pos	pos;

	i = 0;
	pos.x = 0;
	pos.y = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'P')
			{
				pos.x = j;
				pos.y = i;
				return (pos);
			}
			j++;
		}
		i++;
	}
	return (pos);
}

t_player	*allocate_player(void *mlx_ptr)
{
	t_player	*player;

	player = malloc(sizeof (*player));
	if (!player)
		ft_printf(RED "PLAYER IS DEAD");
	player->img = mlx_xpm_file_to_image(mlx_ptr, "images/P.xpm", &((player)->w), &((player)->h));
	if (!player->img)
		ft_printf(MAGENTA "mlxfailed at player");
	return (player);
}