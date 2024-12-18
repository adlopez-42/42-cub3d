/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izperez <izperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 16:23:27 by adrian            #+#    #+#             */
/*   Updated: 2024/12/18 12:46:10 by izperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	count_words(const char *str, char c)
{
	int	i;
	int	trigger;

	i = 0;
	trigger = 0;
	while (*str)
	{
		if (*str != c && trigger == 0)
		{
			trigger = 1;
			i++;
		}
		else if (*str == c)
			trigger = 0;
		str++;
	}
	return (i);
}

char	*word_dup(const char *str, int start, int finish)
{
	char	*word;
	int		i;

	i = 0;
	word = malloc((finish - start + 1) * sizeof(char));
	while (start < finish)
		word[i++] = str[start++];
	word[i] = '\0';
	return (word);
}

int	ft_maptop(char **input)
{
	int	top;

	top = 0;
	while (input[top])
	{
		if (ft_mapline(input[top]) == 1)
			return (top);
		top++;
	}
	return (-1);
}

int	ft_mapbot(char **input, int start)
{
	int	s;

	s = start;
	while (ft_mapline(input[s]) == 1)
		s++;
	return (s);
}

int	ft_mapline(char *line)
{
	int	id;

	id = 0;
	if (!line || line[0] == '\0')
		return (0);
	while (line[id])
	{
		if (line[id] == '0' || line[id] == '1' || line[id] == ' ' \
			|| line[id] == '\t' || line[id] == 'N' || line[id] == 'S' \
			|| line[id] == 'E' || line[id] == 'W' || line[id] == '\n')
			id++;
		else
			break ;
	}
	if (id == ft_strlen(line))
		return (1);
	return (0);
}
