/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   05_parse_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 21:35:42 by adlopez-          #+#    #+#             */
/*   Updated: 2024/11/16 12:53:04 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

// aqui van el top bot del mapa

// checka que al encontrar un punto lo q siga sean xpm

int	ft_xpm_check(char *chain, int idx)
{
	int	idy;

	idy = idx;
	if (chain[idy] && chain[idy + 1] && chain[idy + 2] && chain[idy + 3])
	{
		if (chain[idy] == '.' && chain[idy + 1] == 'x' && chain[idy + 2] == 'p' && \
			chain[idy + 3] == 'm')
			return (1);
	}
	return (0);
}

// comprueba la cadena de entrada q sea .cub

int	ft_cub(char *argv)
{
	int	idx;

	idx = 0;
	if (!argv)
		return (0);
	while (argv[idx])
	{
		if (argv[idx] == '.')
		{
			if (argv[idx + 1] == 'c' && argv[idx + 2] == 'u' && \
				argv[idx + 3] == 'b')
				return (1);
		}
		idx++;
	}
	return (0);
}

int	ft_xpm_format(char **map, int noid, int soid, int weid, int eaid)
{
	int	idx;

	idx = 0;
	while (map[noid][idx] != '.')
		idx++;
	if (ft_xpm_check(map[noid], idx) == 0)
		return (0);		
	idx = 0;
	while (map[soid][idx] != '.')
		idx++;
	if (ft_xpm_check(map[soid], idx) == 0)
		return (0);
	idx = 0;
	while (map[weid][idx] != '.')
		idx++;
	if (ft_xpm_check(map[weid], idx) == 0)
		return (0);
	idx = 0;
	while (map[eaid][idx] != '.')
		idx++;
	if (ft_xpm_check(map[eaid], idx) == 0)
		return (0);
	return (1);
}

int	ft_start_ids(char **map, int *no, int *so, int *we, int *ea)
{
	int	idx;

	idx = 0;
	while (map[idx])
	{
		if (strncmp(map[idx], "NO ", 3) == 0)
			(*no) = idx;
		if (strncmp(map[idx], "SO ", 3) == 0)
			(*so) = idx;
		if (strncmp(map[idx], "WE ", 3) == 0)
			(*we) = idx;
		if (strncmp(map[idx], "EA ", 3) == 0)
			(*ea) = idx;
		idx++;
	}
	return (1);
}

char	*ft_string_streatment(char *str)
{
	char	*newstr;
	size_t	idx;
	int		idy;

	idx = 0;
	idy = 0;
	if (!str)
		return (NULL);
	newstr = malloc(sizeof(strlen(str)) + 4092);
	while (str[idx])
	{
		if ((str[idx] == ' ' && str[idx + 1] && str[idx + 1] == ' ') || str[idx] == '\t')
		{
			idx++;
			continue;
		}
		newstr[idy++] = str[idx++];
	}
	newstr[idy] = '\0';
	return (newstr);
}


// ACTUALMENTE EN BUCLE !!