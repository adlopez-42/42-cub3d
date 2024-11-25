/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   09_map2d.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izperez <izperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 19:48:51 by izperez           #+#    #+#             */
/*   Updated: 2024/11/25 20:13:03 by izperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"
# define TILE_SIZE 64

void	draw_squares(t_data *data, int x, int y, int color)
{
	int	i;
	int	j;

	i = 0;
	while (i < TILE_SIZE)
	{
		j = 0;
		while (j < TILE_SIZE)
		{
			mlx_pixel_put(data->mlx.mlx_ptr, data->mlx.win_ptr, x * TILE_SIZE + j, y * TILE_SIZE + i, color);
			j++;
		}
		i++;
	}
}

void	draw_map(t_data *data)
{
	int x;
	int	y;

	y = 0;
	while (data->map[y])
	{
		x = 0;
		while (data->map[y][x])
		{
			if (data->map[y][x] == '1')
				draw_squares(data, x, y, 0x8B4513);
			else if (data->map[y][x] == '0')
				draw_squares(data, x, y, 0xFFFFFF);
			else if (data->map[y][x] == 'N' || data->map[y][x] == 'S' || data->map[y][x] == 'E' || data->map[y][x] == 'O')
				draw_squares(data, x, y, 0xFF0000);
			x++;
		}
		y++;
	}	
}



