/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmoragli <tmoragli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/31 21:04:49 by tmoragli          #+#    #+#             */
/*   Updated: 2022/01/24 15:40:00 by tmoragli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include "../mlx/mlx.h"
# include "libft.h"
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
}	t_parsing;

typedef	struct s_data
{
	void		*mlx;
	void		*win;
	int			height;
	int			width;
	void		*img;
	char		*addr;
	t_color		*draw;
	t_img		*text;
	t_parsing	*pars;
}	t_data;

//---------Parsing----------//
int		parsing(t_list *parse, char **argv);
int		map_parsing(t_list *parse);
int		map_dimensions(t_list *parse);
int		center_lines(char *line);
int		border_lines(char *border_line);
//---------Allocation-------//
int		ft_free(t_data *data);
int		ft_allocate(t_data *data);
//---------Data init--------//
void	init_textures_data(t_data *data);

#endif
