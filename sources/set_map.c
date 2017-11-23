/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mo0ky <mo0ky@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 21:53:58 by mo0ky             #+#    #+#             */
/*   Updated: 2017/11/23 23:31:05 by mo0ky            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <filler.h>

int		set_map(char **line, t_map *map)
{
	char 	*ptr;
	int		i;
	char	*start;

	if (!line || !*line || !map)
		return (0);
	ptr = *line;
	ptr += 8;
	i = -1;
	if ((map->height = get_number(ptr)) < 0)
		return (0);
	if ((map->width = get_number(ptr + ft_nbrlen(map->height) + 1)) < 0)
		return (0);
	if (!(map->map = (char**)malloc(sizeof(char*) * (map->height + 1))))
		return (0);
	map->map[map->height] = NULL;
	(line && *line) ? ft_memdel((void*)line) : 0;
	get_next_line(0, line);
	(*line) ? ft_dprintf(2, "%s\n", *line) : 0;
	(line && *line) ? ft_memdel((void*)line) : 0;
	while (++i < map->height)
	{
		if (get_next_line(0, line) < 1)
			return (0);
		if (!((start = ft_strchr(*line, ' ')) ? ++start : 0))
			return (0);
		map->map[i] = NULL;
		if ((int)ft_strlen(start) != map->width)
			return (0);
		if(!(map->map[i] = ft_strdup(start)))
			return (0);
		ft_dprintf(2, "%s\n", *line);
		(line && *line) ? ft_memdel((void*)line) : 0;
	}
	ft_dprintf(2, "Map loaded(height:%d, width:%d)\n", map->height, map->width);
	return (1);
}
