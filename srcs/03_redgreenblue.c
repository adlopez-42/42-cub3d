/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   03_redgreenblue.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adlopez- <adlopez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 13:29:15 by adlopez-          #+#    #+#             */
/*   Updated: 2024/11/13 23:47:05 by adlopez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

// dividido en varias aqui busco donde esta cada dato de suelo/cielo y hago
// las comprobaciones de correcto RGB (0-255, 0-255, 0-255).

// aqui uso la treattment tmbn pero libero en la checksingle

int	ft_rgb_check(char **map)
{
	int	floor_pos;
	int	ciel_pos;

	floor_pos = ft_floor_pos(map);
	ciel_pos = ft_cieling_pos(map);
	if (ft_rgb_check_single(ft_string_streatment(map[floor_pos])) == 0)
		return (0);
    if (ft_rgb_check_single(ft_string_streatment(map[ciel_pos])) == 0)
		return (0);
	return (1);
}

int	ft_rgb_check_single(char *map)
{
	int	red;
	int	green;
	int	blue;

	red = ft_rgb_data(map, 0);
	green = ft_rgb_data(map, 1);
	blue = ft_rgb_data(map, 2);
	if (red > 255 || red < 0 || blue < 0)
	{
		free(map);
		return (0);
	}
	if (green > 255 || green < 0 || blue > 255)
	{
		free(map);
		return (0);
	}
	free(map);
	return (1);
}

int	ft_rgb_data(char *map, int flag)
{
	int 	idx;
	int		idy;
	char	str[42];

	idx = 1;
	idy = 0;
	while (map[idx] != ',' && flag == 0)
		str[idy++] = map[idx++];
	if (flag == 0)
		return (atoi(str));
	while (map[idx] != ',' && flag == 1)
		str[idy++] = map[idx++];
	if (flag == 1)
		return (atoi(str));
	while (map[idx] != '\0')
		str[idy++] = map[idx++];
	return (atoi(str));
}

int	ft_floor_pos(char **map)
{
	int	idx;

	idx = 0;
	while (map[idx])
	{
		if (strncmp(map[idx], "F ", 2) == 0)
			return (idx);
		idx++;
	}
	return (0);
}

int	ft_cieling_pos(char **map)
{
	int	idx;

	idx = 0;
	while (map[idx])
	{
		if (strncmp(map[idx], "C ", 2) == 0)
			return (idx);
		idx++;
	}
	return (0);
}
