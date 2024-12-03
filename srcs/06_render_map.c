/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   06_render_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izperez <izperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 10:49:19 by izperez           #+#    #+#             */
/*   Updated: 2024/12/02 14:04:12 by izperez          ###   ########.fr       */
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
	draw_pito(data, data->playerpos->dir, 10);
	mlx_put_image_to_window(data->mlx->mlx, data->mlx->win, data->mlx->img, 0, 0);
}

void	draw_line(t_data *data, float x, float y, float angle, int length)
{
	float x_end;
	float y_end;
	float step;
	int i;

	x_end = x + length * cos(angle);
	y_end = y + length * sin(angle);
	step = 1.0 / length; // Ajusta según tu resolución deseada

	printf("x_end[%f] y y_end[%f]\n", x_end, y_end);
	for (i = 0; i <= length; i++)
	{
		float t = i * step; // Proporción del camino recorrido
		float x_current = x + t * (x_end - x);
		float y_current = y + t * (y_end - y);
		printf("x_current[%f] y y_current[%f]\n", x_current, y_current);
		my_mlx_pixel_put(data, (int)x_current, (int)y_current, ROJO); // Color blanco
	}
}


void	draw_pito(t_data *data, float desf, int lenght)
{
	float pos[2];
	float angle;
	(void)desf;
	(void)lenght;
		
	pos[0] = data->playerpos->x;
	pos[1] = data->playerpos->y;
	angle = data->playerpos->dir;

	printf("pos_x[%f] y pos_y[%f]\n", pos[0], pos[1]);
	draw_line(data, pos[0], pos[1], angle, 10);
	

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