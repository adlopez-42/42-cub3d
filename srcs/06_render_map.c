/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   06_render_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izperez <izperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 10:49:19 by izperez           #+#    #+#             */
/*   Updated: 2024/12/10 14:07:50 by izperez          ###   ########.fr       */
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

//Calculamos el conon de visión del player. Ej: El player empieza en el N. Su cono de visión por omisión son 90º derech.
//Tenemos que ajustarlo para que el player entero tenga un campo de visión igual no solo un lado del player.
void	calculate_fov(t_data *data)
{
	/* int	x;
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
	draw_player(data); */
	float	start_des;
	float	end_des;
	int		i = 0;

	//Mirar el desfase que no esta bien calculado
	start_des = 30 * (PI / 180.0) + (PI / 2); //Ajustar bien el desfase
	end_des = -30 * (PI / 180.0) + (PI / 2);

	float step = 0.0003 / 2;
	//este bucle se tiene que repetir por todos los pixeles horizontales haya.
	while (start_des >= end_des)
	{
		prepare_rays(data, start_des, 3000);
		//start_des -= 0.0003;
		start_des -= step;
		i++;
	}
	mlx_put_image_to_window(data->mlx->mlx, data->mlx->win, data->mlx->img, 0, 0);
	
	//printf("Cuantas veces entro[%d]\n", i); //i == pixeles horizontales de la ventana
}


//Calcula la distancia del rayo cuando choca una pared
/* int	calculate_ray_dist(int x_start, int y_start, int x_end, int y_end)
{
	float	dist_ray;

	dist_ray = 0;
	while (sqrt((x_end - y_start) * (x_end - y_end) + (y_end - x_start) * (y_end - x_start)))
	{
		dist_ray++;
	}
	return (dist_ray);
} */




int	perp_player(int x, int y, t_data *data)
{
	float	angle;

	angle = data->playerpos->dir;
	float px = data->playerpos->x * TILE_SIZE;
    float py = data->playerpos->y * TILE_SIZE;

    // Calcular componentes del vector perpendicular
    float perp_dx = -sin(angle);
    float perp_dy = cos(angle);

    // Evaluar si (x, y) pertenece a la línea perpendicular
    float dx = x - px;
    float dy = y - py;

    // Producto cruzado para verificar alineación
    float cross_product = dx * perp_dy - dy * perp_dx;

    // Si el producto cruzado es 0, está en la línea
    return fabs(cross_product) < 1e-6;
}

int calculate_perp_point(t_data *data, float x_start, float y_start, float angle, float steps)
{
	// Calcular las coordenadas del final de la línea
	float x_end = x_start + steps * cos(angle);
	float y_end = y_start + steps * sin(angle);
	//int	color = 0;
	int	i = 0;
	float t;  // Proporción de la distancia recorrida
	int x_current;
	int y_current;
	//int	dist_wall = 0;

	while (i++ < steps)
	{
		t = (float)i / (float)steps;
		x_current = (int)(x_start + t * (x_end - x_start));
		y_current = (int)(y_start + t * (y_end - y_start));
		printf("perp_player: %d\n", perp_player(x_current, y_current, data));
		if (perp_player(x_current, y_current, data) == 0)
		{
			//dist_wall = (int)sqrt((x_current - x_start) * (x_current - x_start) + (y_current - y_start) * (y_current - y_start));
			break ;
		}
	}
	// printf("distancia: %d\n", i);
	printf("x_current[%d] y y_current[%d]\n", x_current, y_current);
	// printf("x_player: %f y_player: %f\n", data->playerpos->x * TILE_SIZE, data->playerpos->y *TILE_SIZE);
	printf("x_start[%f]: y y_start[%f]\n", x_start, y_start);
	return (i);
}





//Calculamos la distancia de cada rayo y hacemos la matemática para que el rayo mas largo lo pintemos con un valor mas pequeño y viceversa
//Esto es para dar sensación de cercanía o lejanía
void draw_line(t_data *data, float x_start, float y_start, float angle, float steps)
{
	// Calcular las coordenadas del final de la línea
	float x_end = x_start + steps * cos(angle);
	float y_end = y_start + steps * sin(angle);
	int	color = 0;
	int	i = 0;
	float t;  // Proporción de la distancia recorrida
	int x_current;
	int y_current;
	int	dist_wall = 0;

	while (i++ < steps)
	{
		t = (float)i / (float)steps;
		x_current = (int)(x_start + t * (x_end - x_start));
		y_current = (int)(y_start + t * (y_end - y_start));
		if (data->map->grid[(int)(x_current / TILE_SIZE)][(int)(y_current / TILE_SIZE)] == '1')
			break;
	}
	dist_wall = calculate_perp_point(data, y_current, x_current, data->playerpos->dir + PI, steps);
	color = wall_side(x_current, y_current);
	draw_colum(data, color, dist_wall);
	//printf("distancia %d\n", dist_wall);
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


//Nos dice que parte del cuadrado es: Parte superior, inferior, derecha o izquierda.
int	wall_side(int x, int y)
{
	int color;

	color = 0;
	if (((((x % TILE_SIZE) == 0) || (( x + 1 ) % TILE_SIZE) == 0)) && ((((y % TILE_SIZE) == 0) || (( y + 1 ) % TILE_SIZE) == 0)))
		color = NEGRO;
	else if ((y % TILE_SIZE) == 0)
		color = ROSA;
	else if ((x % TILE_SIZE) == 0)
		color = ROSA;
	else if (((x + 1) % (TILE_SIZE)) == 0)
		color = AZUL;
	else if (((y + 1) % (TILE_SIZE)) == 0)
		color = MORADO;
	else
		printf("error\n");
	return (color);
}