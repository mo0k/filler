/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_piece.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoucade <jmoucade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 21:53:58 by mo0ky             #+#    #+#             */
/*   Updated: 2017/12/06 15:04:46 by jmoucade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <filler.h>

static int		init_piece(char **line, t_map *piece)
{
	char	*ptr;

	if (!piece || !line)
		return (0);
	ptr = *line;
	ptr += 6;
	if ((piece->height = get_number(ptr)) < 0)
		return (0);
	if ((piece->width = get_number(ptr + ft_nbrlen(piece->height) + 1)) < 0)
		return (0);
	if (!(piece->map = (char**)malloc(sizeof(char*) * (piece->height + 1))))
		return (0);
	piece->map[piece->height] = NULL;
	(line && *line) ? ft_memdel((void*)line) : 0;
	return (1);
}

int				set_piece(char **line, t_map *piece)
{
	int		i;

	if (!line || !*line || !piece)
		return (0);
	i = -1;
	if (!init_piece(line, piece))
		return (0);
	while (++i < piece->height)
	{
		if (get_next_line(0, line) < 1)
			return (0);
		if ((int)ft_strlen(*line) != piece->width)
			return (0);
		if (!(piece->map[i] = ft_strdup(*line)))
			return (0);
		(line && *line) ? ft_memdel((void*)line) : 0;
	}
	return (1);
}
