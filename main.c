/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izperez <izperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 14:20:38 by adrian            #+#    #+#             */
/*   Updated: 2024/12/05 13:21:20 by izperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	load_image(t_data *data)
{
	//mlx_clear_window(data->mlx->mlx, data->mlx->win);
	ft_drawcf(data);
	calculate_fov(data);
	mlx_put_image_to_window(data->mlx->mlx, data->mlx->win, data->mlx->img, 0, 0);
}


void	ft_cub3d(t_data *data)
{
	load_image(data);
	mlx_hook(data->mlx->win, 2, 3, *ft_hooks, data);
	mlx_hook(data->mlx->win, 17, 0, *ft_close, data);
	mlx_key_hook(data->mlx->win, *ft_close, data);
	mlx_loop(data->mlx->mlx);
		
}

/* void	ft_print_data(t_data *data)
{
	int	idx = 0;
	while (data->map->grid[idx])
	{
		printf("map [%i] -> %s\n", idx, data->map->grid[idx]);
		idx++;
	}
	printf("map W -> %i\n", data->map->width);
	printf("map H -> %i\n", data->map->height);
	printf("assets -> NO %s\n", data->asset->north_texture);
	printf("assets -> SO %s\n", data->asset->south_texture);
	printf("assets -> WE %s\n", data->asset->west_texture);
	printf("assets -> EA %s\n", data->asset->east_texture);
	printf("Floor rgbs %i, %i, %i\n", data->asset->floor_rgb[0], data->asset->floor_rgb[1], data->asset->floor_rgb[2]);
	printf("Cieling rgbs %i, %i, %i\n", data->asset->cieling_rgb[0], data->asset->cieling_rgb[1], data->asset->cieling_rgb[2]);
	printf("Player pos x -> %f\n", data->playerpos->x);
	printf("Player pos y -> %f\n", data->playerpos->y);
	printf("Player orientation -> %f (0 no, 1 so, 2 we, 3 ea)\n", data->playerpos->dir);
} */

/* void	ft_print_checker(t_checks *checker)
{
	printf("north texture -> %s\n", checker->north_texture);
	printf("south texture -> %s\n", checker->south_texture);
	printf("west texture -> %s\n", checker->west_texture);
	printf("east texture -> %s\n", checker->east_texture);
	printf("floor rgbs -> %i, %i, %i\n", checker->f_red, checker->f_green, checker->f_blue);
	printf("cieling rgbs -> %i, %i, %i\n", checker->c_red, checker->c_green, checker->c_blue);
	printf("map[0] %s\nmap[1] %s\nmap[2] %s\n...\n", checker->map[0], checker->map[1], checker->map[2]);
	return ;
} */

int	main(int argc, char **argv)
{
	t_data		*data;
	t_checks	*checker;
	int			fd;

	if (argc == 1 || ft_cub(argv[1]) == 0)
		ft_error(0);
	fd = open(argv[1], O_RDONLY);
	checker = ft_setup_checker(fd);
	// ft_print_checker(checker)
	if (ft_parse(checker) == 1)
		data = ft_setup_data(checker);
	//ft_free_checker(checker);
	//ft_print_data(data);
	if (data)
	{
		ft_cub3d(data);
		ft_free_data(data);
	}
	return (1);
}
