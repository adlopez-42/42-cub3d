/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adlopez- <adlopez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 13:01:02 by adlopez-          #+#    #+#             */
/*   Updated: 2024/11/13 20:12:58 by adlopez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

// ola tengo aqui dos funciones de errores, la void es solo para pintar
// y la de int es para mandarla como retorno de error (0).

void	ft_error(int x)
{
	if (x == 0)
		printf("Error\nInvalid input. usage: './cub3d map.cub'");
	return ;
}

int	ft_interror(int x)
{
	if (x == 0)
		printf("Error\nno such file or directory.\n");
	else if (x == 1)
		printf("Error\nread file error.\n");
	else if (x == 2)
		printf("Error\nBad textures format. usage: NO/SO/WE/EA 'texture dir.xpm'.\n");
	else if (x == 3)
		printf("Error\nInvalid RGB format. usage: F/C '0-255, 0-255, 0-255'.\n");
	else if (x == 4)
		printf("Error\nInvalid map format.\n");
	return (0);
}
