/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory_allocs.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmoragli <tmoragli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 00:29:28 by tmoragli          #+#    #+#             */
/*   Updated: 2022/01/30 17:28:51 by tmoragli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	destroy_text(t_data *data)
{
	int	nb;

	nb = -1;
	while (data->text && ++nb < 9)
		mlx_destroy_image(data->mlx, data->text[nb].img);
}

int	ft_free(t_data *data, int bool)
{
	if (data)
	{
		if (bool == 0)
		{
			destroy_text(data);
			if (data->img)
				mlx_destroy_image(data->mlx, data->img);
			if (data->win)
				mlx_destroy_window(data->mlx, data->win);
			if (data->mlx)
				mlx_destroy_display(data->mlx);
			if (data->mlx)
				free(data->mlx);
		}
		if (data->map)
			ft_free_tab(data->map);
		if (data->text)
			free(data->text);
		free(data);
		if (data->pars)
			free(data->pars);
	}
	return (1);
}

int	ft_allocate(t_data *data)
{
	data->text = malloc(sizeof(t_img) * 9);
	data->pars = malloc(sizeof(t_parsing));
	if (!(data->text) || !data->pars)
	{
		ft_free(data, 1);
		return (1);
	}
	return (0);
}
