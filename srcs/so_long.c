/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmoragli <tmoragli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/31 21:08:18 by tmoragli          #+#    #+#             */
/*   Updated: 2022/01/24 16:04:46 by tmoragli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	draw_pixel(t_data *data, int x, int y, t_color color)
{
	if (color.o == 0 && (x >= 0 && x < data->width) && (y >=0 && y < data->height))
		data->draw[y * data->width + x] = color;
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

void	draw_texture(t_data *data, int posx, int posy, t_img text)
{
	int x;
	int y;

	y = 0;
	while (y < text.height)
	{
		x = 0;
		while (x < text.width)
		{
			draw_pixel(data, x + posx, y + posy, get_pixel_color(text, x, y));
			x++;
		}
		y++;
	}
}
void	background_fill(t_data *data, t_img text)
{
	int x;
	int y;

	y = 0;
	while (y < data->height)
	{
		x = 0;
		while(x < data->width)
		{
			draw_texture(data, x, y, text);
			x += text.width;
		}
		y += text.height;
	}
}

void	ceiling_ground(t_data *data, t_img text)
{
	int x;
	int y;

	y = 0;
	x  = 0;
	while (x < data->width)
	{
		draw_texture(data, x, y, text);
		x += text.width;
	}
	y = data->height - text.height;
	x = 0;
	while (x < data->width)
	{
		draw_texture(data, x, y, text);
		x += text.width;
	}
}
void	walls(t_data *data, t_img text)
{
	int x;
	int y;

	x = 0;
	y = 0;
	while (y < data->height)
	{
		draw_texture(data, x, y, text);
		y += text.height;
	}
	x = data->width - text.width;
	y = 0;
		while (y < data->height)
	{
		draw_texture(data, x, y, text);
		y += text.height;
	}
}
void	wall_fill(t_data *data, t_img text)
{
	int x;
	int y;

	y = 0;
	while (data->map[y])
	{
		x = 0;
		while (data->map[y][x])
		{
			if (data->map[y][x] == '1')
				draw_texture(data, x * text.width, y * text.height, text);
			x++;
		}
		y++;
	}
}

void	init_mlx_data(t_data *data, int trash)
{
	data->win = mlx_new_window(data->mlx, data->width, data->height, "Dodgy Dungeon");
	data->img = mlx_new_image(data->mlx, data->width, data->height);
	data->addr = mlx_get_data_addr(data->img, &trash, &trash, &trash);
	data->draw = (t_color *)data->addr;
}

void	first_image(t_data *data)
{
	background_fill(data, data->text[0]);
	wall_fill(data, data->text[1]);
}

void	so_long(t_data *data)
{
	first_image(data);
	printf("%d\n", data->text[1].height);
	printf("%d\n", data->text[1].width);
	//draw_texture(data, 250, 250);
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
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
	init_textures_data(data);
	if (parsing(data, parse, argv))
	{
		ft_free(data);
		write(1, "Map error\n", 11);
		return (1);
	}
	init_mlx_data(data, 0);
	printf("%d, %d\n", data->height, data->width);
	so_long(data);
	ft_free(data);
	return (0);
}