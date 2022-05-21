#include "so_long.h"

// t_chars	calculate_size(t_images *img, char **map)
// {
// 	t_chars chars;

// 	chars.p = ft_strlen(map[0]) * img->empty->w;
// 	chars.e = ptr_arr_len(map) * img->empty->h;
// 	return (chars);
// }

// t_images	*allocate_struct(void)
// {
// 	t_images	*img;
	
// 	img = malloc(sizeof (*img));
// 	if (!img)
// 		return (NULL);
// 	img->player = malloc(sizeof (*(img->player)));
// 	img->wall = malloc(sizeof (*(img->wall)));
// 	img->collect = malloc(sizeof (*(img->collect)));
// 	img->empty = malloc(sizeof (*(img->empty)));
// 	img->exit = malloc(sizeof (*(img->exit)));
// 	return (img);
// }

// t_images	*init_images(void *mlx_ptr)
// {
// 	t_images	*img;

// 	img = allocate_struct();
// 	img->player->img = mlx_xpm_file_to_image(mlx_ptr, "images/star.xpm",
// 			&(img->player->w), &(img->player->h));
// 	img->wall->img = mlx_xpm_file_to_image(mlx_ptr, "images/star.xpm",
// 			&(img->wall->w), &(img->wall->h));
// 	img->empty->img = mlx_xpm_file_to_image(mlx_ptr, "images/0.xpm",
// 			&(img->empty->w), &(img->empty->h));
// 	// ft_printf(RED "%d %d\n" COLOR_RESET, img->empty->w, img->empty->h);
// 	img->collect->img = mlx_xpm_file_to_image(mlx_ptr, "images/star.xpm",
// 			&(img->collect->w), &(img->collect->h));
// 	img->exit->img = mlx_xpm_file_to_image(mlx_ptr, "images/E.xpm",
// 			&(img->exit->w), &(img->exit->h));
// 	return (img);
// }


// void	draw_images(t_mlx *mlx, t_images **img, char **map)
// {
// 	int	i;
// 	int	j;
// 	void	*xpm;

// 	i = 0;
// 	while (map[i])
// 	{
// 		j = 0;
// 		while (map[i][j])
// 		{
// 			xpm = (*img)->empty->img;
// 			mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, xpm, j * (*img)->empty->w, i * (*img)->empty->h);
// 			j++;	
// 		}
// 		i++;
// 	}
// }

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

void	mlx_init_stuff(char **map)
{
	t_mlx		mlx;
	t_chars		size;

	int	i;
	int	j;
	int	k;

	i = 0;
	k = 0;
	mlx.imgs = malloc(sizeof (*mlx.imgs) * (ptr_arr_len(map) * ft_strlen(map[0]) + 1));

	if (!mlx.imgs)
		ft_printf(CYAN "OH NO");

	mlx.mlx_ptr = mlx_init();

	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			mlx.imgs[k] = malloc(sizeof (**mlx.imgs));
			(mlx.imgs[k])->img = mlx_xpm_file_to_image(mlx.mlx_ptr, "images/0.xpm", &((mlx.imgs[k])->w), &((mlx.imgs[k])->h));
			k++;
			j++;
		}
		i++;
	}


	mlx.imgs[k] = NULL;

	mlx.player = malloc(sizeof (*mlx.player));
	if (!mlx.player)
		ft_printf(YELLOW "OH NO AGAIN" COLOR_RESET);
	mlx.player->img = mlx_xpm_file_to_image(mlx.mlx_ptr, "images/P.xpm", &((mlx.player)->w), &((mlx.player)->h));

	mlx.player->posx = 2 * mlx.player->w;
	mlx.player->posy = mlx.player->h * 2;

	ft_printf(MAGENTA "%d %d %d %d\n", mlx.player->w, mlx.player->h, mlx.player->posx, mlx.player->posy);

	mlx.win_ptr = mlx_new_window(mlx.mlx_ptr, mlx.imgs[0]->w * ft_strlen(map[0]), mlx.imgs[0]->h * ptr_arr_len(map), "Hello");
	mlx.win_size_w = mlx.imgs[0]->w * ft_strlen(map[0]);
	mlx.win_size_h = mlx.imgs[0]->h * ptr_arr_len(map);
	i = 0;
	k = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			mlx_put_image_to_window(mlx.mlx_ptr, mlx.win_ptr, mlx.imgs[k]->img, j * (mlx.imgs[k])->w, i * (mlx.imgs[k])->h);
			k++;
			j++;
		}
		i++;
	}
	i = 2;
	j = 2;

	mlx_put_image_to_window(mlx.mlx_ptr, mlx.win_ptr, mlx.player->img, j * (mlx.player)->w, i * (mlx.player)->h);


	i = 0;
	k = 0;

	mlx_key_hook(mlx.win_ptr, &key_hook, &mlx);
	mlx_hook(mlx.win_ptr, 17, 0, &hook, 0);
	mlx_do_key_autorepeaton(mlx.mlx_ptr);
	mlx_loop(mlx.mlx_ptr);
}

			// if (map[i][j] == '1')
			// 	ft_strcpy(path, "images/1.xpm");
			// else if (map[i][j] == 'P')
			// 	ft_strcpy(path, "images/P.xpm");
			// else if (map[i][j] == 'E')
			// 	ft_strcpy(path, "images/E.xpm");
			// else if (map[i][j] == 'C')
			// 	ft_strcpy(path, "images/C.xpm");
			// else

				// while (map[i])
	// {
	// 	j = 0;
	// 	while (map[i][j])
	// 	{
	// 		mlx_destroy_image(mlx.mlx_ptr, mlx.imgs[k]->img);
	// 		k++;
	// 		j++;
	// 	}
	// 	i++;
	// }