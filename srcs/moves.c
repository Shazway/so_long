/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmoragli <tmoragli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/30 05:10:04 by tmoragli          #+#    #+#             */
/*   Updated: 2022/01/30 05:23:55 by tmoragli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	hook_keypress(int keycode, t_data *data)
{
	if (keycode == ESC)
	{
		printf("You pressed escape key\nGame closed\n");
		mlx_loop_end(data->mlx);
		return (0);
	}
	if (data->finish == 1)
		return (0);
	move_player(keycode, data);
	return (0);
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

void	show_moves(t_data *data)
{
	char	*temp;

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
