/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mo0ky <mo0ky@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 14:34:43 by jmoucade          #+#    #+#             */
/*   Updated: 2017/03/16 00:06:38 by mo0ky            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_putnbr_fd(int n, int fd)
{
	long	l_n;
	long	d;

	l_n = (long)n;
	d = 1;
	if (l_n == 0)
	{
		ft_putchar_fd('0', fd);
		return ;
	}
	if (l_n < 0)
	{
		l_n *= -1;
		ft_putchar_fd('-', fd);
	}
	while (l_n / d)
		d *= 10;
	while (d - 1)
	{
		ft_putchar_fd((l_n - (l_n / d * d)) / (d / 10) + 48, fd);
		d /= 10;
	}
}
