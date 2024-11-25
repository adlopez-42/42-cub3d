/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izperez <izperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 12:58:08 by adlopez-          #+#    #+#             */
/*   Updated: 2024/11/25 13:35:30 by izperez          ###   ########.fr       */
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
typedef struct s_ray
{
	double	pos_x;
	double	pos_y;
	double	dir_x;
	double	dir_y;
	double	delta_x; //distancia entre pasos en x
	double	delta_y; // distancia entre pasos en y
	int		step_x;	//direccion del movimiento del rayo
	int		step_y;
	double	side_x; // distancia que necesita recorrer el rayo hasta que atraviese un borde del mapa
	double	side_y;
	int		map_x;
	int		map_y;
}				t_ray;

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
typedef struct s_imagen_info
{
	void				*image_charge;
	char				*addres;
	int					bpp;
	int					line_s;
	int					endian;
	bool				created;
}						t_imagen_info;

/* typedef struct s_player_position
{
	double	x;
	double	y;

}						t_player_position; */

typedef struct s_pos_player
{
	double				x;
	double				y;
	int					dir;
}						t_pos;

typedef struct s_asset
{
	char				*north_texture;
	char				*south_texture;
	char				*west_texture;
	char 				*east_texture;
	int					*cieling_rgb;
	int					*floor_rgb;
}				t_asset;


typedef struct s_data
{
	char						**map;
	t_asset						*asset;
	t_pos						*player_position;
	t_mlx						mlx;
	t_imagen_info				*textures;
	t_ray						*ray;
}						t_data;

// functions
//utils/00_split.c
//static int		ft_wordcount(const char *str, char c);
//static char		*ft_splitwords(const char *str, int start, int end);
//static void		*ft_free(char **strs, int count);
//static void		ft_iniciovar(size_t *x, int *y, int *word);
char			**ft_split(const char *s, char c);

//utils/00_split.c
void			*ft_calloc(size_t count, size_t size);
size_t			ft_strlen(const char *s);


//00_error.c
void			ft_error(int x);
int				ft_interror(int x);

//01_parse.c
int				ft_parse_map(int fd);

//02_mapcheck.c
int				ft_map_check(char **map);
int				ft_full_mapcheck(char **map);
int				ft_player_access(char **map);
int				ft_checkspaces(char **map);
int				ft_checkplayer(char **map);

//03_redgreenblue.c
int				ft_rgb_check(char **map);
int				ft_rgb_check_single(char *map);
int				ft_rgb_data_2(char *map);
int				ft_rgb_data(char *map, int flag);
int				ft_floor_pos(char **map);
int				ft_cieling_pos(char **map);

//04_textures.c
int				ft_textures_check(char **map);
int				ft_textures_access(char **map, int noid, int soid, int weid, int eaid);
int				ft_textures_deepcheck(char *north, char *south, char *west, char *east);
char			*ft_return_path(char *map);
void			ft_free_paths(char *north, char *south, char *west, char *east);

//05_parse_utils.c
int				ft_xpm_check(char *chain, int idx);
int				ft_cub(char *argv);
int				ft_xpm_format(char **map, int noid, int soid, int weid, int eaid);
int				ft_start_ids(char **map, int *no, int *so, int *we, int *ea);
char			*ft_string_streatment(char *str);

//06_parse_utils_2.c
int				ft_map_top(char **map);
int				ft_map_bot(char **map);
int				ft_corr_line(char *line);

//07_init_setup.c
t_data			ft_setup_data(int fd);
t_mlx			*ft_mlx_init(void);
t_imagen_info	*ft_textures_init(void);
char			**ft_setup_map(char **argv);
t_asset			*ft_setup_asset(char **argv);
t_pos			*ft_player_pos(char **map);
int				ft_posdir(char **map);

//08_setup_utils.c
void			ft_set_rgbs(t_asset **asset, char **map);
int				*ft_set_rgb(char *map, int flag);
void			ft_free_splt(char **spt);
char			*ft_custstrdup(char *str);


#endif