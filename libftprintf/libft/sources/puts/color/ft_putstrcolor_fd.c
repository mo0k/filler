/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstrcolor_fd.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoucade <jmoucade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/15 23:40:15 by mo0ky             #+#    #+#             */
/*   Updated: 2017/07/11 19:56:04 by jmoucade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstrcolor_fd(char const *s, int fd, char *color)
{
	if (!s || fd < 0)
		return ;
	ft_putstr_fd(color, fd);
	write(fd, s, ft_strlen(s));
	ft_putstr_fd(C_DFL, fd);
}
