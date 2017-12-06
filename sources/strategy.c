/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strategy.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoucade <jmoucade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 14:43:27 by jmoucade          #+#    #+#             */
/*   Updated: 2017/12/06 15:00:36 by jmoucade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <filler.h>

int					strategy_1(t_filler *data)
{
	if (!ft_strchr(data->map.map[data->map.height / 2], data->player))
		return (CENTER);
	else if (data->map.map[0][data->map.width - 1] == '.')
		return (TOP_RIGHT);
	else if (data->map.map[data->map.height - 1][data->map.width / 2] == '.')
		return (BOTTOM);
	else if (data->map.map[data->map.height - 1][data->map.width - 1] == '.')
		return (BOTTOM_RIGHT);
	else
		return (CENTER);
}

int					strategy_2(t_filler *data)
{
	if (!ft_strchr(data->map.map[data->map.height / 2], data->player))
		return (CENTER);
	else if (data->map.map[data->map.height - 1][0] == '.')
		return (BOTTOM_LEFT);
	else if (data->map.map[0][data->map.width - 1] == '.')
		return (TOP_RIGHT);
	else
		return (CENTER);
}

int					strategy_3(t_filler *data)
{
	if (!ft_strchr(data->map.map[data->map.height / 2], data->player))
		return (CENTER);
	else if (data->map.map[0][data->map.width - 1] == '.')
		return (TOP_RIGHT);
	else if (data->map.map[data->map.height - 1][0] == '.')
		return (BOTTOM_LEFT);
	else
		return (CENTER);
}

int					strategy_4(t_filler *data)
{
	if (data->map.map[data->map.height - 1][0] == '.')
		return (BOTTOM_LEFT);
	else if (data->map.map[data->map.height / 2][0] == '.')
		return (TOP_LEFT);
	else if (data->map.map[0][data->map.width / 2] == '.')
		return (TOP);
	else
		return (CENTER);
}

int					get_strategy(t_filler *data)
{
	static int				i = 0;
	static t_strategy_func	strategy_func = NULL;

	if (i++ == 0)
		if (!(strategy_func = define_strategy(data)))
			return (CENTER);
	return (strategy_func ? strategy_func(data) : 0);
}
