/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmoragli <tmoragli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 16:20:16 by tmoragli          #+#    #+#             */
/*   Updated: 2022/01/27 21:30:04 by tmoragli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int		border_lines(char *border_line)
{
	int i;

	i = 0;
	while (border_line[i] && border_line[i] == '1')
		i++;
	if (i == ft_strlen((const char *)border_line))
		return (0);
	return (1);
}

int		center_lines(char *line)
{
	int i;

	i = 0;
	while (line && line[i])
	{
		if (line[0] != '1' || line[ft_strlen(line) - 1] != '1')
			return (1);
		if (line[i] != 'P' && line[i] != '0' && line[i] != 'E' 
			&& line[i] != 'C' && line[i] != '1')
			return (1);
		i++;
	}
	return (0);
}

int		map_dimensions(t_list *parse, t_data *data)
{
	int	width;

	width = ft_strlen((const char *)parse->content);
	data->width = data->text[1].width * width;
	while (parse)
	{
		if (width != ft_strlen((const char *)parse->content))
			return (1);
		if (!(parse->next))
			return (0);
		parse = parse->next;
	}
	return (0);
}

int		map_parsing(t_list *parse, t_data *data)
{
	int pos;
	int size;

	size = ft_lstsize(parse);
	data->map = malloc(sizeof(char *) * (size + 1));
	data->height = data->text[1].height * size;
	pos = 0;
	while (parse)
	{
		if (pos == 0 || pos == size)
			if (border_lines((char *)parse->content))
				return (1);
		if (center_lines((char *)parse->content))
			return (1);
		data->map[pos] = parse->content;
		if (!(parse->next))
		{	
			if (border_lines((char *)parse->content))
				return (1);
			else
			{	
				data->map[pos + 1] = NULL;
				return (0);
			}
		}
		pos++;
		parse = parse->next;
	}
	return(0);
}

int		parsing(t_data *data, t_list *parse, char **argv)
{
	int		fd;
	char	*line;

	fd = open(argv[1], O_RDONLY);
	while (get_next_line(fd, &line))
		ft_lstadd_back(&parse, ft_lstnew(line));
	ft_lstadd_back(&parse, ft_lstnew(line));
	close(fd);
	if (map_parsing(parse, data) || map_dimensions(parse, data))
	{
		ft_lstclear(&parse, free);
		return (1);
	}
	return(0);
}
