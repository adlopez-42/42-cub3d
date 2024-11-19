/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 12:57:00 by adlopez-          #+#    #+#             */
/*   Updated: 2024/11/19 12:55:35 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d.h"

int	ft_close(int keycode, t_data *data)
{
	(void)data;
	if (keycode == ESC)
		mlx_destroy_window(data->mlx.mlx, data->mlx.win);
	return (keycode);
}

void	ft_cub3d(t_data data)
{
	mlx_hook(data.mlx.win, 2, 1L<<0, ft_close, &data);
	mlx_loop(data.mlx.mlx);
}

int main(int argc, char **argv)
{
	t_data		data;
	int			fd;

	if (argc == 1 || ft_cub(argv[1]) == 0)
		ft_error(0);
	fd = open(argv[1], O_RDONLY);
	if (ft_parse_map(fd) == 1)
	{
		data = ft_setup_data(fd);
		ft_print_data(data);
	}
	if (data)
	{
		ft_cub3d(data);
		ft_free_data(data);
	}
	return (0);
}

void	ft_print_data(t_data data)
{
	int	idx;

	idx = 0;	
	printf("----DATA----\n");
	printf("playerpos->x -> %f\n", data.player_position->x);
	printf("playerpos->y -> %f\n", data.player_position->y);
	printf("player dir-> %i\n", data.player_position->dir);
	printf("cieling red-> %i\n", data.asset->cieling_rgb[0]);
	printf("cieling green-> %i\n", data.asset->cieling_rgb[1]);
	printf("cieling blue-> %i\n", data.asset->cieling_rgb[2]);
	printf("floor red-> %i\n", data.asset->floor_rgb[0]);
	printf("floor green-> %i\n", data.asset->floor_rgb[1]);
	printf("floor blue-> %i\n", data.asset->floor_rgb[2]);
	printf("north texture-> %s\n", data.asset->north_texture);
	printf("south texture-> %s\n", data.asset->south_texture);
	printf("east texture-> %s\n", data.asset->east_texture);
	printf("west texture-> %s\n", data.asset->west_texture);
	while (data.map[idx] != NULL)
		printf("map-> %s\n", data.map[idx++]);
}

void	ft_free_data(t_data data)
{
	(void)data;
	//free todo.
}
