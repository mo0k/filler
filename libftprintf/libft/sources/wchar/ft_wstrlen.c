/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wstrlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoucade <jmoucade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/15 23:30:58 by mo0ky             #+#    #+#             */
/*   Updated: 2017/10/01 20:56:06 by jmoucade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wchars.h>

int		ft_wstrlen(wchar_t *str)
{
	int		wstrlen;
	int		wcharlen;

	wstrlen = 0;
	while (*str)
	{
		if (!(wcharlen = ft_wcharlen(*str)))
			return (wstrlen * -1);
		wstrlen += wcharlen;
		++str;
	}
	return ((!wstrlen)) ? 1 : wstrlen;
}
