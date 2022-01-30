/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmoragli <tmoragli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/30 05:05:24 by tmoragli          #+#    #+#             */
/*   Updated: 2022/01/30 05:27:35 by tmoragli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	draw_player(t_data *data)
{
	if (data->start < 0)
		draw_texture(data, point(data->player.x, data->player.y),
			data->text[PLAYER], data->s);
	else if (data->start % 2 == 0)
		draw_texture(data, point(data->player.x, data->player.y),
			data->text[PLAYER_MOVE], data->s);
	else
		draw_texture(data, point(data->player.x, data->player.y),
			data->text[PLAYER_MOVE2], data->s);
}

void	draw_pixel(t_data *d, int x, int y, t_color color)
{
	if (color.o == 0 && (x >= 0 && x < d->width) && (y >= 0 && y < d->height))
		d->draw[y * d->width + x] = color;
}

t_color	convert_color(char r, char g, char b, char o)
{
	t_color	color;

	color.r = r;
	color.g = g;
	color.b = b;
	color.o = o;
	return (color);
}

t_color	get_pixel_color(t_img text, int x, int y)
{
	if ((x >= 0 && x < text.width) && (y >= 0 && y < text.height))
		return (text.draw[y * text.width + x]);
	return (convert_color(0, 0, 0, 0));
}

void	draw_texture(t_data *data, t_point pos, t_img text, int size)
{
	double	x;
	double	y;
	t_point	ratio;

	pos.x = pos.x * data->s + (data->s - size) / 2;
	pos.y = pos.y * data->s + (data->s - size) / 2;
	y = 0;
	while (y < size)
	{
		ratio.y = (double)(y / size)*text.height;
		x = 0;
		while (x < size)
		{
			ratio.x = (double)(x / size)*text.width;
			draw_pixel(data, x + pos.x, y + pos.y,
				get_pixel_color(text, (int)ratio.x, (int)ratio.y));
			x++;
		}
		y++;
	}
}
