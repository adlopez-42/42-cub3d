/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izperez <izperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 14:20:38 by adrian            #+#    #+#             */
/*   Updated: 2024/12/19 12:38:53 by izperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	load_image(void *patata)
{
	t_data	*data;

	data = (t_data *)patata;
	mlx_clear_window(data->mlx->mlx, data->mlx->win);
	ft_drawcf(data);
	calculate_fov(data);
	mlx_put_image_to_window(data->mlx->mlx, data->mlx->win,
		data->mlx->img, 0, 0);
	return (0);
}

char	*ft_clean_path(char *oldpath)
{
	int		idx;
	int		idy;
	char	*newpath;

	newpath = malloc(sizeof(char *) * 1024);
	idx = 3;
	idy = 0;
	while (oldpath[idx])
	{
		newpath[idy] = oldpath[idx];
		idx++;
		idy++;
	}
	newpath[idy] = '\0';
	return (newpath);
}

void	ft_textures_mlxinit(t_data **data)
{
	(*data)->n_texture = ft_setup_texture(ft_clean_path
			((*data)->asset->north_texture), (*data)->mlx);
	(*data)->s_texture = ft_setup_texture(ft_clean_path
			((*data)->asset->south_texture), (*data)->mlx);
	(*data)->w_texture = ft_setup_texture(ft_clean_path
			((*data)->asset->west_texture), (*data)->mlx);
	(*data)->e_texture = ft_setup_texture(ft_clean_path
			((*data)->asset->east_texture), (*data)->mlx);
}

void	ft_cub3d(t_data *data)
{
	ft_textures_mlxinit(&data);
	load_image(data);
	mlx_hook(data->mlx->win, 2, 3, *ft_hooks, data);
	mlx_key_hook(data->mlx->win, *ft_close, data);
	mlx_loop_hook(data->mlx->mlx, load_image, data);
	mlx_loop(data->mlx->mlx);
}

int	main(int argc, char **argv)
{
	t_data		*data;
	t_checks	*checker;
	int			fd;

	if (argc == 1 || ft_cub(argv[1]) == 0)
		ft_error(0);
	fd = open(argv[1], O_RDONLY);
	checker = ft_setup_checker(fd);
	if (ft_parse(checker) == 1)
		data = ft_setup_data(checker);
	if (data)
	{
		ft_cub3d(data);
		ft_free_data(data);
	}
	return (1);
}
