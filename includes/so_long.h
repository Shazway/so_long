/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmoragli <tmoragli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/31 21:04:49 by tmoragli          #+#    #+#             */
/*   Updated: 2022/09/22 01:01:02 by tmoragli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include "../mlx/mlx.h"
# include "../libft/libft.h"
# include "get_next_line.h"
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <stdio.h>
# ifndef BONUS
#  define BONUS 0
# endif
# define SIZE 64
# define BACK 0
# define WALL 1
# define PLAYER 2
# define PLAYER_MOVE 3
# define PLAYER_MOVE2 4
# define ODOOR 5
# define CDOOR 6
# define COIN 7
# define END 8

# define ERR_MISS_OBJ "Missing exit, player or coins in the map"
# define ERR_BORDER "Borders aren't closed walls"
# define ERR_CHAR "Invalid char in the map"
# define ERR_PLAYER "Too many players in the map"
# define ERR_DIM "Wrong dimensions for the map"
# define ERR_NO_MAP "No map given"
# define ERR_MULTI_MAP "Multiple maps given"
# define ERR_MALLOC "Malloc failed"
# define ERR_BER "Not a .ber file, usage: ./so_long <path to .ber file try one in ./maps>"
# define W 119	//QWERTY
# define A 97		//QWERTY
# define S 115
# define D 100
# define Z 122	//AZERTY
# define Q 113	//AZERTY
# define ESC 65307

typedef struct s_point
{
	int	x;
	int	y;
}	t_point;

typedef struct s_color
{
	unsigned char	b;
	unsigned char	g;
	unsigned char	r;
	unsigned char	o;
}	t_color;

typedef struct s_img
{
	void	*img;
	int		height;
	int		width;
	void	*addr;
	t_color	*draw;
}	t_img;

typedef struct s_parsing
{	
	t_point	player;
	t_point	exit;
	t_point	collect;
	int		map_width;
	int		map_height;
}	t_parsing;

typedef struct s_data
{
	void		*mlx;
	void		*win;
	int			height;
	int			width;
	void		*img;
	char		*addr;
	char		**map;
	int			coins;
	int			finish;
	int			moves;
	int			s;
	int			start;
	int		direction;
	t_point		screen;
	t_point		map_size;
	t_point		player;
	t_point		exit;
	t_color		*draw;
	t_img		*text;
	t_parsing	*pars;
}	t_data;

//---------Parsing----------//
int		parsing(t_data *data, t_list *parse, char **argv);
int		map_parsing(t_list *parse, t_data *data);
int		map_dimensions(t_list *parse, t_data *data);
int		center_lines(char *line, int pos, t_data *data);
int		border_lines(char *border_line);
int		ft_error(t_data *data, char *error, int bool);
//---------Allocation-------//
int		ft_free(t_data *data, int bool);
void	destroy_text(t_data *data);
int		ft_allocate(t_data *data);
//---------Data init--------//
void	init_textures_data(t_data *data);
void	assign_text(t_data *data, int nb, char *path);
void	init_data(t_data *data);
void	init_mlx_data(t_data *data, int trash);
t_point	point(int x, int y);
//---------Checks/Errors----//
void	check_coin(t_data *data);
void	check_screen(t_data *data);
int		ft_error(t_data *data, char *error, int bool);
int		ft_checkber(char *av, char *ber);
void	check_exit(t_data *d);
//---------Drawing----------//
void	draw_pixel(t_data *d, int x, int y, t_color color);
t_color	get_pixel_color(t_img text, int x, int y);
void	draw_texture(t_data *data, t_point pos, t_img text, int size);
void	draw_player(t_data *data);
void	image(t_data *data);
void	map_fill(t_data *data);
void	draw_invert_texture(t_data *data, t_point pos, t_img text, int size);
//---------Moves------------//
void	move_player(int key, t_data *d);
void	show_moves(t_data *data);
int		hook_keypress(int keycode, t_data *data);

#endif
