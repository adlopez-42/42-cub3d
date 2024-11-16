/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izperez <izperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 12:58:08 by adlopez-          #+#    #+#             */
/*   Updated: 2024/11/16 12:58:35 by izperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

// includes

# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <stdbool.h>
# include "../mlx/mlx.h"

//hook linux
# define A 97
# define D 100
# define W 119
# define S 115
# define LEFT 65361  // linux
# define RIGHT 65363 // linux
# define UP 65362    // linux
# define DOWN 65364  // linux
# define ESC 65307   // linux

// structs

// aqui pegas las que necesitas y todo llamado por t_data
// y cuando las tengas hacemos la ft_setup_data
//mlx
typedef struct s_mlx
{
	void				*mlx_ptr;
	void				*win_ptr;
	void				*img;
	void				*img_addr;
	int					bits_per_pixel;
	int					size_line;
	int					endian;
}						t_mlx;

//pintar imagenes en el juego de lo que devuelve la mlx
typedef struct s_info
{
	void				*image_charge;
	char				*addres;
	int					bpp;
	int					line_s;
	int					endian;
	bool				created;
}						t_info;

typedef struct s_player_position
{
	

}						t_player_position;

typedef struct s_pos_player
{
	double				x;
	double				y;
}						t_pos;

typedef struct s_data
{
	char				*north_texture;
	char				*south_texture;
	char				*west_texture;
	char				*east_texture;
	int					color_texture[3];
	char				**map;
	t_player_position	*player_position;
	t_mlx				mlx;
	t_info				*textures;
}						t_data;

// functions

char	            **ft_split(const char *s, char c);
void	            ft_error(int x);
int	                ft_interror(int x);
int	                ft_parse_map(int fd);
char	            *ft_string_streatment(char *str);
int	                ft_map_check(char **map);
int                 ft_full_mapcheck(char **map);
int                 ft_checkspaces(char **map);
int                 ft_checkplayer(char **map);
int	                ft_rgb_check(char **map);
int	                ft_rgb_check_single(char *map);
int	                ft_rgb_data(char *map, int flag);
int	                ft_floor_pos(char **map);
int	                ft_cieling_pos(char **map);
int	                ft_textures_check(char **map);
int	                ft_textures_access(char **map, int noid, int soid, int weid, int eaid);
int	                ft_textures_deepcheck(char *north, char *south, char *west, char *east);
char	            *ft_return_path(char *map);
void	            ft_free_paths(char *north, char *south, char *west, char *east);
int	                ft_xpm_check(char *chain, int idx);
int	                ft_cub(char *argv);
int	                ft_xpm_format(char **map, int noid, int soid, int weid, int eaid);
int	                ft_start_ids(char **map, int *no, int *so, int *we, int *ea);
char	            *ft_string_streatment(char *str);
int	                ft_map_top(char **map);
int	                ft_map_bot(char **map);
size_t              ft_strlen(const char *s);
void	            *ft_calloc(size_t count, size_t size);

void				init_data(t_data *data);

#endif