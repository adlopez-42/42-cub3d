/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   07_hooks.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izperez <izperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 12:29:39 by izperez           #+#    #+#             */
/*   Updated: 2024/12/02 13:40:17 by izperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static void	key_press_aux(t_data *data, double move_x, double move_y, int mode)
{
	t_pos		*player;
	float		tmp_x;
	float		tmp_y;
	tmp_x = 0;
	tmp_y = 0;
	player = data->playerpos;
	if (mode == 1)
	{
		tmp_x = player->x - (move_x * 0.1);
		tmp_y = player->y - (move_y * 0.1);
	}
	else
	{
		tmp_x = player->x + (move_x * 0.1);
		tmp_y = player->y + (move_y * 0.1);
	}
	if (data->map->grid[(int)(tmp_x)][(int)(tmp_y)] != '1' && 	data->map->grid[(int)tmp_x][(int)tmp_y] != ' ')
	{
		player->x = tmp_x;
		player->y = tmp_y;
	}
	data->playerpos = player;
	//printf("tmpx[%f] y tmpy[%f]\n", data->playerpos->x, data->playerpos->y);
}

int	ft_hooks( int keycode, t_data *data)
{
	if (keycode == A)
		key_press_aux(data, cos(data->playerpos->dir), sin(data->playerpos->dir), 1);
	else if (keycode == D)
		key_press_aux(data, cos(data->playerpos->dir), sin(data->playerpos->dir), 2);
	else if (keycode == W)
		key_press_aux(data, cos(data->playerpos->dir + PI / 2), sin(data->playerpos->dir + PI / 2), 2);
	else if (keycode == S)
		key_press_aux(data, cos(data->playerpos->dir + PI / 2), sin(data->playerpos->dir + PI / 2), 1);
	else
		printf("tamos en el else\n");
	mlx_clear_window(data->mlx->mlx, data->mlx->win);
	draw_grid(data);
	return (keycode);
}