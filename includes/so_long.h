/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmoragli <tmoragli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/31 21:04:49 by tmoragli          #+#    #+#             */
/*   Updated: 2022/01/27 21:28:39 by tmoragli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include "../mlx/mlx.h"
# include "../includes/libft.h"
# include "get_next_line.h"
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>

typedef	struct s_point
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

typedef	struct s_img
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
	t_point collect;
	int		map_width;
	int		map_height;
}	t_parsing;

typedef	struct s_data
{
	void		*mlx;
	void		*win;
	int			height;
	int			width;
	void		*img;
	char		*addr;
	char		**map;
	t_color		*draw;
	t_img		*text;
	t_parsing	*pars;
}	t_data;

//---------Parsing----------//
int		parsing(t_data *data, t_list *parse, char **argv);
int		map_parsing(t_list *parse, t_data *data);
int		map_dimensions(t_list *parse, t_data *data);
int		center_lines(char *line);
int		border_lines(char *border_line);
//---------Allocation-------//
int		ft_free(t_data *data, int bool);
int		ft_allocate(t_data *data);
//---------Data init--------//
void	init_textures_data(t_data *data);
void	assign_text(t_data *data, int nb, char *path);

#endif
