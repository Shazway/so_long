/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory_allocs.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmoragli <tmoragli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 00:29:28 by tmoragli          #+#    #+#             */
/*   Updated: 2022/01/25 16:56:30 by tmoragli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int		ft_free(t_data *data)
{
	free(data->text);
	free(data->pars);
	//ft_free_tab(data->map);
	free(data);
	return(1);
}

int		ft_allocate(t_data *data)
{
	data->text = malloc(sizeof(t_img) * 9);
	data->pars = malloc(sizeof(t_parsing));
	if (!(data->text))
	{
		ft_free(data);
		return (1);
	}
	return (0);
}