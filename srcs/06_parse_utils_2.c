/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   06_parse_utils_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 23:50:00 by adlopez-          #+#    #+#             */
/*   Updated: 2024/11/16 13:02:49 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	ft_map_top(char **map)
{
	int	idx;

	idx = 0;
	while (map[idx])
	{
		if (ft_corr_line(map[idx]) == 1)
			return (idx);
		idx++;
	}
	return (0);
}

int	ft_map_bot(char **map, int start)
{
	int	idx;

	idx = start;
	while (ft_corr_line(map[idx]) != 0)
		idx++;
	return (idx);
}

int	ft_corr_line(char *line)
{
	int	idx;

	idx = 0;
	if (!line)
		return (0);
	while (line[idx])
	{
		if (!(line[idx] == ' ' || line[idx] == '0' || line[idx] == '1' || line[idx] == 'N' \
			|| line[idx] == 'S' || line[idx] == 'W' || line[idx] == 'E' || line[idx] == '\n' || line[idx] == '\0'))
			return (0);
		idx++;
	}
	return (1);
}
