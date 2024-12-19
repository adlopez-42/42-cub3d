/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   04_setup_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izperez <izperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 18:59:07 by adrian            #+#    #+#             */
/*   Updated: 2024/12/19 12:32:09 by izperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

t_map	*ft_clean_map(char **checkermap)
{
	t_map	*newmap;
	int		idx;
	char	**newgrid;
	int		max;
	int		size;

	size = 0;
	max = 0;
	newmap = malloc(sizeof(t_map));
	newgrid = (char **)malloc(sizeof(char *) * 1024);
	idx = 0;
	while (checkermap[idx])
	{
		newgrid[idx] = ft_strdup(checkermap[idx]);
		size = ft_strlen(newgrid[idx]);
		if (size > max)
			max = size;
		idx++;
	}
	newgrid[idx] = NULL;
	newmap->grid = newgrid;
	newmap->height = idx;
	newmap->width = max;
	return (newmap);
}

char	**ft_setup_map(char **input)
{
	int		map_top;
	int		map_bot;
	int		idx;
	char	**newmap;

	idx = 0;
	newmap = (char **)malloc(sizeof(char) * 4092);
	map_top = ft_maptop(input);
	map_bot = ft_mapbot(input, map_top);
	if (map_bot == -1 || map_bot == -1)
		return (NULL);
	while (map_top != map_bot)
		newmap[idx++] = ft_strdup(input[map_top++]);
	newmap[idx] = '\0';
	return (newmap);
}

t_ray	*ft_ray_init(t_ray *ray)
{
	t_ray	*new;

	(void)ray;
	new = malloc(sizeof(t_ray));
	new->color = 0;
	new->x_text = 0;
	new->y_text = 0;
	new->dist_wall = 0;
	new->x_current = 0;
	new->y_current = 0;
	new->angle = 0.0;
	return (new);
}
