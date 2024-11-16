/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izperez <izperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 12:57:00 by adlopez-          #+#    #+#             */
/*   Updated: 2024/11/16 13:16:34 by izperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"
# include <string.h>

// primero declaramos la big structure hago comprobaciones de input, 
// llamo a la funcion de parse y si esta todo okay llamamos a setup data, llenamos
// las estructuras y empezamos la movida en ft_cub3d, la free data en un futuro
// es pa limpiar TODO.

int		ft_close(int keycode, t_data *data)
{
	(void) data;
	if (keycode == ESC)
	{
		mlx_destroy_window(data->mlx.mlx_ptr, data->mlx.win_ptr);
	}
	return (keycode);
}

int main(int argc, char **argv)
{
	 t_data			data;
	 int			fd;
	bzero(&data, (sizeof(t_data)));
	//data = NULL;
	if (argc == 1 || ft_cub(argv[1]) == 0)
		ft_error(0);
	fd = open(argv[1], O_RDONLY);
	if (ft_parse_map(fd) == 1)
	{
		printf("parse ok!");
		//devuelve el mapa ok
		
		 data.mlx.mlx_ptr = mlx_init();
		data.mlx.win_ptr = mlx_new_window(data.mlx.mlx_ptr, 1920, 1080, "Cub3d no payo");
		mlx_hook(data.mlx.win_ptr, 2, 1L<<0, ft_close, &data);
		mlx_loop(data.mlx.mlx_ptr);
		/* NO assets/armenistan.xpm
		SO assets/pakistan.xpm
		WE assets/turkmenistan.xpm
		EA assets/uzbekistan.xpm */
		//Devuelveme en NO la textura y asi sucesivamente en un char*
		
		/* estructura con:
		char **map //por favor necesitamos el mapa quitandole los saltos de linea y cerrandolos en vez de \n que sea \0 gracias; 
		char *texture = una por cada textura graxias;
		el rgb tambien a poder ser que nos vega en un array de 3 int(pista usa atoi); */
		
	}
		/* yo soy izaro y tengo que hacer que se levanten los muros y simular el 3d 
		para ello necesito
		cargar texturas en la mlx
		cargar una imagen nueva, pintar la imgen del juego que se va a ver
		calcular hacia donde esta mirando el jugador N S E W (la primera vez segun entras)
		
		ESTO EN BUCLE
		--- la posicion del player, x y
		camara, seno coseno y pos jugador.
		Calcular los rayos ----
		//data = ft_setup_data(argv[1]);
	if (data)
	{
		ft_cub3d(data);
		ft_free_data(data);
	}*/
	return (0);
}
