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

t_img	*allocate_collect(t_mlx *mlx)
{
	int		x;
	int		y;
	t_img	*collect;

	collect = malloc(sizeof (*collect));
	if (!collect)
		ft_printf(RED "COLLECT IS DEAD");
	collect->img = mlx_xpm_file_to_image(mlx->mlx_ptr,
			COLLECT_IMG, &(collect->w), &(collect->h));
	if (!collect->img)
		ft_printf(MAGENTA "mlx failed at collect");
	return (collect);
}
