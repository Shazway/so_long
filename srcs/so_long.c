/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmoragli <tmoragli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/31 21:08:18 by tmoragli          #+#    #+#             */
/*   Updated: 2023/02/09 22:07:00 by tmoragli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	comp_pos(t_point lhs, t_point rhs)
{
	if (lhs.x == rhs.x && lhs.y == rhs.y)
		return (1);
	return (0);
}

void	image(t_data *data)
{
	check_coin(data);
	if (!data->first_img) // first image, so we draw the full layout
		map_fill(data);
	else if (data->first_img == 1) //Then we only, erase the player, and draw it on the new pos
	{
		draw_texture(data, data->old_player, data->text[0], data->s);
		if (comp_pos(data->player, data->exit))
		{
			if (data->coins)
				draw_texture(data, data->player, data->text[CDOOR], data->s);
			else
				draw_texture(data, data->player, data->text[ODOOR], data->s);
		}
		else if (!data->coins)
			draw_texture(data, data->exit, data->text[ODOOR], data->s);
		draw_player(data);
	}
	data->first_img = 1;
	data->start++;
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
	show_moves(data);
	check_exit(data);
}

void	map_fill(t_data *data)
{
	int	x;
	int	y;

	y = 0;
	while (data->map[y])
	{
		x = 0;
		while (data->map[y][x])
		{	
			if (data->map[y][x] != '1')
				draw_texture(data, point(x, y), data->text[0], data->s);
			if (data->map[y][x] == '1')
				draw_texture(data, point(x, y), data->text[WALL], data->s);
			if (data->map[y][x] == 'E' && data->coins)
				draw_texture(data, point(x, y), data->text[CDOOR], data->s);
			if (data->map[y][x] == 'E' && data->coins == 0)
				draw_texture(data, point(x, y), data->text[ODOOR], data->s);
			if (data->map[y][x] == 'C')
				draw_texture(data, point(x, y), data->text[COIN], data->s / 2);
			x++;
		}
		y++;
	}
	draw_player(data);
}

void	so_long(t_data *data)
{
	image(data);
	mlx_hook(data->win, 33, 1L << 17, mlx_loop_end, data->mlx);
	mlx_hook(data->win, 2, 1L << 0, hook_keypress, data);
	mlx_loop(data->mlx);
}

int	main(int argc, char **argv)
{
	t_data	*data;
	t_list	*parse;

	parse = NULL;
	if (ft_checkber(argv[1], ".ber"))
		return (ft_error(NULL, ERR_BER, 1));
	data = malloc(sizeof(t_data));
	if (argc < 2)
		return (ft_error(data, ERR_NO_MAP, 1));
	if (argc > 2)
		return (ft_error(data, ERR_MULTI_MAP, 1));
	if (!data || ft_allocate(data))
		return (1);
	init_data(data);
	if (parsing(data, parse, argv))
		return (1);
	init_mlx_data(data, 0);
	init_textures_data(data);
	so_long(data);
	ft_free(data, 0);
	return (0);
}
