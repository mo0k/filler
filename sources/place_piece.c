/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   place_piece.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mo0ky <mo0ky@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/18 20:46:25 by mo0ky             #+#    #+#             */
/*   Updated: 2017/11/23 23:28:05 by mo0ky            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <filler.h>

int			is_place(t_filler *data, int x, int y)
{
	//ft_dprintf(2, "start is_place\n");
	int		x_piece;
	int		y_piece;
	t_map	*map;
	t_map	*piece;
	int count = 0;

	if (!data)
		return (0);
	y_piece = -1;
	map = &data->map;
	piece = &data->piece;
	if (map->height - y < piece->height || map->width - x < piece->width)
		return (0);
	while (piece->map[++y_piece])
	{
		x_piece = -1;
		while (piece->map[y_piece][++x_piece])
		{
			/*if ((piece->map[y_piece][x_piece] == '.' && 
				map->map[y + y_piece][x + x_piece] == '.') ||
				(piece->map[y_piece][x_piece] == '.' && 
				map->map[y + y_piece][x + x_piece] == data->player))
			{
				continue ;
			}*/
			if (piece->map[y_piece][x_piece] == '*' &&
				map->map[y + y_piece][x + x_piece] == data->player)
			{
				++count;
			}
			else if (piece->map[y_piece][x_piece] == '*' &&
				map->map[y + y_piece][x + x_piece] != data->player &&
				map->map[y + y_piece][x + x_piece] != '.')
				return (0);
			/*else if (piece->map[y_piece][x_piece] == '*' &&
				map->map[y + y_piece][x + x_piece] == '.')
			{
				continue;
			}*/
			//else
			//{
			//	return (0);
			//}
		}
	}
	return (count == 1 ? 1 : 0);
}

static int	calcul_distance(t_coord *coord, int x, int y)
{
	int		distance[2];

	distance[0] = coord->x - x;
	ft_dprintf(2, "coord->x:%d x:%d\n", coord->x, x);
	distance[1] = coord->y - y;
	ft_dprintf(2, "coord->y:%d y:%d\n", coord->y, y);
	distance[0] = ABS(distance[0]);
	distance[1] = ABS(distance[1]);
	return (distance[0] + distance[1]);
}
/*
static int	get_min_distance(t_map *map, t_coord *coord, char player)
{
	int		x;
	int		y;
	int		ret;
	int		temp;

	y = -1;
	ret = 0;
	ft_dprintf(2, "coord->x:%d coord->y:%d\n", coord->x, coord->y);
	while (map->map[++y])
	{
		x = -1;
		while (map->map[y][++x])
		{
			if (map->map[y][x] != '.' && map->map[y][x] != player)
			{
				temp = calcul_distance(coord, x, y);
				if (ret == 0 || ret < temp)
					ret = temp;
			}
			//else
				//ft_dprintf(2, "IMPOSSIBLE %d %d\n", y, x);
		}
	}
	return (ret);
}
*/

void			available_coord(t_filler *data)
{
	int			x;
	int			y;
	t_coord		coord;

	if (!data)
		return ;
	y = -1;
	while (data->map.map[++y])
	{
		x = -1;
		while (data->map.map[y][++x])
		{
			if (is_place(data, x, y))
			{
				coord.x = x;
				coord.y = y;
				ft_lstadd_end(&data->coords, ft_lstnew(&coord, sizeof(t_coord)));
			}
		}
	}
}

int			get_strategy(t_filler *data)
{
	if (!ft_strchr(data->map.map[data->map.height / 2], data->player))
	{
			ft_dprintf(2, "Strategy:CENTER\n");
		return (CENTER);
	}
	else if (data->map.map[0][data->map.width-1] == '.')
	{
		ft_dprintf(2, "Strategy:TOP_RIGHT\n");
		return (TOP_RIGHT);
	}
	else if (data->map.map[data->map.height - 1][data->map.width / 2] == '.')
	{
		ft_dprintf(2, "Strategy:BOTTOM\n");
		return (BOTTOM);
	}
	else if (data->map.map[data->map.height - 1][data->map.width - 1] == '.')
	{
		//ft_dprintf(2, "Strategy:RE CENTER\n");
		return (BOTTOM_RIGHT);
		return (-1);
	}
	else
		return (CENTER);
}
void		place_piece(t_filler *data)
{
	data->direction = get_tab_direction(data->map.height, data->map.width);
	available_coord(data);
	if (data->coords)
	{
		t_list *coords;
		t_list *select;
		int distance = 0;
		int temp = 0;
		int choix = 0;
		coords = data->coords;
		while (coords)
		{
			choix = get_strategy(data);
			temp = calcul_distance(coords->content, data->direction[choix].x,
													data->direction[choix].y);
			ft_dprintf(2, "temp:%d\tdistance:%d\n", temp, distance);
			distance = (distance == 0 || temp <= distance) ? temp : distance;
			(distance == temp) ? (select = coords) : 0;
			coords = coords->next;
		}
		ft_lstiter(data->coords, &print_coord);

		ft_dprintf(2, "%d %d\n", ((t_coord*)(select->content))->y, ((t_coord*)(select->content))->x);
		ft_printf("%d %d\n", ((t_coord*)(select->content))->y, ((t_coord*)(select->content))->x);
		while (data->coords)
			ft_lstdelfirst(&data->coords, &del_coord);
	}
	else
		ft_printf("0 0\n");
	clear(data);
}