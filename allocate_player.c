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

void	printf_exit_cond(char *s, int cond)
{
	if (cond)
	{
		ft_printf(RED "%s\n" COLOR_RESET, s);
		exit (EXIT_FAILURE);
	}
}

t_img	*allocate_player(t_mlx *mlx)
{
	int		x;
	int		y;
	t_img	*player;

	player = malloc(sizeof (*player));
	printf_exit_cond("Can't allocate player", !player);
	player->img = mlx_xpm_file_to_image(mlx->mlx_ptr,
			PLAYER_IMG, &(player->w), &(player->h));
	if (!player->img)
	{
		free(player);
		ft_printf(MAGENTA "mlx failed at player" COLOR_RESET);
		exit(EXIT_FAILURE);
	}
	x = get_player_position(mlx->map).x;
	y = get_player_position(mlx->map).y;
	player->i = x;
	player->j = y;
	player->posx = (x * mlx->floor->w)
		+ ((mlx->floor->w / 2)) - (player->w / 2);
	player->posy = (y * mlx->floor->h)
		+ ((mlx->floor->h / 2)) - (player->h / 2);
	return (player);
}

t_pos	get_player_position(char **map)
{
	int		i;
	int		j;
	t_pos	pos;

	i = 1;
	pos.x = 0;
	pos.y = 0;
	while (map[i + 1])
	{
		j = 1;
		while (map[i][j + 1])
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
