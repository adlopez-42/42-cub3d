/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   06_render_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izperez <izperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 10:49:19 by izperez           #+#    #+#             */
/*   Updated: 2024/12/03 13:58:41 by izperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

/* 
    1. Pintar el mapa con los cuadrados
    2. Pintar como un punto el jugador
    3. Pintar el pitilin segun la direccion que mira el jugador
    4. Tiene que rotar
    5. FOV
 */
//Places a pixel
void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	/* if (data->mlx->img_addr == NULL)
		printf("tamo null img addr\n");

	if (data->mlx->size_line)
		printf("tamo null size line\n");
	
	if (data->mlx->bit_per_pixel)
		printf("tamo null bpp\n"); */

	// printf("Image address: %p\n", data->mlx->img_addr);
	// printf("Size line address: %p\n", &data->mlx->size_line);
	// printf("Bit per pixel address: %p\n", &data->mlx->bit_per_pixel);
	
	if ((x < 0 || x > data->mlx->width_window) \
	|| (y < 0 || y > data->mlx->height_window))
		return ;
	dst = data->mlx->img_addr + (y * data->mlx->size_line) \
	+ (x * (data->mlx->bit_per_pixel / 8));
	*(unsigned int *) dst = color;
}

void	draw_square(t_data *data, char c, int d_x, int d_y)
{
	int	x;
	int	y;
	int color;


	if (c == '1')
		color = GRIS; //gris paredes
	else if (c == '0')
		color = BLANCO; //blanco para el suelo
	else if (c == 'N' || c == 'S' || c == 'E' || c == 'O')
		color = BLANCO; //rojo jugador
	else
		color = NEGRO; //negro
	y = 0;
	
	while(y < TILE_SIZE)
	{
		x = 0;
		while(x < TILE_SIZE)
		{
			if (x == 0 || x == TILE_SIZE - 1 || y == 0 || y == TILE_SIZE - 1)
				my_mlx_pixel_put(data, x + d_x * TILE_SIZE, y + d_y * TILE_SIZE, NEGRO);
			else
				my_mlx_pixel_put(data, x + d_x * TILE_SIZE, y + d_y * TILE_SIZE, color);
			x++;
		}
		//printf("\n");
		y++;
	}
	//printf("%i %i\n", x, y);
}

void	draw_grid(t_data *data)
{
	int	x;
	int	y;

	y = 0;
	while(y < data->map->height)
	{
		x = 0;
		while(x < data->map->width)
		{
			draw_square(data, data->map->grid[y][x], x, y);
			x++;
		}
		y++;
	}
	draw_player(data);
	float	start_des;
	float	end_des;
	int		i = 0;
	start_des = 30 * (PI / 180.0) + (PI / 2);
	end_des = -30 * (PI / 180.0) + (PI / 2);
	//este bucle se tiene que repetir por todos los pixeles horizontales haya.
	while (start_des >= end_des)
	{
		draw_pito(data, start_des, 3000);
		start_des -= 0.1;
		i++;
	}
	printf("Cuantas veces entro[%d]\n", i); //i == pixeles horizontales de la ventana
	mlx_put_image_to_window(data->mlx->mlx, data->mlx->win, data->mlx->img, 0, 0);
}


void draw_line(t_data *data, float x_start, float y_start, float angle, float distance, int color)
{
	// Calcular las coordenadas del final de la línea
	float x_end = x_start + distance * cos(angle);
	float y_end = y_start + distance * sin(angle);
	int	new_color = color;

	// Dibuja la línea pixel a pixel
	int steps = (int)distance; // Número de pasos para recorrer la línea
	// float x = x_start;
	// float y = y_start;

	int	i = 0;
	while (i++ < steps)
	{
		// Calculamos la posición actual de la línea usando la interpolación lineal
		float t = (float)i / (float)steps;  // Proporción de la distancia recorrida
		int x_current = (int)(x_start + t * (x_end - x_start));
		int y_current = (int)(y_start + t * (y_end - y_start));
		if (data->map->grid[(int)(x_current / TILE_SIZE)][(int)(y_current / TILE_SIZE)] == '1')
			break ;
		else
			my_mlx_pixel_put(data, y_current, x_current, new_color);
	}
	printf("distancia %d\n", i);
	
}


void	draw_pito(t_data *data, float desf, int lenght)
{
	float pos_x;
	float pos_y;
	float angle;
		
	pos_x = data->playerpos->x * TILE_SIZE;
	pos_y = data->playerpos->y * TILE_SIZE;
	angle = data->playerpos->dir + desf;

	//printf("pos_x[%f] y pos_y[%f] angle[%f]\n", pos_x, pos_y, angle);
	draw_line(data, pos_x, pos_y, angle, lenght, ROJO);
	//mlx_put_image_to_window(data->mlx->mlx, data->mlx->win, data->mlx->img, 0, 0);

}

void	draw_player(t_data *data)
{
	int	x;
	int	y;
	int	p_x;
	int	p_y;

	p_x = data->playerpos->x * TILE_SIZE;
	p_y = data->playerpos->y * TILE_SIZE;

	y = 0;

	while (y < data->mlx->height_window)
	{
		x = 0;
		while (x < data->mlx->width_window)
		{
			// Comprueba si (x, y) está dentro de un círculo de 10 píxeles alrededor de (p_y, p_x)
			if (sqrt((x - p_y) * (x - p_y) + (y - p_x) * (y - p_x)) <= 10)
			{
				my_mlx_pixel_put(data, x, y, ROJO);
			}
			x++;
		}
		y++;
	}
}