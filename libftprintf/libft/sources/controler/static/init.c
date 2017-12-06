/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoucade <jmoucade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/30 23:59:17 by mo0ky             #+#    #+#             */
/*   Updated: 2017/10/01 20:03:28 by jmoucade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <buffer_controler.h>

void			init_buffer_static(t_buffer_static *controler)
{
	controler->current = controler->buffer;
	controler->buff_size = BUFF_SIZE_INIT;
	controler->remaining_size = BUFF_SIZE_INIT;
	controler->used_size = 0;
}
