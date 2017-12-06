/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filln_buffer.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoucade <jmoucade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/30 23:59:17 by mo0ky             #+#    #+#             */
/*   Updated: 2017/10/01 20:06:29 by jmoucade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <buffer_controler.h>

static int		filln_buffer(t_buffer_static *ctrl, void *c, size_t n)
{
	int		i;

	if (!ctrl || !c)
		return (0);
	i = -1;
	while (++i < (int)n)
		ft_memmove(ctrl->buffer + ctrl->used_size + i, c, 1);
	ctrl->remaining_size -= n;
	ctrl->used_size += n;
	ctrl->buffer[ctrl->used_size] = 0;
	return (1);
}

int				filln_buffer_static(t_buffer_static *ctrl, void *c, size_t n)
{
	if (!ctrl)
		return (0);
	return (available_space(n, ctrl->remaining_size) ?
			filln_buffer(ctrl, c, n) : 0);
}
