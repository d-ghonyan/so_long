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

static t_img	*helper(t_mlx *mlx, int i, int j)
{
	t_img	*walls;

	walls = malloc(sizeof (*walls));
	if (!walls)
		ft_printf(MAGENTA "NO WALSS NOOOO");
	walls->i = i;
	walls->j = j;
	walls->img = mlx_xpm_file_to_image(mlx->mlx_ptr, WALL_IMG,
			&(walls->w), &(walls->h));
	if (!walls->img)
		ft_printf(YELLOW "NO WALLS AGAIN OMG" COLOR_RESET);
	return (walls);
}

t_img	**allocate_walls(t_mlx *mlx)
{
	int		i;
	int		j;
	int		k;
	t_img	**walls;

	i = 0;
	k = 0;
	walls = malloc(sizeof (*walls) * (get_count(mlx->map, '1') + 1));
	if (!walls)
		ft_printf(RED "OH NO" COLOR_RESET);
	while (mlx->map[i])
	{
		j = 0;
		while (mlx->map[i][j])
		{
			if (mlx->map[i][j] == '1')
			{
				walls[k] = helper(mlx, i, j);
				k++;
			}
			j++;
		}
		i++;
	}
	walls[k] = NULL;
	return (walls);
}
