/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_player.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mo0ky <mo0ky@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 21:53:58 by mo0ky             #+#    #+#             */
/*   Updated: 2017/11/23 23:31:25 by mo0ky            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <filler.h>

int		set_player(char *ptr, char *addr_player)
{
	if (!addr_player || !ptr)
		return (0);
	if (*ptr == '1')
		player = 'O';
	else if (*ptr == '2')
		player = 'X';
	else
		return (0);
	*addr_player = player;
	ft_dprintf(2, "Player loaded(%c)\n", *addr_player);
	return (1);
}
