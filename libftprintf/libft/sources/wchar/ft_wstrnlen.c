/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wstrnlen.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoucade <jmoucade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/24 20:55:24 by mo0ky             #+#    #+#             */
/*   Updated: 2017/10/01 20:56:30 by jmoucade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wchars.h>

int		ft_wstrnlen(wchar_t *str, int n)
{
	int		wstrlen;
	int		wcharlen;

	wstrlen = 0;
	if (n <= 0)
		return (0);
	while (*str)
	{
		if (!(wcharlen = ft_wcharlen(*str)))
			return (wstrlen * -1);
		if (wstrlen + wcharlen > (int)n)
			return (wstrlen);
		wstrlen += wcharlen;
		++str;
	}
	return ((!wstrlen)) ? 1 : wstrlen;
}
