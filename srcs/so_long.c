/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmoragli <tmoragli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/31 21:08:18 by tmoragli          #+#    #+#             */
/*   Updated: 2022/01/30 13:31:01 by tmoragli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	image(t_data *data)
{
	check_coin(data);
	map_fill(data);
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

int	ft_error(t_data *data, char *error, int bool)
{
	printf("Error\n%s\n", error);
	if (bool == 1)	
		free(data);
	else
		ft_free(data, 1);
	return (1);
}

int	main(int argc, char **argv)
{
	t_data	*data;
	t_list	*parse;

	parse = NULL;
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
