/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   02_mapcheck.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adlopez- <adlopez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 23:48:17 by adlopez-          #+#    #+#             */
/*   Updated: 2024/11/13 23:57:57 by adlopez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

// aqui voy a buscar donde esta el mapa con la posicion de la linea de mas arriba
// y la de mas abajo y en la funcion siguiente full mapchek es donde le hago
// sus comprobaciones.

int	ft_map_check(char **map)
{
    int     top_id;
    int     bot_id;
    int     idx;
    char    **just_map;

    idx = 0;
    just_map = malloc(sizeof(char **) * 1024);
    top_id = ft_map_top(map);
    bot_id = ft_map_bot(map);
    if (top_id < 6)
    {
        free(just_map);
        return (0);
    }
    while (top_id != bot_id && map[top_id + 1])
        just_map[idx++] = map[top_id++];
    return (ft_full_mapcheck(just_map));
}

int ft_full_mapcheck(char **map)
{
    if (ft_checkspaces(map) == 0)
    {
        free(map);
        return (0);
    }
    if (ft_checkplayer(map) == 0)
    {
        free(map);
        return (0);
    }
    free(map);
    return (1);
}

// me falta por implementar los checks de dentro del mapa primero
// comprobare que mi logica tiene sentido cuando eso los implemento bn

int ft_checkspaces(char **map)
{
    (void)map;
    return (1);
}

int ft_checkplayer(char **map)
{
    (void)map;
    return (1);
}
