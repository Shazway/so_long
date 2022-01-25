/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data->textures_init.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmoragli <tmoragli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 16:36:52 by tmoragli          #+#    #+#             */
/*   Updated: 2022/01/24 13:32:36 by tmoragli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

// This function assigns to the tabulation of structures each textures data accordingly to the titles//
void	init_textures_data(t_data *data)
{
	int trash;
	//BACKGROUND TEXTURE//
	data->text[0].img = mlx_xpm_file_to_image(data->mlx, "Textures/Background.xpm", &data->text[0].width, &data->text[0].height);
	data->text[0].addr = mlx_get_data_addr(data->text[0].img, &trash, &trash, &trash);
	data->text[0].draw = (t_color *)data->text[0].addr;
	//WALL TEXTURE//
	data->text[1].img = mlx_xpm_file_to_image(data->mlx, "Textures/WallTexture.xpm", &data->text[1].width, &data->text[1].height);
	data->text[1].addr = mlx_get_data_addr(data->text[1].img, &trash, &trash, &trash);
	data->text[1].draw = (t_color *)data->text[1].addr;
	//PLAYER TEXTURES (3 different stances)//
	data->text[2].img = mlx_xpm_file_to_image(data->mlx, "Textures/Rezisedrogue.xpm", &data->text[2].width, &data->text[2].height);
	data->text[2].addr = mlx_get_data_addr(data->text[2].img, &trash, &trash, &trash);
	data->text[2].draw = (t_color *)data->text[2].addr;
	data->text[3].img = mlx_xpm_file_to_image(data->mlx, "Textures/WalkingRogue1.xpm", &data->text[3].width, &data->text[3].height);
	data->text[3].addr = mlx_get_data_addr(data->text[3].img, &trash, &trash, &trash);
	data->text[3].draw = (t_color *)data->text[3].addr;
	data->text[4].img = mlx_xpm_file_to_image(data->mlx, "Textures/WalkingRogue2.xpm", &data->text[4].width, &data->text[4].height);
	data->text[4].addr = mlx_get_data_addr(data->text[4].img, &trash, &trash, &trash);
	data->text[4].draw = (t_color *)data->text[4].addr;
	//EXIT TEXTURE (2 opened and closed)//
	data->text[5].img = mlx_xpm_file_to_image(data->mlx, "Textures/ClosedDoor.xpm", &data->text[5].width, &data->text[5].height);
	data->text[5].addr = mlx_get_data_addr(data->text[5].img, &trash, &trash, &trash);
	data->text[5].draw = (t_color *)data->text[5].addr;
	data->text[6].img = mlx_xpm_file_to_image(data->mlx, "Textures/OpenedDoor.xpm", &data->text[6].width, &data->text[6].height);
	data->text[6].addr = mlx_get_data_addr(data->text[6].img, &trash, &trash, &trash);
	data->text[6].draw = (t_color *)data->text[6].addr;
	//COLLECTIBLE TEXTURE//
	data->text[7].img = mlx_xpm_file_to_image(data->mlx, "Textures/Coin.xpm", &data->text[7].width, &data->text[7].height);
	data->text[7].addr = mlx_get_data_addr(data->text[7].img, &trash, &trash, &trash);
	data->text[7].draw = (t_color *)data->text[7].addr;
	//FINAL MESSAGE TEXTURE//
	data->text[8].img = mlx_xpm_file_to_image(data->mlx, "Textures/lvl_cleared.xpm", &data->text[8].width, &data->text[8].height);
	data->text[8].addr = mlx_get_data_addr(data->text[8].img, &trash, &trash, &trash);
	data->text[8].draw = (t_color *)data->text[8].addr;
}