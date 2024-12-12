/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   06_render_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izperez <izperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 10:49:19 by izperez           #+#    #+#             */
/*   Updated: 2024/12/11 12:50:21 by izperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

//Places a pixel
void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;
	
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
		color = GRIS;
	else if (c == '0')
		color = BLANCO;
	else if (c == 'N' || c == 'S' || c == 'E' || c == 'O')
		color = BLANCO;
	else
		color = NEGRO;
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
		y++;
	}
}

//Calculamos el conon de visión del player. Ej: El player empieza en el N. Su cono de visión por omisión son 90º derech.
//Tenemos que ajustarlo para que el player entero tenga un campo de visión igual no solo un lado del player.
void	calculate_fov(t_data *data)
{
	float	start_des;
	float	end_des;
	int		i = 0;

	start_des = 35 * (PI / 180.0) + (PI / 2);
	end_des = -35 * (PI / 180.0) + (PI / 2);

	float	j = (start_des - end_des) / data->mlx->width_window;
	while (start_des >= end_des)
	{
		prepare_rays(data, start_des, 3000);
		//start_des -= 0.0003;
		start_des -= j;
		i++;
	}
	mlx_put_image_to_window(data->mlx->mlx, data->mlx->win, data->mlx->img, 0, 0);
	// printf("%i\n", i);
	// printf("el width es %d\n", data->mlx->width_window);
}

//Calculamos la distancia de cada rayo y hacemos la matemática para que el rayo mas largo lo pintemos con un valor mas pequeño y viceversa
//Esto es para dar sensación de cercanía o lejanía
void draw_line(t_data *data, float x_start, float y_start, float angle, float steps)
{
	float x_end = x_start + steps * cos(angle);
	float y_end = y_start + steps * sin(angle);
	int	color = 0;
	int	i = 0;
	float t;
	int x_current;
	int y_current;
	//int	dist_wall = 0;

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
	//dist_wall = (ft_distancia(x_current, y_current, data->playerpos) / cos(90 - angle));
	draw_colum(data, color, ((TILE_SIZE * data->mlx->height_window) / (ft_distancia(x_current, y_current, data->playerpos)) / cos(angle * (PI / 360))), x_current, y_current);
}

int	ft_texture_color(int x, int y, t_data *data, int x_text, int y_text)
{
	int	color;

	color = 0;
	if (((((x % TILE_SIZE) == 0) || (( x + 1 ) % TILE_SIZE) == 0)) && ((((y % TILE_SIZE) == 0) || (( y + 1 ) % TILE_SIZE) == 0)))
		color = NEGRO;
	else if ((y % TILE_SIZE) == 0)
		color = ft_textures_colors(x_text, y_text, data->e_texture, data);
	else if ((x % TILE_SIZE) == 0)
		color = ft_textures_colors(x_text, y_text, data->s_texture, data);
	else if (((x + 1) % (TILE_SIZE)) == 0)
		color = ft_textures_colors(x_text, y_text, data->n_texture, data);
	else if (((y + 1) % (TILE_SIZE)) == 0)
		color = ft_textures_colors(x_text, y_text, data->w_texture, data);
	else
		color = BLANCO;
	return (color);
}

int	ft_textures_colors(int x, int y, t_image_info *info, t_data *data)
{
    //int texture_x;
    //int texture_y;
    int color;
	(void)data;
    //int len_x = 500;   // Ancho de la textura
    //int len_y = 500;  // Alto de la textura

    // Escalar las coordenadas (x, y) para que estén dentro de los límites de la textura
    //texture_x = (int)((double)x / (double)data->mlx->width_window * len_x) % len_x;
    //texture_y = (int)((double)y / (double)data->mlx->height_window * len_y) % len_y;

    // Obtener los datos de la imagen
    int *pixels = (int *)mlx_get_data_addr(info->image_charge, &info->bpp, &info->line_s, &info->endian);

    // Acceder al color del píxel en las coordenadas calculadas
    color = pixels[y * x];
    
    return color;
}

int	ft_distancia(int x, int y, t_pos *player)
{
	int	num;
	int	num2;

	num = (x - (player->x * TILE_SIZE)) * (x - (player->x * TILE_SIZE));
	num2 = (y - (player->y * TILE_SIZE)) * (y - (player->y * TILE_SIZE));
	return (sqrt(num + num2));
}

//Preparamos los rayos para que estes acorde con las dimensiones de la ventana y no solo del mapa.
void	prepare_rays(t_data *data, float desf, int lenght)
{
	float pos_x;
	float pos_y;
	float angle;
		
	pos_x = data->playerpos->x * TILE_SIZE;
	pos_y = data->playerpos->y * TILE_SIZE;
	angle = data->playerpos->dir + desf;

	//printf("pos_x[%f] y pos_y[%f] angle[%f]\n", pos_x, pos_y, angle);
	draw_line(data, pos_x, pos_y, angle, lenght);
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
			if (sqrt((x - p_y) * (x - p_y) + (y - p_x) * (y - p_x)) <= 10)
			{
				my_mlx_pixel_put(data, x, y, ROJO);
			}
			x++;
		}
		y++;
	}
}


//Nos dice que parte del cuadrado es: Parte superior, inferior, derecha o izquierda.