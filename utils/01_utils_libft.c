/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   01_utils_libft.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izperez <izperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 12:06:09 by izperez           #+#    #+#             */
/*   Updated: 2024/12/18 12:46:49 by izperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

char	**ft_split(char const *s, char c)
{
	int		i;
	int		j;
	int		index;
	char	**split;

	split = malloc((count_words(s, c) + 1) * sizeof(char *));
	if (!s || !split)
		return (0);
	i = 0;
	j = 0;
	index = -1;
	while (i <= ft_strlen(s))
	{
		if (s[i] != c && index < 0)
			index = i;
		else if ((s[i] == c || i == ft_strlen(s)) && index >= 0)
		{
			split[j++] = word_dup(s, index, i);
			index = -1;
		}
		i++;
	}
	split[j] = 0;
	return (split);
}

int	ft_strlen(const char *s)
{
	int	idx;

	idx = 0;
	while (s[idx])
		idx++;
	return (idx);
}

char	*ft_strdup(char *str)
{
	char	*newstr;
	int		idx;

	idx = 0;
	if (!str)
		return (NULL);
	newstr = (char *)malloc(sizeof(char *) * 4092);
	while (str[idx])
	{
		if (str[idx] == '\n' || str[idx] == '\0')
			break ;
		newstr[idx] = str[idx];
		idx++;
	}
	newstr[idx] = '\0';
	return (newstr);
}

int	ft_strncmp(const char *str, const char *str2, size_t c)
{
	size_t			i;
	unsigned int	diff;

	diff = 0;
	i = 0;
	while ((str[i] != '\0') && (str2[i] != '\0')
		&& (diff == 0) && (i < c))
	{
		diff = (unsigned char)str[i] - (unsigned char)str2[i];
		i++;
	}
	if ((diff == 0) && (i < c))
		diff = (unsigned char)str[i] - (unsigned char)str2[i];
	return (diff);
}

float	ft_posdir(char **map)
{
	int		idx;
	int		idy;
	float	res;

	idx = 0;
	idy = 0;
	while (map[idx])
	{
		while (map[idx][idy])
		{
			if (map[idx][idy] == 'N')
				res = PI / 2;
			if (map[idx][idy] == 'S')
				res = 3 * (PI / 2);
			if (map[idx][idy] == 'W')
				res = PI;
			if (map[idx][idy] == 'E')
				res = 2 * PI;
			idy++;
		}
		idy = 0;
		idx++;
	}
	return (res);
}
