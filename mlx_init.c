#include "so_long.h"

t_chars	calculate_size(t_images *img, char **map)
{
	t_chars chars;

	chars.p = ft_strlen(map[0]) * img->wall->w;
	chars.e = ptr_arr_len(map) * img->wall->h;
	return (chars);
}

t_images	*allocate_struct(void)
{
	t_images	*img;
	
	img = malloc(sizeof (*img));
	if (!img)
		return (NULL);
	img->player = malloc(sizeof (*(img->player)));
	img->wall = malloc(sizeof (*(img->wall)));
	img->collect = malloc(sizeof (*(img->collect)));
	img->empty = malloc(sizeof (*(img->empty)));
	img->exit = malloc(sizeof (*(img->exit)));
	return (img);
}

t_images	*init_images(void *mlx_ptr)
{
	t_images	*img;

	img = allocate_struct();
	img->player->img = mlx_xpm_file_to_image(mlx_ptr, "images/star.xpm",
			&(img->player->w), &(img->player->h));
	img->wall->img = mlx_xpm_file_to_image(mlx_ptr, "images/star.xpm",
			&(img->wall->w), &(img->wall->h));
	img->empty->img = mlx_xpm_file_to_image(mlx_ptr, "images/star.xpm",
			&(img->empty->w), &(img->empty->h));
	img->collect->img = mlx_xpm_file_to_image(mlx_ptr, "images/star.xpm",
			&(img->collect->w), &(img->collect->h));
	img->exit->img = mlx_xpm_file_to_image(mlx_ptr, "images/E.xpm",
			&(img->exit->w), &(img->exit->h));
	return (img);
}


void	draw_images(t_mlx *mlx, t_images **img, char **map)
{
	int	i;
	int	j;
	void	*xpm;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == '1')
				xpm = (*img)->wall->img;
			else if (map[i][j] == 'P')
			{
				(*img)->player->posx = j * (*img)->wall->w;
				(*img)->player->posy = i * (*img)->wall->h;
				xpm = (*img)->player->img;
			}
			else if (map[i][j] == 'E')
				xpm = (*img)->exit->img;
			else if (map[i][j] == 'C')
				xpm = (*img)->collect->img;
			else
				xpm = (*img)->empty->img;
			mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, xpm, j * (*img)->wall->w, i * (*img)->wall->h);
			j++;	
		}
		i++;
	}
}

void	mlx_init_stuff(char **map)
{
	void		*xpm;
	t_mlx		mlx;
	t_chars		size;
	t_images	*img;

	mlx.mlx_ptr = mlx_init();
	mlx.img = init_images(mlx.mlx_ptr);
	size = calculate_size(mlx.img, map);
	ft_printf("%d %d\n", size.p, size.e);
	ft_printf("%d %d\n", mlx.img->wall->w, mlx.img->wall->h);
	mlx.win_ptr = mlx_new_window(mlx.mlx_ptr, size.p, size.e, "Hello");
	//mlx.img_ptr = img->player->img;
	mlx_key_hook(mlx.win_ptr, &key_hook, &mlx);
	mlx_mouse_hook(mlx.win_ptr, &mouse_hook, 0);
	mlx_hook(mlx.win_ptr, 17, 0, &hook, 0);
	int a, b;
	void	*skybox = mlx_xpm_file_to_image(mlx.mlx_ptr, "images/skybox.xpm", &a, &b);
	mlx_put_image_to_window(mlx.mlx_ptr, mlx.win_ptr, skybox, -1000, 0);

	//mlx_key_hook(mlx.win_ptr, &key_hook, 0);

	draw_images(&mlx, &mlx.img, map);
	mlx_loop(mlx.mlx_ptr);
}
