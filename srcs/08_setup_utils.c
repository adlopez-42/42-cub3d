/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   08_setup_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 12:41:43 by marvin            #+#    #+#             */
/*   Updated: 2024/11/15 12:41:43 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	ft_set_rgbs(t_asset **asset, char **map)
{
	int	*rgb;
	int	f_id;
	int	c_id;
	int	idx;

	idx = 0;
	while (map[idx])
	{
		if (strncmp(map[idx], "F", 1) == 0)
			f_id = idx;
		if (strncmp(map[idx], "C", 1) == 0)
			c_id = idx;
		idx++;
	}
	rgb = ft_set_rgb(map[c_id], 0);
	(*asset)->cieling_rgb = rgb;
	rgb = ft_set_rgb(map[f_id], 1);
	(*asset)->floor_rgb = rgb;
}

int	*ft_set_rgb(char *map, int flag)
{
	int	red;
	int	blue;
	int	green;
	int	*ret;

	ret = malloc(sizeof(int) * 3);
	if (flag == 0)
	{
		red = ft_rgb_data(map, 0);
		green = ft_rgb_data(map, 1);
		blue = ft_rgb_data_2(map);
	}
	else if (flag == 1)
	{
		red = ft_rgb_data(map, 0);
		green = ft_rgb_data(map, 1);
		blue = ft_rgb_data_2(map);
	}
	ret[0] = red;
	ret[1] = green;
	ret[2] = blue;
	return (ret);
}

void	ft_free_splt(char **spt)
{
	int idx;

	idx = 0;
	while (spt[idx])
		free(spt[idx++]);
	free(spt);
}

char	*ft_custstrdup(char *str)
{
	char	*newstr;
	int		idx;

	idx = 0;
	newstr = malloc(sizeof(str) + 42);
	if (!str || str[0] == '\0')
		return (NULL);
	while (str[idx] != '\0')
	{
		newstr[idx] = str[idx];
		idx++;
	}
	newstr[idx] = '\0';
	free(str);
	return (newstr);
}
