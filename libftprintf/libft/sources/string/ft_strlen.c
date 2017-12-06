/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mo0ky <mo0ky@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 14:41:38 by jmoucade          #+#    #+#             */
/*   Updated: 2017/11/13 14:22:07 by mo0ky            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlen(const char *str)
{
	char	*cur;

	if (!str)
		return (0);
	cur = (char *)str;
	while (1)
	{
		if (!*(cur++))
			break ;
		if (!*(cur++))
			break ;
		if (!*(cur++))
			break ;
		if (!*(cur++))
			break ;
		if (!*(cur++))
			break ;
		if (!*(cur++))
			break ;
		if (!*(cur++))
			break ;
		if (!*(cur++))
			break ;
	}
	return (cur - str - 1);
}
