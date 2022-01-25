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

void	assign_text(t_data *data, int nb, char *path)
{
	int trash;

	data->text[nb].img = mlx_xpm_file_to_image(data->mlx, path, &data->text[nb].width, &data->text[nb].height);
	data->text[nb].addr = mlx_get_data_addr(data->text[nb].img, &trash, &trash, &trash);
	data->text[nb].draw = (t_color *)data->text[nb].addr;
}

void	init_textures_data(t_data *data)
{
	data->mlx = mlx_init();
	//BACKGROUND TEXTURE//
	assign_text(data, 0, "Textures/Background.xpm");
	//WALL TEXTURE//
	assign_text(data, 1, "Textures/WallTexture.xpm");
	//PLAYER TEXTURES (3 different stances)//
	assign_text(data, 2, "Textures/SpawnRogue.xpm");
	assign_text(data, 3, "Textures/WalkingRogue1.xpm");
	assign_text(data, 4, "Textures/WalkingRogue2.xpm");
	//EXIT TEXTURE (2 opened and closed)//
	assign_text(data, 5, "Textures/OpenedDoor.xpm");
	assign_text(data, 6, "Textures/ClosedDoor.xpm");
	//COLLECTIBLE TEXTURE//
	assign_text(data, 7, "Textures/Coin.xpm");
	//FINAL MESSAGE TEXTURE//
	assign_text(data, 8, "Textures/End.xpm");
}