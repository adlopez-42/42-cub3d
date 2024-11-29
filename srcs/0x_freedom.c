/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   0x_freedom.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izperez <izperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 14:31:51 by adrian            #+#    #+#             */
/*   Updated: 2024/11/29 13:06:49 by izperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	ft_free_split(char **data)
{
	int idx;

	idx = 0;
	while (data[idx])
		free(data[idx++]);
	free(data);
	return ;
}

void	ft_free_checker(t_checks *checker)
{
	free(checker->north_texture);
	free(checker->south_texture);
	free(checker->west_texture);
	free(checker->east_texture);
	ft_free_split(checker->map);
	free(checker);
	return ;
}

void	ft_free_data(t_data *data)
{
	ft_free_split(data->map->grid);
	free(data->map);
	free(data->playerpos);
	free(data->asset->north_texture);
	free(data->asset->south_texture);
	free(data->asset->west_texture);
	free(data->asset->east_texture);
	free(data->asset);
	free(data->textures);
	free(data->mlx);
	return ;
}
