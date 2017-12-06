/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   place_piece.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoucade <jmoucade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/18 20:46:25 by mo0ky             #+#    #+#             */
/*   Updated: 2017/12/06 15:17:38 by jmoucade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <filler.h>

static int			is_place(t_filler *d, int x, int y)
{
	int			x_piece;
	int			y_piece;
	int			count;

	if (!d || (d->map.height - y < d->piece.height ||
					d->map.width - x < d->piece.width))
		return (0);
	y_piece = -1;
	count = 0;
	while (d->piece.map[++y_piece])
	{
		x_piece = -1;
		while (d->piece.map[y_piece][++x_piece])
		{
			if (d->piece.map[y_piece][x_piece] == '*' &&
					d->map.map[y + y_piece][x + x_piece] == d->player)
				++count;
			else if (d->piece.map[y_piece][x_piece] == '*' &&
				d->map.map[y + y_piece][x + x_piece] != d->player &&
				d->map.map[y + y_piece][x + x_piece] != '.')
				return (0);
		}
	}
	return (count == 1 ? 1 : 0);
}

static int			calcul_distance(t_coord *coord, int x, int y)
{
	int			distance[2];

	if (!coord)
		return (0);
	distance[0] = coord->x - x;
	distance[1] = coord->y - y;
	distance[0] = ABS(distance[0]);
	distance[1] = ABS(distance[1]);
	return (distance[0] + distance[1]);
}

static void			available_coord(t_filler *d)
{
	int			x;
	int			y;
	t_coord		coord;

	if (!d)
		return ;
	y = -1;
	while (d->map.map[++y])
	{
		x = -1;
		while (d->map.map[y][++x])
		{
			if (is_place(d, x, y))
			{
				coord.x = x;
				coord.y = y;
				ft_lstadd_end(&d->coords, ft_lstnew(&coord, sizeof(t_coord)));
			}
		}
	}
}

void				do_place(t_filler *data, t_list *coords)
{
	t_list		*select;
	int			distance;
	int			temp;
	int			choix;

	distance = 0;
	temp = 0;
	choix = 0;
	while (coords)
	{
		choix = get_strategy(data);
		temp = calcul_distance(coords->content, data->direction[choix].x,
												data->direction[choix].y);
		distance = (distance == 0 || temp <= distance) ? temp : distance;
		(distance == temp) ? (select = coords) : 0;
		coords = coords->next;
	}
	ft_printf("%d %d\n", ((t_coord*)(select->content))->y, \
											((t_coord*)(select->content))->x);
	while (data->coords)
		ft_lstdelfirst(&data->coords, &del_coord);
	clear(data);
}

void				place_piece(t_filler *data)
{
	t_list		*coords;

	data->direction = get_tab_direction(data->map.height, data->map.width);
	available_coord(data);
	coords = data->coords;
	coords ? do_place(data, coords) : ft_printf("0 0\n");
}
