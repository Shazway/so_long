/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmoragli <tmoragli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/31 21:08:18 by tmoragli          #+#    #+#             */
/*   Updated: 2022/01/29 23:42:25 by tmoragli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	draw_pixel(t_data *d, int x, int y, t_color color)
{
	if (color.o == 0 && (x >= 0 && x < d->width) && (y >= 0 && y < d->height))
		d->draw[y * d->width + x] = color;
}
t_color	convert_color(char r, char g, char b, char o)
{
	t_color color;

	color.r = r;
	color.g = g;
	color.b = b;
	color.o = o;
	return (color);
}
t_color	get_pixel_color(t_img text, int x, int y)
{
	if ((x >= 0 && x < text.width) && (y >=0 && y < text.height))	
		return (text.draw[y * text.width + x]);
	return (convert_color(0, 0, 0, 0));
}

void	draw_texture(t_data *data, t_point pos, t_img text, int size)
{
	double x;
	double y;
	t_point ratio;

	pos.x = pos.x * data->s + (data->s - size) / 2;
	pos.y = pos.y * data->s + (data->s - size) / 2;
	y = 0;
	while (y < size)
	{
		ratio.y = (double)(y / size) * text.height;
		x = 0;
		while (x < size)
		{
			ratio.x = (double)(x / size) * text.width;
			draw_pixel(data, x + pos.x, y + pos.y,
			get_pixel_color(text, (int)ratio.x, (int)ratio.y));
			x++;
		}
		y++;
	}
}

t_point point(int x, int y)
{
	t_point ret;

	ret.x = x;
	ret.y = y;
	return (ret);
}

void	show_moves(t_data *data)
{
	char *temp;
	if (BONUS == 1)
	{
		mlx_string_put(data->mlx, data->win, 5, 10, 0xFFFFFF, "Moves: ");
		temp = ft_itoa(data->moves);
		mlx_string_put(data->mlx, data->win, 42, 10, 0xFFFFFF, temp);
		free(temp);
	}
	else
		printf("Moves: %d\n", data->moves);
}

void	map_fill(t_data *data)
{
	int x;
	int y;

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
	draw_texture(data, point(data->player.x, data->player.y),
		data->text[PLAYER], data->s);
}

void	check_screen(t_data *data)
{
	t_point diff;

	diff.x = data->width - data->screen.x;
	diff.y = data->height - data->screen.y;
	if (diff.x <= 0 && diff.y <= 0)
		return ;
	if (diff.x > diff.y)
		data->s = data->screen.x / data->map_size.x;
	else
		data->s = data->screen.y / data->map_size.y;
	data->width = data->map_size.x * data->s;
	data->height = data->map_size.y * data->s;
}

void	init_mlx_data(t_data *data, int trash)
{
	int	x;
	int	y;

	data->mlx = mlx_init();
	mlx_get_screen_size(data->mlx, &x, &y);
	data->screen.x = x;
	data->screen.y = y;
	check_screen(data);
	data->win = mlx_new_window(data->mlx, data->width, data->height,
		"Dodgy Dungeon");
	data->img = mlx_new_image(data->mlx, data->width, data->height);
	data->addr = mlx_get_data_addr(data->img, &trash, &trash, &trash);
	data->draw = (t_color *)data->addr;
}

void	check_coin(t_data *data)
{
	if (data->map[(int)data->player.y][(int)data->player.x] != 'C')
		return ;
	data->coins--;
	data->map[(int)data->player.y][(int)data->player.x] = '0';
}

void	check_exit(t_data *d)
{
	if (d->map[(int)d->player.y][(int)d->player.x] != 'E' || d->coins)
		return ;
	d->finish = 1;
	draw_texture(d, point(d->width / d->s / 2,
	d->height / d->s / 2), d->text[END], d->width / 2);
}

void	image(t_data *data)
{
	check_coin(data);
	map_fill(data);
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
	show_moves(data);
	check_exit(data);
}

void	move_player(int key, t_data *d)
{
	if (key == UP && d->map[(int)d->player.y - 1][(int)d->player.x] != '1')
		d->player.y--;
	else if (key == DW && d->map[(int)d->player.y + 1][(int)d->player.x] != '1')
		d->player.y++;
	else if (key == LT && d->map[(int)d->player.y][(int)d->player.x + 1] != '1')
		d->player.x++;
	else if (key == RT && d->map[(int)d->player.y][(int)d->player.x - 1] != '1')
		d->player.x--;
	else
		return ;
	d->moves++;
	image(d);
}

int		hook_keypress(int keycode, t_data *data)
{
	if (keycode == ESC)
	{
		printf("You pressed escape key\nSession terminated\n");
		mlx_loop_end(data->mlx);
		return (0);
	}
	if (data->finish == 1)
		return (0);
	move_player(keycode, data);
	return (0);
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

	if (argc != 2)
		return (1);
	parse = NULL;
	data = malloc(sizeof(t_data));
	if (!data || ft_allocate(data))
		return (1);
	init_data(data);
	if (parsing(data, parse, argv))
	{
		ft_free(data, 1);
		write(1, "Map error\n", 11);
		return (1);
	}
	init_mlx_data(data, 0);
	init_textures_data(data);
	so_long(data);
	ft_free(data, 0);
	return (0);
}