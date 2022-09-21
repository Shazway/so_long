/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmoragli <tmoragli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/30 04:55:20 by tmoragli          #+#    #+#             */
/*   Updated: 2022/01/30 05:24:40 by tmoragli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

t_point	point(int x, int y)
{
	t_point	ret;

	ret.x = x;
	ret.y = y;
	return (ret);
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
			"Kirby's Dungeon");
	data->img = mlx_new_image(data->mlx, data->width, data->height);
	data->addr = mlx_get_data_addr(data->img, &trash, &trash, &trash);
	data->draw = (t_color *)data->addr;
}

void	assign_text(t_data *data, int nb, char *path)
{
	int	trash;

	data->text[nb].img = mlx_xpm_file_to_image(data->mlx, path,
			&data->text[nb].width, &data->text[nb].height);
	data->text[nb].addr = mlx_get_data_addr(data->text[nb].img,
			&trash, &trash, &trash);
	data->text[nb].draw = (t_color *)data->text[nb].addr;
}

void	init_data(t_data *data)
{
	data->player.x = -1;
	data->player.y = -1;
	data->exit.x = -1;
	data->exit.y = -1;
	data->coins = 0;
	data->finish = 0;
	data->moves = 0;
	data->s = SIZE;
	data->start = -1;
	data->direction = 0;
}

void	init_textures_data(t_data *data)
{
	assign_text(data, 0, "Textures/Background.xpm");
	assign_text(data, 1, "Textures/WallTexture.xpm");
	assign_text(data, 2, "Textures/Kirby_Spawn.xpm");
	assign_text(data, 3, "Textures/WalkingKirby1.xpm");
	assign_text(data, 4, "Textures/WalkingKirby2.xpm");
	assign_text(data, 5, "Textures/OpenedDoor.xpm");
	assign_text(data, 6, "Textures/ClosedDoor.xpm");
	assign_text(data, 7, "Textures/Coin.xpm");
	assign_text(data, 8, "Textures/End.xpm");
}
