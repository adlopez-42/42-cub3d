/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adlopez- <adlopez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 12:57:00 by adlopez-          #+#    #+#             */
/*   Updated: 2024/11/13 23:37:56 by adlopez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d.h"

// primero declaramos la big structure hago comprobaciones de input, 
// llamo a la funcion de parse y si esta todo okay llamamos a setup data, llenamos
// las estructuras y empezamos la movida en ft_cub3d, la free data en un futuro
// es pa limpiar TODO.

int main(int argc, char **argv)
{
	//t_data	*data;
	int			fd;

	//data = NULL;
	if (argc == 1 || ft_cub(argv[1]) == 0)
		ft_error(0);
	fd = open(argv[1], O_RDONLY);
	if (ft_parse_map(fd) == 1)
		printf("parse ok!");
		//data = ft_setup_data(argv[1]);
	/*if (data)
	{
		ft_cub3d(data);
		ft_free_data(data);
	}*/
	return (0);
}
