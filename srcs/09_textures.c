/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   09_textures.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izperez <izperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 12:03:09 by izperez           #+#    #+#             */
/*   Updated: 2024/12/19 13:32:01 by izperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	ft_texture_color(t_data *data)
{
	int	color;
	int	x;
	int	y;
	int	x_text;
	int	y_text;

	color = BLANCO;
	x = data->ray->x_current;
	y = data->ray->y_current;
	x_text = data->ray->x_text;
	y_text = data->ray->y_text;
	if ((x % TILE_SIZE == 0 || (x + 1) % TILE_SIZE == 0) \
		&& (y % TILE_SIZE == 0 || (y + 1) % TILE_SIZE == 0))
		color = NEGRO;
	else if ((y % TILE_SIZE) == 0)
		color = ft_textures_colors(x_text, y_text, data->e_texture);
	else if ((x % TILE_SIZE) == 0)
		color = ft_textures_colors(x_text, y_text, data->s_texture);
	else if (((x + 1) % (TILE_SIZE)) == 0)
		color = ft_textures_colors(x_text, y_text, data->n_texture);
	else if (((y + 1) % (TILE_SIZE)) == 0)
		color = ft_textures_colors(x_text, y_text, data->w_texture);
	else
		color = BLANCO;
	return (color);
}

int	ft_textures_colors(int x_text, int y_text, t_image_info *data)
{
	char	*pixel;
	int		color;

	pixel = data->address + (y_text * data->line_s) \
		+ (x_text * (data->bpp / 8));
	if (data->endian == 0)
		color = *(unsigned int *)pixel;
	else
		color = ((unsigned char)pixel[2] << 16) | \
				((unsigned char)pixel[1] << 8) | \
				((unsigned char)pixel[0]);
	return (color);
}

int	ft_transform_rgb(int red, int green, int blue)
{
	int	rgb;

	rgb = (red << 16) | (green << 8) | blue;
	return (rgb);
}
