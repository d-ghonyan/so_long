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

t_img	*allocate_floor(t_mlx *mlx)
{
	int		x;
	int		y;
	t_img	*floor;

	floor = malloc(sizeof (*floor));
	if (!floor)
		ft_printf(RED "FLOOR IS DEAD");
	floor->img = mlx_xpm_file_to_image(mlx->mlx_ptr,
			FLOOR_IMG, &(floor->w), &(floor->h));
	if (!floor->img)
		ft_printf(MAGENTA "mlx failed at floor");
	return (floor);
}
