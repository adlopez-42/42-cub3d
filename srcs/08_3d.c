/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   08_3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izperez <izperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 13:46:56 by izperez           #+#    #+#             */
/*   Updated: 2024/12/11 12:23:09 by izperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

//1. Coger el horizonte y pintar mitad arriba y mitad abajo con las color techo y suelo
//2. Me llega la distancia y el color de lo que voy a pintar. Depende de que parte de la pared pintar de colores
//3. Identificar en que columna estoy pintando. Por cada rayo pintar en una columna
//Esta función pinta el fondo del juego
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

// //Esta función pinta las columnas en función de los rayos y su distancia.
// void	draw_colum(t_data *data, int color, int dist_wall)
// {
// 	static int	x = 0;
// 	int			y;
// 	int			horizonte;

// 	dist_wall = dist_wall * 10;
// 	horizonte = data->mlx->height_window / 2;
// 	y = 0;
// 	if (x == data->mlx->width_window)
// 		x = 0;

// 	while (y <= data->mlx->height_window)
// 	{
// 		if (horizonte == y)
// 		{
// 			//my_mlx_pixel_put(data, x, y, NEGRO);
// 			while (y >= (horizonte - dist_wall))
// 				y--;
// 			while (y <= (horizonte + dist_wall))
// 			{
// 				my_mlx_pixel_put(data, x, y, color);
// 				y++;
// 			}
// 		}
// 		y++;
// 	}
// 	x++;
// }

void draw_colum(t_data *data, int color, int dist_wall, int x_current, int y_current)
{
	static int x = 0;
	int y;
	int horizonte;
	int	texture_color;
	int	x_text;
	int	y_text;

	horizonte = data->mlx->height_window / 2;
	y = 0;
	if (x == data->mlx->width_window )
		x = 0;

	dist_wall = dist_wall;

	int start = horizonte - dist_wall;
	int end = horizonte + dist_wall;
	(void)color;
	while (y <= data->mlx->height_window)
	{
		if (y >= start && y <= end)
		{
            y_text = (y - start) * 500 / (end - start);
			x_text = (int)((float)x_current / (float)data->mlx->width_window * 500) % 500;
			texture_color = ft_texture_color(x_current, y_current, data, y_text, x_text);
			my_mlx_pixel_put(data, x, y, texture_color);
		}
		y++;
	}
	x++;
}


