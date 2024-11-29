/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   06_render_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izperez <izperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 10:49:19 by izperez           #+#    #+#             */
/*   Updated: 2024/11/29 12:58:15 by izperez          ###   ########.fr       */
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
		color = ROJO; //rojo jugador
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
	printf("%i %i\n", x, y);
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
			//printf("%c", data->map->grid[y][x]);
			draw_square(data, data->map->grid[y][x], x, y);
			x++;
		}
		y++;
	}
}