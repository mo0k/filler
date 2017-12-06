/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_player.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoucade <jmoucade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 21:53:58 by mo0ky             #+#    #+#             */
/*   Updated: 2017/12/06 14:57:25 by jmoucade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <filler.h>

int		set_player(char *ptr, char *addr_player)
{
	if (!addr_player || !ptr)
		return (0);
	if (*ptr == '1')
		*addr_player = 'O';
	else if (*ptr == '2')
		*addr_player = 'X';
	else
		return (0);
	return (1);
}
