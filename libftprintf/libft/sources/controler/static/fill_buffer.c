/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_buffer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoucade <jmoucade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/30 23:59:17 by mo0ky             #+#    #+#             */
/*   Updated: 2017/10/01 20:05:21 by jmoucade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <buffer_controler.h>

static int		fill_buffer(t_buffer_static *ctrl, void *input, size_t size)
{
	if (!ctrl || !input)
		return (0);
	ft_memmove(ctrl->buffer + ctrl->used_size, input, size);
	ctrl->remaining_size -= size;
	ctrl->used_size += size;
	ctrl->buffer[ctrl->used_size] = 0;
	return (1);
}

int				fill_buffer_static(t_buffer_static *ctrl, void *input,
																size_t size)
{
	if (!ctrl || !input)
		return (0);
	return (available_space(size, ctrl->remaining_size) ?
										fill_buffer(ctrl, input, size) : 0);
}
