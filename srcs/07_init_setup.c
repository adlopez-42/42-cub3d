/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   07_init_setup.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 18:55:15 by marvin            #+#    #+#             */
/*   Updated: 2024/11/14 18:55:15 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

t_data	ft_setup_data(int fd)
{
	t_data	voidata;
	char	buff[4092];
	char	**spl_argv;

	read(fd, buff, 4092);
	spl_argv = ft_split(buff, '\n');
	voidata.map = ft_setup_map(spl_argv);
	voidata.mlx.mlx_ptr = ft_mlx_init();
	voidata.asset = ft_setup_asset(spl_argv);
	voidata.player_position = ft_player_pos(voidata.map);
	voidata.textures = ft_textures_init();
	ft_free_splt(spl_argv);
	return (voidata);
}

t_mlx	*ft_mlx_init(void)
{
	t_mlx	*new;

	new = malloc(sizeof(t_mlx));
	new->mlx_ptr = mlx_init();
	new->win_ptr = mlx_new_window(new->mlx_ptr, 1920, 1080, "cubed no payo");
	new->bits_per_pixel = 0;
	new->endian = 0;
	new->size_line = 0;
	new->img = NULL;
	new->img_addr = NULL;
	return (new);
}

t_imagen_info	*ft_textures_init(void)
{
	t_imagen_info	*new;

	new = malloc(sizeof(t_imagen_info));
	new->addres = NULL;
	new->bpp = 0;
	new->endian = 0;
	new->image_charge = NULL;
	new->line_s = 0;
	return (new);
}

char	**ft_setup_map(char **argv)
{
	char	**map;
	int		top;
	int		bot;
	int		idx;

	idx = 0;
	map = (char **)malloc(sizeof(char *) * 4092);
	top = ft_map_top(argv);
	bot = ft_map_bot(argv); // antets estaba -> (ft_map_bot(argv, top))
	while (top != bot + 1)
	{
		map[idx++] = ft_custstrdup(ft_string_streatment(argv[top]));
		top++;
	}
	map[idx] = NULL;
	return (map);
}

t_asset	*ft_setup_asset(char **argv)
{
	int		nidx;
	int		sidx;
	int		widx;
	int		eidx;
	t_asset	*newassets;

	ft_start_ids(argv, &nidx, &sidx, &widx, &eidx);
	newassets = malloc(sizeof(t_asset));
	newassets->north_texture = ft_return_path(ft_string_streatment(argv[nidx]));
	newassets->south_texture = ft_return_path(ft_string_streatment(argv[sidx]));
	newassets->west_texture = ft_return_path(ft_string_streatment(argv[widx]));
	newassets->east_texture = ft_return_path(ft_string_streatment(argv[eidx]));
	ft_set_rgbs(&newassets, argv);
	return (newassets);
}

t_pos	*ft_player_pos(char **map)
{
	int		idx;
	int		idy;
	t_pos	*position;

	position = malloc(sizeof(t_pos));
	idx = 0;
	idy = 0;
	while (map[idx])
	{
		while (map[idx][idy])
		{
			if (map[idx][idy] == 'N' || map[idx][idy] == 'S' || map[idx][idy] == 'E' || map[idx][idy] == 'W')
			{
				position->x = idx;
				position->y = idy;
			}
			idy++;
		}
		idy = 0;
		idx++;
	}
	position->dir = ft_posdir(map);
	return (position);
}

int	ft_posdir(char **map)
{
	int		idx;
	int		idy;
	int		res;

	idx = 0;
	idy = 0;
	res = 0;
	while (map[idx])
	{
		while (map[idx][idy])
		{
			if (map[idx][idy] == 'N')
				res = 0;
			if (map[idx][idy] == 'S')
				res = 1;
			if (map[idx][idy] == 'E')
				res = 2;
			if (map[idx][idy] == 'W')
				res = 3;
			idy++;
		}
		idy = 0;
		idx++;
	}
	return (res);
}
