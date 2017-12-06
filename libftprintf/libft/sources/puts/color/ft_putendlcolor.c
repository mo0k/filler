/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendlcolor.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoucade <jmoucade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/15 23:41:12 by mo0ky             #+#    #+#             */
/*   Updated: 2017/07/11 19:56:35 by jmoucade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendlcolor(char const *s, char *color)
{
	if (!s)
		return ;
	ft_putstr(color);
	write(1, s, ft_strlen(s));
	ft_putstr(C_DFL);
	ft_putchar('\n');
}
