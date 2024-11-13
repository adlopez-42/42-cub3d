/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   04_textures.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adlopez- <adlopez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 13:15:00 by adlopez-          #+#    #+#             */
/*   Updated: 2024/11/14 00:19:03 by adlopez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

// aqui tengo 4 ints con las posiciones en el **map de cada lado de textura
// luego compruebo que terminen en .xpm y al final que todos sean accesibles.

int	ft_textures_check(char **map)
{
	int	no_id;
	int	so_id;
	int	we_id;
	int	ea_id;

	if (ft_start_ids(map, &no_id, &so_id, &we_id, &ea_id) == 0)
	{
		printf("aqui 1\n");
		return (0);
	}
	if (ft_xpm_format(map, no_id, so_id, we_id, ea_id) == 0)
	{
		printf("aqui 2\n");
		return (0);
	}
	if (ft_textures_access(map, no_id, so_id, we_id, ea_id) == 0)
	{
		printf("aqui 3\n");
		return (0);
	}
	return (1);
}

// aqui uso la streatment y libero al final

int	ft_textures_access(char **map, int noid, int soid, int weid, int eaid)
{
	char	*north;
	char	*south;
	char	*east;
	char	*west;

	north = ft_return_path(ft_string_streatment(map[noid]));
	south = ft_return_path(ft_string_streatment(map[soid]));
	west = ft_return_path(ft_string_streatment(map[weid]));
	east = ft_return_path(ft_string_streatment(map[eaid]));
	if (ft_textures_deepcheck(north, south, west, east) == 0)
	{
		ft_free_paths(north, south, east, west);
		return (0);
	}
	ft_free_paths(north, south, east, west);
	return (1);
}

int	ft_textures_deepcheck(char *north, char *south, char *west, char *east)
{
	if ((!strcmp(north, south)) || (!strcmp(north, east)) || (!strcmp(east, west)))
		return (0);
	if ((!strcmp(east, south)) || (!strcmp(south, west)) || (!strcmp(north, west)))
		return (0);
	if (access(north, O_RDONLY) == -1)
		return (0);
	if (access(south, O_RDONLY) == -1)
		return (0);
	if (access(west, O_RDONLY) == -1)
		return (0);
	if (access(east, O_RDONLY) == -1)
		return (0);
	return (1);
}

char	*ft_return_path(char *map)
{
	int		idx;
	int		idy;
	char	*path;

	idx = 0;
	idy = 0;
	path = malloc(sizeof(map) + 4092);
	while (map[idx] && map[idx] != '\0')
	{
		if (map[idx] == 'N' && map[idx + 1] == 'O')
			idx += 2;
		if (map[idx] == 'S' && map[idx + 1] == 'O')
			idx += 2;
		if (map[idx] == 'W' && map[idx + 1] == 'E')
			idx += 2;
		if (map[idx] == 'E' && map[idx + 1] == 'A')
			idx += 2;
		if (map[idx] == ' ')
			idx++;
		path[idy++] = map[idx++];
	}
	path[idy] = '\0';
	free(map);
	return (path);
}

void	ft_free_paths(char *north, char *south, char *west, char *east)
{
	if (north)
		free(north);
	if (south)
		free(south);
	if (west)
		free(west);
	if (east)
		free(east);
}
