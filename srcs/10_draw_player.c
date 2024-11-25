/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   10_draw_player.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izperez <izperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 20:14:06 by izperez           #+#    #+#             */
/*   Updated: 2024/11/25 20:17:55 by izperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

//rojo
#define PLAYER_COLOR 0xFF0000 

void	draw_pixel(void *mlx, void *win, int x, int y, int color)
{
	mlx_pixel_put(mlx, win, x, y, color);
}

