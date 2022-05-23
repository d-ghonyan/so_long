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

static void	ft_strcpy(char *s1, const char *s2)
{
	int	j;

	j = 0;
	while (s2[j])
	{
		s1[j] = s2[j];
		j++;
	}
	s1[j] = '\0';
}

static void	init(t_mlx *mlx)
{
	mlx->collect_count = get_count(mlx->map, 'C');
	mlx->walls = allocate_walls(mlx);
	mlx->floor = allocate_floor(mlx);
	mlx->collect = allocate_collect(mlx);
	mlx->player = allocate_player(mlx);
	mlx->exit = allocate_exit(mlx);
	mlx->win_size_w = mlx->floor->w * ft_strlen(mlx->map[0]);
	mlx->win_size_h = mlx->floor->h * ptr_arr_len(mlx->map);
	mlx->win_ptr = mlx_new_window(mlx->mlx_ptr,
			mlx->win_size_w, mlx->win_size_h, "Hewwo");
	draw_floor(mlx, mlx->map);
	draw_walls(mlx, mlx->map);
	draw_collect(mlx, mlx->map);
	draw_exit(mlx);
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr,
		mlx->player->img, mlx->player->posx, mlx->player->posy);
}

void	mlx_init_stuff(char *filename)
{
	t_mlx		mlx;

	mlx.mlx_ptr = mlx_init();
	perror_exit_cond("can't init mlx", !mlx.mlx_ptr);
	mlx.map = parse_map(filename);
	init(&mlx);
	mlx_key_hook(mlx.win_ptr, &key_hook, &mlx);
	mlx_hook(mlx.win_ptr, 17, 0, &hook, &mlx);
	mlx_loop(mlx.mlx_ptr);
}
