/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   01_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 13:05:35 by adlopez-          #+#    #+#             */
/*   Updated: 2024/11/15 17:53:59 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

// en esta funcion abro y leo el mapa y lo cargo en splitted_map
// en caso de cualquier error pasa por free_split q la libera y
// no uso mas reservas de memoria en el parse que no m apetece
// hacerlo 150 veces :D


// nos piden que mostremos errores específicos y he decidido q
// menos algunos que tenga por dentro aún mas específicos de retorno
// de funciones o lo que sea pos saldran 2 seguidos supongo.

int	ft_parse_map(int fd)
{
	char	buffer[4092];
	char	**splitted_map;

	if (!read(fd, buffer, sizeof(buffer)))
		return (ft_interror(1));
	splitted_map = ft_split(buffer, '\n');
	if (ft_map_check(splitted_map) == 0)
	{
		ft_free_splt(splitted_map);
		return (ft_interror(4));
	}
	if (ft_textures_check(splitted_map) == 0)
	{
		ft_free_splt(splitted_map);
		return (ft_interror(2));
	}
	if (ft_rgb_check(splitted_map) == 0)
	{
		ft_free_splt(splitted_map);
		return (ft_interror(3));
	}
	return (1);
}
