/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define_strategy.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoucade <jmoucade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 14:49:18 by jmoucade          #+#    #+#             */
/*   Updated: 2017/12/06 14:55:37 by jmoucade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <filler.h>

static t_coord		find_start(char **map, char player)
{
	int			x;
	int			y;
	t_coord		coord;

	y = 0;
	coord.x = 0;
	coord.y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == player)
			{
				coord.x = x;
				coord.y = y;
				return (coord);
			}
			++x;
		}
		++y;
	}
	return (coord);
}

t_strategy_func		define_strategy(t_filler *data)
{
	t_coord		coord;

	if (!data)
		return (NULL);
	coord = find_start(data->map.map, data->player);
	if (coord.x <= data->map.width / 2 && coord.y <= data->map.height / 2)
		return (&strategy_1);
	else if (coord.x > data->map.width / 2 && coord.y <= data->map.height / 2)
		return (&strategy_2);
	else if (coord.x <= data->map.width / 2 && coord.y > data->map.height / 2)
		return (&strategy_3);
	else
		return (&strategy_4);
}
