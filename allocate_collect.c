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
	t_img	*collect;

	collect = malloc(sizeof (*collect));
	if (!collect)
		ft_printf(BLUE "NO COLLECT BLIN");
	collect->i = i;
	collect->j = j;
	collect->img = mlx_xpm_file_to_image(mlx->mlx_ptr,
			COLLECT_IMG,
			&(collect->w), &(collect->h));
	collect->posx = (j * mlx->floor[0]->w)
		+ ((mlx->floor[0]->w / 2))
		- (collect->w / 2);
	collect->posy = (i * mlx->floor[0]->h)
		+ ((mlx->floor[0]->h / 2))
		- (collect->h / 2);
	if (!collect->img)
		ft_printf(YELLOW "OH NO AGAIN WALLS IMG" COLOR_RESET);
	return (collect);
}

t_img	**allocate_collect(t_mlx *mlx)
{
	int		i;
	int		j;
	int		k;
	t_img	**collect;

	i = 0;
	k = 0;
	collect = malloc(sizeof (*collect) * (get_count(mlx->map, 'C') + 1));
	if (!collect)
		ft_printf(RED "OH NO" COLOR_RESET);
	while (mlx->map[i])
	{
		j = 0;
		while (mlx->map[i][j])
		{
			if (mlx->map[i][j] == 'C')
			{
				collect[k] = helper(mlx, i, j);
				k++;
			}
			j++;
		}
		i++;
	}
	collect[k] = NULL;
	return (collect);
}
