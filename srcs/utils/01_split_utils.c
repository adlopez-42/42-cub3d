/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   01_split_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izperez <izperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 23:52:14 by adlopez-          #+#    #+#             */
/*   Updated: 2024/11/16 12:47:54 by izperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	*ft_calloc(size_t count, size_t size)
{
	unsigned char	*temp;
	size_t			x;

	x = 0;
	temp = malloc(count * size);
	if (!temp)
		return (0);
	while (x < (count * size))
		temp[x++] = 0;
	return (temp);
}

size_t  ft_strlen(const char *s)
{
    int len;

    len = 0;
    while (s[len])
        len++;
    return (len);
}