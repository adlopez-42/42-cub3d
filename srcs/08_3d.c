/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   08_3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izperez <izperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 13:46:56 by izperez           #+#    #+#             */
/*   Updated: 2024/12/10 12:54:49 by izperez          ###   ########.fr       */
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
				my_mlx_pixel_put(data, x, y, GRIS);
			else
				my_mlx_pixel_put(data, x, y, BLANCO);
			x++;
		}
		y++;
	}
}

//Esta función pinta las columnas en función de los rayos y su distancia.
/* void	draw_colum(t_data *data, int color, int dist_wall)
{
	static int	x = 0;
	int			y;
	int			horizonte;

	dist_wall = dist_wall * 10;
	horizonte = data->mlx->height_window / 2;
	y = 0;
	if (x == data->mlx->width_window)
		x = 0;

	while (y <= data->mlx->height_window)
	{
		if (horizonte == y)
		{
			//my_mlx_pixel_put(data, x, y, NEGRO);
			while (y >= (horizonte - dist_wall))
				y--;
			while (y <= (horizonte + dist_wall))
			{
				my_mlx_pixel_put(data, x, y, color);
				y++;
			}
		}
		y++;
	}
	x++;
} */

void draw_colum(t_data *data, int color, int dist_wall)
{
	static int x = 0;
	int y;
	int horizonte;

	horizonte = data->mlx->height_window / 2;
	y = 0;
	if (x == data->mlx->width_window)
		x = 0;

	dist_wall = dist_wall;

	int start = horizonte - dist_wall;
	int end = horizonte + dist_wall;

	while (y <= data->mlx->height_window)
	{
		if (y >= start && y <= end)
		{
			my_mlx_pixel_put(data, x, y, color);
		}
		else
		{
			if (y < horizonte)
				my_mlx_pixel_put(data, x, y, GRIS); // Color del cielo
			else
				my_mlx_pixel_put(data, x, y, BLANCO); // Color del suelo
		}
		y++;
	}
	x++;
}


//1. Perpendicular: dir y es a 90º de esa direccion
//2. 



