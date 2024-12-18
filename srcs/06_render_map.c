/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   06_render_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izperez <izperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 10:49:19 by izperez           #+#    #+#             */
/*   Updated: 2024/12/18 12:31:25 by izperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static void	draw_square_utils(t_data *data, int d_x, int d_y, int color)
{
	int	x;
	int	y;

	y = 0;
	while (y < TILE_SIZE)
	{
		x = 0;
		while (x < TILE_SIZE)
		{
			if (x == 0 || x == TILE_SIZE - 1 || y == 0 || y == TILE_SIZE - 1)
				my_mlx_pixel_put(data, x + d_x * TILE_SIZE,
					y + d_y * TILE_SIZE, NEGRO);
			else
				my_mlx_pixel_put(data, x + d_x * TILE_SIZE,
					y + d_y * TILE_SIZE, color);
			x++;
		}
		y++;
	}
}

void	draw_square(t_data *data, char c, int d_x, int d_y)
{
	int	x;
	int	y;
	int	color;

	if (c == '1')
		color = GRIS;
	else if (c == '0')
		color = BLANCO;
	else if (c == 'N' || c == 'S' || c == 'E' || c == 'O')
		color = BLANCO;
	else
		color = NEGRO;
	draw_square_utils(data, d_x, d_y, color);
}

void	calculate_fov(t_data *data)
{
	float	start_des;
	float	end_des;
	int		i;
	float	j;

	i = 0;
	j = (start_des - end_des) / data->mlx->width_window;
	start_des = 35 * (PI / 180.0) + (PI / 2);
	end_des = -35 * (PI / 180.0) + (PI / 2);
	while (start_des >= end_des)
	{
		prepare_rays(data, start_des, 3000);
		start_des -= j;
		i++;
	}
	mlx_put_image_to_window(data->mlx->mlx, data->mlx->win,
		data->mlx->img, 0, 0);
}

void	draw_line(t_data *data, float x_start, float y_start, float angle, float steps)
{
	float x_end = x_start + steps * cos(angle);
	float y_end = y_start + steps * sin(angle);
	int	color = 0;
	int	i = 0;
	float t;
	int x_current;
	int y_current;

	x_current = 0;
	y_current = 0;
	while (i++ < steps)
	{
		t = (float)i / (float)steps;
		x_current = (int)(x_start + t * (x_end - x_start));
		y_current = (int)(y_start + t * (y_end - y_start));
		if (x_current < 0 || x_current >= (data->map->width * TILE_SIZE) || y_current < 0 || y_current >= (data->map->width * TILE_SIZE))
			break ;
		if (data->map->grid[(int)(x_current / TILE_SIZE)][(int)(y_current / TILE_SIZE)] && data->map->grid[(int)(x_current / TILE_SIZE)][(int)(y_current / TILE_SIZE)] == '1')
			break ;
	}
	if (((ft_distancia(x_current, y_current, data->playerpos)) / cos(angle * (PI / 360))) == 0)
		return ;
	draw_colum(data, color, ((TILE_SIZE * data->mlx->height_window) / (ft_distancia(x_current, y_current, data->playerpos)) / cos(angle * (PI / 360))), x_current, y_current);
}

void	ft_drawcf(t_data *data)
{
	int	x;
	int	y;
	int	horizonte;

	horizonte = data->mlx->height_window / 2;
	y = 0;
	while (y <= data->mlx->height_window)
	{
		x = 0;
		while (x <= data->mlx->width_window)
		{
			if (y <= horizonte)
				my_mlx_pixel_put(data, x, y, data->asset->cieling_rgb);
			else
				my_mlx_pixel_put(data, x, y, data->asset->floor_rgb);
			x++;
		}
		y++;
	}
}
