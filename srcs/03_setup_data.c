/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   03_setup_data.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izperez <izperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 18:55:28 by adrian            #+#    #+#             */
/*   Updated: 2024/12/04 13:51:53 by izperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

t_data	*ft_setup_data(t_checks *checker)
{
	t_data	*voidata;

	voidata = malloc(sizeof(t_data));
	voidata->map = ft_clean_map(checker->map);
	voidata->asset = ft_setup_assets(checker);
	voidata->playerpos = ft_playerpos(checker->map);
	voidata->textures = ft_setup_textures();
	voidata->mlx = ft_mlx_init(voidata->map);
	return (voidata);
}

t_image_info	*ft_setup_textures(void)
{
	t_image_info *new;

	new = malloc(sizeof(t_image_info));
	new->address = NULL;
	new->bpp = 0;
	new->endian = 0;
	new->image_charge = NULL;
	new->line_s = 0;
	return (new);
}

t_pos	*ft_playerpos(char **map)
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
			if (map[idx][idy] == 'N' || map[idx][idy] == 'S' || map[idx][idy] == 'W' || map[idx][idy] == 'E')
			{
				position->x = idx + 0.5;
				position->y = idy + 0.5;
			}
			idy++;
		}
		idy = 0;
		idx++;
	}
	position->dir = ft_posdir(map);
	return (position);
}

t_mlx	*ft_mlx_init(t_map *map)
{
	t_mlx	*new;

	new = (t_mlx *)malloc(sizeof(t_mlx));
	new->mlx = mlx_init();
	new->win = mlx_new_window(new->mlx, 3491, 1964, "cub3d no payo");
	// new->win = mlx_new_window(new->mlx, map->width * 100, map->height * 100, "cubed");
	//new->bit_per_pixel = 0;
	//new->endian = 0;
	//new->size_line = 0;
	new->img =  mlx_new_image(new->mlx, map->width * 100, map->height * 100);
	if (new->img == NULL)
		printf("la img ta null\n");
	new->img_addr = mlx_get_data_addr(new->img, &new->bit_per_pixel, &new->size_line, &new->endian);
	new->width_window = map->width * 100;
	new->height_window = map->height * 100;
	return (new);
}

t_asset	*ft_setup_assets(t_checks *checker)
{
	t_asset	*new;
	int		*cieling;
	int		*floor;

	new = malloc(sizeof(t_asset));
	cieling = (int *)malloc(sizeof(int) * 3);
	floor = (int *)malloc(sizeof(int) * 3);
	new->north_texture = ft_strdup(checker->north_texture);
	new->south_texture = ft_strdup(checker->south_texture);
	new->west_texture = ft_strdup(checker->west_texture);
	new->east_texture = ft_strdup(checker->east_texture);
	cieling[0] = checker->c_red;
	cieling[1] = checker->c_green;
	cieling[2] = checker->c_blue;
	floor[0] = checker->f_red;
	floor[1] = checker->f_green;
	floor[2] = checker->f_blue;
	new->cieling_rgb = cieling;
	new->floor_rgb = floor;
	return (new);
}
