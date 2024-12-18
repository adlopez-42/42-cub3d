/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   08_3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izperez <izperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 13:46:56 by izperez           #+#    #+#             */
/*   Updated: 2024/12/18 12:44:00 by izperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void draw_colum(t_data *data, int dist_wall, int x_current, int y_current)
{
	static int x = 0;
	int	y;
	int	horizonte;
	int	texture_color;
	int	x_text;
	int	y_text;

	horizonte = data->mlx->height_window / 2;
	y = 0;

	if (x == data->mlx->width_window)
		x = 0;
	int start = horizonte - dist_wall;
	int end = horizonte + dist_wall;
	(void)y_current;

	while (y <= data->mlx->height_window)
	{
		if (y >= start && y <= end)
		{
			y_text = (y - start) * 500 / (end - start);
			int flag = ft_north_south(x_current, y_current);
			int local_coord = (flag ? y_current : x_current) % TILE_SIZE;
			x_text = local_coord * 500 / TILE_SIZE;
			texture_color = ft_texture_color(x_current, y_current, data, x_text, y_text);
			my_mlx_pixel_put(data, x, y, texture_color);
		}
		y++;
	}
	x++;
}

int	ft_north_south(int x, int y)
{
	int	color;

	color = 0;
	if ((x % TILE_SIZE == 0 || (x + 1) % TILE_SIZE == 0) && \
		(y % TILE_SIZE == 0 || (y + 1) % TILE_SIZE == 0))
		color = 0;
	else if ((y % TILE_SIZE) == 0)
		color = 0;
	else if ((x % TILE_SIZE) == 0)
		color = 1;
	else if (((x + 1) % (TILE_SIZE)) == 0)
		color = 1;
	else if (((y + 1) % (TILE_SIZE)) == 0)
		color = 0;
	else
		color = 0;
	return (color);
}
