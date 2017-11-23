/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_piece.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mo0ky <mo0ky@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 21:53:58 by mo0ky             #+#    #+#             */
/*   Updated: 2017/11/23 23:31:04 by mo0ky            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <filler.h>

int		set_piece(char **line, t_map *piece)
{
	char 	*ptr;
	int		i;

	if (!line || !*line || !piece)
		return (0);
	ptr = *line;
	ptr += 6;
	i = -1;
	if ((piece->height = get_number(ptr)) < 0)
		return (0);
	if ((piece->width = get_number(ptr + ft_nbrlen(piece->height) + 1)) < 0)
		return (0);
	if (!(piece->map = (char**)malloc(sizeof(char*) * (piece->height + 1))))
		return (0);
	piece->map[piece->height] = NULL;
	(line && *line) ? ft_memdel((void*)line) : 0;
	while (++i < piece->height)
	{
		if (get_next_line(0, line) < 1)
			return (0);
		if ((int)ft_strlen(*line) != piece->width)
			return (0);
		if(!(piece->map[i] = ft_strdup(*line)))
			return (0);
		(line && *line) ? ft_memdel((void*)line) : 0;
		ft_dprintf(2, "%s\n", piece->map[i]);
	}
	ft_dprintf(2, "Piece loaded(height:%d, width:%d)\n", piece->height, piece->width);
	return (1);
}
