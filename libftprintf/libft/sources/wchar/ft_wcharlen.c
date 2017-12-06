/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wcharlen.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoucade <jmoucade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/15 23:30:58 by mo0ky             #+#    #+#             */
/*   Updated: 2017/10/01 20:55:25 by jmoucade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wchars.h>

char	ft_wcharlen(wchar_t c)
{
	if (MB_CUR_MAX == 1)
	{
		if (c >= 0 && c <= 0xFF)
			return (1);
		return (0);
	}
	else if (c >= 0 && c < 0x10FFFF)
	{
		if (c >= 0 && c <= 0x7F)
			return (1);
		else if (c >= 0x80 && c <= 0x7FF)
			return (2);
		else if ((c >= 0x800 && c <= 0xD7FF) || (c >= 0xE000 && c <= 0xFFFF))
			return (3);
		else if (c >= 0x10000 && c <= 0x10FFFF)
			return (4);
		else
			return (0);
	}
	else
		return (0);
}
