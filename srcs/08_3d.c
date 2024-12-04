/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   08_3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izperez <izperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 13:46:56 by izperez           #+#    #+#             */
/*   Updated: 2024/12/04 14:27:54 by izperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

//1. Coger el horizonte y pintar mitad arriba y mitad abajo con las color techo y suelo
//2. Me llega la distancia y el color de lo que voy a pintar. Depende de que parte de la pared pintar de colores
//3. Identificar en que columna estoy pintando. Por cada rayo pintar en una columna
void	ft_horizonte(int dist_ray, int color, t_data *data)
{
	int	colum_x;
	int	colum_y;
	int	horizonte;

	(void)dist_ray;
	(void)color;

	horizonte = data->mlx->height_window / 2;
	colum_y = 0;
	while (colum_y <= data->mlx->height_window)
	{
		colum_x = 0;
		while (colum_x <= data->mlx->width_window)
		{
			if (colum_x <= horizonte)
				mlx_pixel_put(data->mlx->mlx, data->mlx->win, colum_y, colum_x, VERDE);
			else
				mlx_pixel_put(data->mlx->mlx, data->mlx->win, colum_y, colum_x, MORADO);
			colum_x++;
		}
		colum_y++;
	}
}



