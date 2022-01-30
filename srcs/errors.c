/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmoragli <tmoragli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/30 17:32:53 by tmoragli          #+#    #+#             */
/*   Updated: 2022/01/30 17:33:21 by tmoragli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	ft_error(t_data *data, char *error, int bool)
{
	printf("Error\n%s\n", error);
	if (bool == 1)
		free(data);
	else
		ft_free(data, 1);
	return (1);
}

int	ft_checkber(char *av, char *ber)
{
	int	i;
	int	j;

	i = ft_strlen(av) - 4;
	j = 0;
	while (av && ber && av[i] == ber[j] && av[i] && ber[j])
	{
		j++;
		i++;
	}
	if (j != (ft_strlen(ber)))
		return (1);
	return (0);
}
