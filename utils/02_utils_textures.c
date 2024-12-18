/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   02_utiles_textures.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izperez <izperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 12:07:30 by izperez           #+#    #+#             */
/*   Updated: 2024/12/18 12:07:54 by izperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	ft_rgb_pos(char **input, int flag)
{
	int	idx;

	idx = 0;
	if (flag == 0)
	{
		while (input[idx])
		{
			if (ft_strncmp(input[idx], "C", 1) == 0)
				return (idx);
			idx++;
		}
	}
	if (flag == 1)
	{
		while (input[idx])
		{
			if (ft_strncmp(input[idx], "F", 1) == 0)
				return (idx);
			idx++;
		}
	}
	return (0);
}

int	ft_rgbreturn(char *input, int flag)
{
	int		idx;
	int		idy;
	char	str[42];

	idx = 1;
	idy = 0;
	if (flag == 0)
	{
		while (input[idx] != ',')
			str[idy++] = input[idx++];
		str[idy] = '\0';
		return (atoi(str));
	}
	if (flag == 1)
	{
		while (input[idx] != ',')
			idx++;
		idx++;
		while (input[idx] != ',')
			str[idy++] = input[idx++];
		str[idy] = '\0';
		return (atoi(str));
	}
	return (0);
}

int	ft_rgbreturn_2(char *input)
{
	int		idx;
	int		idy;
	char	str[42];

	idx = 0;
	idy = 0;
	while (input[idx] != ',')
		idx++;
	idx++;
	while (input[idx] != ',')
		idx++;
	idx++;
	while (input[idx] && input[idx] != '\0')
		str[idy++] = input[idx++];
	str[idy] = '\0';
	return (atoi(str));
}

int	ft_texture_format(char *texture)
{
	(void)texture;
	return (1);
}

int	ft_repeated_textures(t_checks *checker)
{
	(void)checker;
	return (1);
}
