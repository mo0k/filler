/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mo0ky <mo0ky@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 14:49:03 by jmoucade          #+#    #+#             */
/*   Updated: 2017/11/19 17:02:39 by mo0ky            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strstr(const char *s1, const char *s2)
{
	int		i;
	int		j;

	i = -1;
	if (!s1 || !s2)
		return (NULL);
	while (s1[++i] || !*s2)
	{
		j = 0;
		while (s1[i + j] == s2[j] && s1[i + j])
		{
			j++;
		}
		if (!s2[j])
			return ((char *)s1 + i);
	}
	return (NULL);
}
