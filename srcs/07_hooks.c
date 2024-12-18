/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   07_hooks.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izperez <izperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 12:29:39 by izperez           #+#    #+#             */
/*   Updated: 2024/12/18 12:43:19 by izperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static void	key_press_aux(t_data *data, double move_x, double move_y, int mode)
{
	t_pos	*player;
	float	tmp_x;
	float	tmp_y;

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
	if (data->map->grid[(int)(tmp_x)][(int)(tmp_y)] != '1' && \
	data->map->grid[(int)tmp_x][(int)tmp_y] != ' ')
	{
		player->x = tmp_x;
		player->y = tmp_y;
	}
	data->playerpos = player;
}

static void	ft_hooks_utils(int keycode, t_data *data)
{
	double	move_x;
	double	move_y;

	if (keycode == D)
	{
		move_x = cos(data->playerpos->dir);
		move_y = sin(data->playerpos->dir);
		key_press_aux(data, move_x, move_y, 2);
	}
	else if (keycode == A)
	{
		move_x = cos(data->playerpos->dir);
		move_y = sin(data->playerpos->dir);
		key_press_aux(data, move_x, move_y, 1);
	}
}

int	ft_hooks(int keycode, t_data *data)
{
	double	move_x;
	double	move_y;

	if (keycode == S)
	{
		move_x = cos(data->playerpos->dir + PI / 2);
		move_y = sin(data->playerpos->dir + PI / 2);
		key_press_aux(data, move_x, move_y, 1);
	}
	else if (keycode == W)
	{
		move_x = cos(data->playerpos->dir - PI / 2);
		move_y = sin(data->playerpos->dir - PI / 2);
		key_press_aux(data, move_x, move_y, 1);
	}
	else if (keycode == D || keycode == A)
		ft_hooks_utils(keycode, data);
	else
		ft_rotation(keycode, data);
	return (keycode);
}

int	ft_rotation(int keycode, t_data *data)
{
	float	angle;

	angle = data->playerpos->dir;
	if (keycode == RIGHT)
		angle -= 0.015;
	else if (keycode == LEFT)
		angle += 0.015;
	data->playerpos->dir = angle;
	return (keycode);
}
