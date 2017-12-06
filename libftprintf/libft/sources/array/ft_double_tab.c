/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_double_tab.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoucade <jmoucade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/24 10:45:53 by mo0ky             #+#    #+#             */
/*   Updated: 2017/12/05 20:42:45 by jmoucade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <stdio.h>

void			ft_print_double_tab(char **tab)
{
	if (!tab)
		return ;
	while (*tab)
	{
		write(1, *tab, ft_strlen(*tab));
		++tab;
	}
}

char			**ft_get_double_tab(int height, int width)
{
	char	**tab;
	int		i;

	i = -1;
	if (!(tab = (char**)malloc(sizeof(char*) * (height + 1))))
		return (NULL);
	tab[height] = NULL;
	while (++i < height)
	{
		if (!(tab[i] = (char*)malloc(sizeof(char) * (width + 1))))
		{
			ft_delete_double_tab(tab);
			return (NULL);
		}
		tab[i][width] = 0;
	}
	return (tab);
}

void			ft_delete_double_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab && tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
	tab = NULL;
}
