/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_screen.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoucade <jmoucade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 23:44:25 by mo0ky             #+#    #+#             */
/*   Updated: 2017/12/06 15:46:16 by jmoucade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <win.h>
#include <ncurses.h>
#include <libft.h>

void			update_screen(t_win *w, int y_start, int x_start, char *line)
{
	char c;

	if (!line || !w)
		return ;
	while (*line)
	{
		if ((c = (A_CHARTEXT & mvwinch(w->window, y_start, x_start))) == *line)
			continue ;
		else if (*line == 'O' || *line == 'o')
		{
			wattron(w->window, COLOR_PAIR(P1));
			mvwaddch(w->window, y_start, x_start, *line);
			wattroff(w->window, COLOR_PAIR(P1));
		}
		else if (*line == 'X' || *line == 'x')
		{
			wattron(w->window, COLOR_PAIR(P2));
			mvwaddch(w->window, y_start, x_start, *line);
			wattroff(w->window, COLOR_PAIR(P2));
		}
		else
			mvwaddch(w->window, y_start, x_start, ' ');
		++x_start;
		++line;
	}
}
