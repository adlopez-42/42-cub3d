/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izperez <izperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 23:47:28 by adlopez-          #+#    #+#             */
/*   Updated: 2024/11/16 12:47:28 by izperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static int	ft_wordcount(const char *str, char c)
{
	int	count;
	int	x;

	count = 0;
	x = 0;
	while (*str)
	{
		if (*str != c && x == 0)
		{
			x = 1;
			count++;
		}
		if (*str == c)
			x = 0;
		str++;
	}
	return (count);
}

static char	*ft_splitwords(const char *str, int start, int end)
{
	char	*word;
	int		x;

	x = 0;
	word = malloc((end - start + 1) * sizeof(char));
	if (!word)
		return (NULL);
	while (start < end)
	{
		word[x] = str[start];
		x++;
		start++;
	}
	word[x] = 0;
	return (word);
}

static void	*ft_free(char **strs, int count)
{
	int	x;

	x = 0;
	while (x < count)
	{
		free(strs[x]);
		x++;
	}
	free(strs);
	return (NULL);
}

static void	ft_iniciovar(size_t *x, int *y, int *word)
{
	*x = 0;
	*y = 0;
	*word = -1;
}

char	**ft_split(const char *s, char c)
{
	char	**split;
	size_t	x;
	int		y;
	int		word;

	ft_iniciovar(&x, &y, &word);
	split = ft_calloc((ft_wordcount(s, c) + 1), sizeof(char *));
	if (!split)
		return (NULL);
	while (x <= ft_strlen(s))
	{
		if (s[x] != c && word < 0)
			word = x;
		else if ((s[x] == c || x == ft_strlen(s))
			&& word >= 0)
		{
			split[y] = ft_splitwords(s, word, x);
			if (!split[y])
				return (ft_free(split, y));
			word = -1;
			y++;
		}
		x++;
	}
	return (split);
}
