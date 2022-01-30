/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmoragli <tmoragli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/30 05:00:15 by tmoragli          #+#    #+#             */
/*   Updated: 2022/01/30 05:03:45 by tmoragli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	check_screen(t_data *data)
{
	t_point	diff;

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
	printf("Stage Cleared ! Good job :)\n");
}
