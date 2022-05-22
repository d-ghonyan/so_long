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

static t_img	*helper(void *mlx_ptr, int i, int j)
{
	t_img	*floor;

	floor = malloc(sizeof (*floor));
	if (!floor)
	{
		ft_printf(RED "Couldn't allocate memory for floor");
		return (NULL);
	}
	floor->img = mlx_xpm_file_to_image(mlx_ptr,
			FLOOR_IMG, &(floor->w), &(floor->h));
	if (!floor->img)
	{
		ft_printf(RED "MLX failed to allocate image for floor");
		return (NULL);
	}
	floor->i = i;
	floor->j = j;
	floor->posy = i * floor->h;
	floor->posx = j * floor->w;
	return (floor);
}

t_img	**allocate_floor(t_mlx *mlx)
{
	int		i;
	int		j;
	int		k;
	t_img	**floor;

	i = 0;
	k = 0;
	floor = malloc(sizeof (*floor) * ((get_count_reverse(mlx->map, '1') + 1)));
	if (!floor)
		ft_printf(RED "OH NO" COLOR_RESET);
	while (mlx->map[i])
	{
		j = 0;
		while (mlx->map[i][j])
		{
			if (mlx->map[i][j] != '1')
			{
				floor[k] = helper(mlx->mlx_ptr, i, j);
				k++;
			}
			j++;
		}
		i++;
	}
	floor[k] = NULL;
	return (floor);
}
