/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putcharcolor.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoucade <jmoucade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/15 23:41:50 by mo0ky             #+#    #+#             */
/*   Updated: 2017/07/11 19:56:45 by jmoucade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	ft_putcharcolor(char c, char *color)
{
	ft_putstr(color);
	write(1, (unsigned char *)(&c), 1);
	ft_putstr(C_DFL);
}
