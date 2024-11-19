/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   02_mapcheck.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 23:48:17 by adlopez-          #+#    #+#             */
/*   Updated: 2024/11/18 18:01:06 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	ft_map_check(char **map)
{
    int     top_id;
    int     bot_id;
    int     idx;
    char    **just_map;

    idx = 0;
    just_map = malloc(sizeof(char **) * 1024);
    top_id = ft_map_top(map);
    bot_id = ft_map_bot(map, top_id);
    if (top_id < 6)
    {
        free(just_map);
        return (0);
    }
    top_id -= 1;
    while (top_id != bot_id + 1)
        just_map[idx++] = map[top_id++];
    just_map[idx] = NULL;
    return (ft_full_mapcheck(just_map));
}

int ft_full_mapcheck(char **map)
{
    if (ft_player_access(map) != 1)
    {
        free(map);
        return (0);   
    }
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

int ft_player_access(char **map)
{
    int idx;
    int idy;
    int players;
    
    idx = 0;
    idy = 0;
    players = 0;
    while (map[idx])
    {
        while (map[idx][idy])
        {
            if (map[idx][idy] == 'N' || map[idx][idy] == 'E' || map[idx][idy] == 'W' \
                || map[idx][idy] == 'S')
            {    
                players++;
                if (map[idx][idy + 1] == ' ' || map[idx + 1][idy] == ' ' \
                    || map[idx][idy - 1] == ' ' || map[idx - 1][idy] == ' ')
                    return (0);
            }
            idy++;
        }
        idy = 0;
        idx++;
    }
    return (players);
}

int ft_checkspaces(char **map)
{
    int idx;
    int idy;
    
    idx = 0;
    idy = 0;
    while (map[idx])
    {
        while (map[idx][idy])
        {
            if (map[idx][idy] == ' ')
            {
                if (map[idx][idy + 1] == '0' || map[idx][idy - 1] == '0' \
                    || map[idx + 1][idy] == '0' || map[idx - 1][idy] == '0')
                    return (0);
            }
            idy++;
        }
        idy = 0;
        idx++;
    }
    return (1);
}

int ft_checkplayer(char **map)
{
    (void)map;
    return (1);
}
