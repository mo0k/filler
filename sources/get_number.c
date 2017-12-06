/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_number.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoucade <jmoucade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 21:53:58 by mo0ky             #+#    #+#             */
/*   Updated: 2017/12/06 14:56:19 by jmoucade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <filler.h>

int				get_number(char *ptr)
{
	int		number;
	int		i;

	if (!ptr)
		return (-1);
	i = 0;
	while (ft_isdigit(ptr[i]))
		i++;
	if (i == 0)
		return (-1);
	ptr[i] = 0;
	number = ft_atoi(ptr);
	ptr[i] = ' ';
	return (number);
}
