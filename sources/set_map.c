/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoucade <jmoucade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 21:53:58 by mo0ky             #+#    #+#             */
/*   Updated: 2017/12/06 15:07:08 by jmoucade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <filler.h>

static int		init_map(char **line, t_map *map)
{
	char	*ptr;

	if (!map || !line)
		return (0);
	ptr = *line;
	ptr += 8;
	if ((map->height = get_number(ptr)) < 0)
		return (0);
	if ((map->width = get_number(ptr + ft_nbrlen(map->height) + 1)) < 0)
		return (0);
	if (!(map->map = (char**)malloc(sizeof(char*) * (map->height + 1))))
		return (0);
	map->map[map->height] = NULL;
	(line && *line) ? ft_memdel((void*)line) : 0;
	get_next_line(0, line);
	(line && *line) ? ft_memdel((void*)line) : 0;
	return (1);
}

int				set_map(char **line, t_map *map)
{
	int		i;
	char	*start;

	if (!line || !*line || !map)
		return (0);
	i = -1;
	init_map(line, map);
	while (++i < map->height)
	{
		if (get_next_line(0, line) < 1)
			return (0);
		if (!((start = ft_strchr(*line, ' ')) ? ++start : 0))
			return (0);
		map->map[i] = NULL;
		if ((int)ft_strlen(start) != map->width)
			return (0);
		if (!(map->map[i] = ft_strdup(start)))
			return (0);
		(line && *line) ? ft_memdel((void*)line) : 0;
	}
	return (1);
}
