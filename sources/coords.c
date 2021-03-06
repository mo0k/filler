/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coords.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoucade <jmoucade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 23:27:55 by mo0ky             #+#    #+#             */
/*   Updated: 2017/12/06 14:55:18 by jmoucade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <filler.h>

static t_coord	init_coord(int x, int y)
{
	t_coord		new;

	new.x = x;
	new.y = y;
	return (new);
}

t_coord			*get_tab_direction(int height, int width)
{
	t_coord		*direction;

	if (!(direction = (t_coord*)malloc(sizeof(t_coord) * NBR_DIRECTION)))
		return (NULL);
	direction[TOP] = init_coord(width / 2, 0);
	direction[BOTTOM] = init_coord(width / 2, height);
	direction[LEFT] = init_coord(0, height / 2);
	direction[RIGHT] = init_coord(width, height / 2);
	direction[CENTER] = init_coord(width / 2, height / 2);
	direction[TOP_LEFT] = init_coord(0, 0);
	direction[TOP_RIGHT] = init_coord(width, 0);
	direction[BOTTOM_LEFT] = init_coord(0, height);
	direction[BOTTOM_RIGHT] = init_coord(width, height);
	return (direction);
}

void			del_coord(void *elem, size_t size)
{
	(void)size;
	if (!elem)
		return ;
	free(elem);
	elem = NULL;
}
