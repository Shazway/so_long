/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmoragli <tmoragli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/30 13:22:35 by telli             #+#    #+#             */
/*   Updated: 2022/01/06 21:24:32 by tmoragli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_filldest(char const *s1, char const *s2, char *dest)
{
	int i;
	int j;

	j = 0;
	while (s1[j])
	{
		dest[j] = s1[j];
		j++;
	}
	i = 0;
	while (s2[i])
	{
		dest[j] = s2[i];
		j++;
		i++;
	}
	dest[j] = '\0';
	return (dest);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*dest;
	int		i;

	if (!s1 && !s2)
		return (NULL);
	if (!s1)
		return ((char *)(s2));
	if (!s2)
		return ((char *)(s1));
	i = ft_strlen((void *)s1) + ft_strlen((void *)s2) + 1;
	if (!(dest = malloc(sizeof(char) * (i))))
		return (NULL);
	return (ft_filldest(s1, s2, dest));
}
