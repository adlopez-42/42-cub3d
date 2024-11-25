/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   06_parse_utils_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izperez <izperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 23:50:00 by adlopez-          #+#    #+#             */
/*   Updated: 2024/11/25 13:35:18 by izperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	ft_map_top(char **map)
{
	(void)map;
	return (9);
}

int	ft_map_bot(char **map)
{
	(void)map;
	return (13);
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