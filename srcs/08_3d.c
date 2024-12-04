/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   08_3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izperez <izperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 13:46:56 by izperez           #+#    #+#             */
/*   Updated: 2024/12/04 13:15:23 by izperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

# define WALL_TOP 0
# define WALL_BOTTOM 1
# define WALL_RIGHT 2
# define WALL_LEFT 3

/* void	wall_side(t_data *data, int x, int y, float angle)
{
	(void)data;
	(void)angle;
	if ((TILE_SIZE % x)== 0 && (TILE_SIZE % y) == 0) 
		printf("Ha chocado en una esquina\n");
	else if ((TILE_SIZE % y) == 0)
		printf("Ha chocado en una vertical\n");
	else if ((TILE_SIZE % x) == 0)
		printf("Ha chocado en  una horizontal\n");
	else
		printf("Error no ha entrado nada\n");
	//printf("x[%i] y y[%i]\n", x, y);
	//printf("hondarra_x %f eta hondarra_y %f\n", (TILE_SIZE % x), (TILE_SIZE %))
} */

void	wall_side(t_data *data, int x, int y, float angle)
{
	(void)data;
	(void)angle;
	
	if ((x % TILE_SIZE)== 0 && (y % TILE_SIZE) == 0) 
		printf("Ha chocado en una esquina\n");
	else if ((y % TILE_SIZE) == 0)
		printf("Ha chocado en una vertical derecha\n");
	else if ((x % TILE_SIZE) == 0)
		printf("Ha chocado en  una horizontal abajo\n");
	else if ((x % (TILE_SIZE - 1)) == 0)
		printf("Ha chocado en  una horizontal arriba\n");
	else if ((y % (TILE_SIZE - 1)) == 0)
		printf("Ha chocado en una vertical izquierda\n");
	else
		printf("error\n");
	printf("x[%i] y y[%i]\n", x, y);
	//printf("hondarra_x %d eta hondarra_y %d\n", (x % TILE_SIZE), (y % TILE_SIZE));
}

