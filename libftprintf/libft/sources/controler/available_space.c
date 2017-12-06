/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   available_space.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mo0ky <mo0ky@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/31 00:01:40 by mo0ky             #+#    #+#             */
/*   Updated: 2017/07/31 00:24:22 by mo0ky            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <buffer_controler.h>

int		available_space(size_t new_size, size_t remaining_size)
{
	return ((new_size <= remaining_size) ? 1 : 0);
}
