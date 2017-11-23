/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mo0ky <mo0ky@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 21:53:58 by mo0ky             #+#    #+#             */
/*   Updated: 2017/11/23 23:29:00 by mo0ky            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <filler.h>

void			clear(t_filler *data)
{
	if (!data)
		return ;
	(data->map.map) ? ft_delete_double_tab(data->map.map) : 0;
	(data->piece.map) ? ft_delete_double_tab(data->piece.map) : 0;
	(data->direction) ? ft_memdel((void*)&data->direction) : 0;
	data->map.map = NULL;
	data->piece.map = NULL;
}

void			exit_prog(t_filler *data, char **line, int exit_flag)
{
	clear(data);
	(line && *line) ? ft_memdel((void*)line) : 0;
	//close(g_fd);
	exit(exit_flag);
}


int		main(void)
{
	char		*line;
	//int			fd;
	t_filler	data;
	int			ret;

	data.map.map = NULL;
	data.piece.map = NULL;
	data.coords = NULL;
	data.direction = NULL;
	//if ((g_fd = open("debug", O_WRONLY | O_TRUNC | O_CREAT, 0600)) == -1)
	//	return (0);
	while ((ret = get_next_line(0, &line)) > 0)
	{
		if (ft_strstr(line, "$$$ exec p") &&
				!set_player(line + 10, &data.player))
			exit_prog(&data, &line, EXIT_FAILURE);
		else if (ft_strstr(line, "Plateau ") &&
				!set_map(&line, &data.map))
			exit_prog(&data, &line, EXIT_FAILURE);
		else if (ft_strstr(line, "Piece "))
			set_piece(&line, &data.piece) ?
										place_piece(&data) :
										exit_prog(&data, &line, EXIT_FAILURE);
		(line) ? ft_memdel((void*)&line) : 0;
	}
	//while(1){};
	exit_prog(&data, &line, EXIT_SUCCESS);
}
