/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 12:58:08 by adlopez-          #+#    #+#             */
/*   Updated: 2024/11/19 13:00:01 by marvin           ###   ########.fr       */
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

// macros

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

//mlx
typedef struct s_mlx
{
	void				*mlx;
	void				*win;
	void				*img;
	void				*img_addr;
	int					bits_per_pixel;
	int					size_line;
	int					endian;
}						t_mlx;

//pintar imagenes en el juego de lo que devuelve la mlx
typedef struct s_image_info
{
	void				*image_charge;
	char				*addres;
	int					bpp;
	int					line_s;
	int					endian;
	bool				created;
}						t_image_info;

typedef struct s_playerpos
{
	double				x;
	double				y;
	int					dir;
}						t_pos;

// dir es 0 - norte, 1 - sur, 2 - este, 3 - oeste

// he hecho una estructura pa eso pork asi parece q curramos biende

typedef struct s_asset
{
	char				*north_texture;
	char				*south_texture;
	char				*west_texture;
	char				*east_texture;
	int					*cieling_rgb;
	int					*floor_rgb;
}						t_asset;

typedef struct s_data
{
	char				**map;
	t_asset				*asset;
	t_pos				*player_position;
	t_mlx				mlx;
	t_image_info		*textures;
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
int	                ft_map_bot(char **map, int flag);
size_t              ft_strlen(const char *s);
void	            *ft_calloc(size_t count, size_t size);
char				*ft_custstrdup(char *str);
void				ft_free_splt(char **spt);
int					*ft_set_rgb(char *map, int start);
void				ft_set_rgbs(t_asset **asset, char **map);
t_pos				*ft_player_pos(char **argv);
t_asset				*ft_setup_asset(char **argv);
char				**ft_setup_map(char **argv);
t_data				ft_setup_data(int fd);
int					ft_corr_line(char *line);
void				ft_print_data(t_data data);
int 				ft_player_access(char **map);
int					ft_rgb_data_2(char *map);
void				ft_free_data(t_data data);
t_image_info		*ft_textures_init(void);
int					ft_posdir(char **map);
t_mlx				*ft_mlx_init(void);

#endif