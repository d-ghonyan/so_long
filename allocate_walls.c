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

t_img	*allocate_walls(t_mlx *mlx)
{
	int		x;
	int		y;
	t_img	*walls;

	walls = malloc(sizeof (*walls));
	if (!walls)
		ft_printf(RED "WALL IS DEAD");
	walls->img = mlx_xpm_file_to_image(mlx->mlx_ptr,
			WALL_IMG, &(walls->w), &(walls->h));
	if (!walls->img)
		ft_printf(MAGENTA "mlx failed at walls");
	return (walls);
}
