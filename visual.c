/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visual.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mo0ky <mo0ky@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 23:44:25 by mo0ky             #+#    #+#             */
/*   Updated: 2017/11/29 21:58:49 by mo0ky            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <visual.h>
#include <win.h>
#include <ncurses.h>
#include <libft.h>

enum e_pairs{
	WIN = 1,
	P1,
	P2
};

void			init_visual()
{
	int		y_max;
	int		x_max;

	initscr();
	curs_set(0);
	if (!has_colors())
		exit(write(1, "No color\n", ft_strlen("No color\n")));
	start_color();
	init_pair(WIN, COLOR_WHITE, COLOR_WHITE);
	init_pair(P1, COLOR_GREEN, COLOR_GREEN);
	init_pair(P2, COLOR_RED, COLOR_RED);
	getmaxyx(stdscr, y_max, x_max);

	int tmp = x_max / 2 - 5;
	mvprintw(0, tmp, "P1:");
	attron(COLOR_PAIR(2));
	mvprintw(0, tmp + 3, " ");
	attroff(COLOR_PAIR(2));
	mvprintw(0, tmp + 5, "P2:");
	attron(COLOR_PAIR(3));
	mvprintw(0, tmp + 8, " ");
	attroff(COLOR_PAIR(3));
	refresh();
}

void			update_screen(t_win *win, int y_start, int x_start, char *line)
{
	char c;

	if (!line || !win)
		return ;
	while (*line)
	{
		if ((c = (A_CHARTEXT & mvwinch(win->window, y_start, x_start))) == *line)
			continue ;
		else if (*line == 'O' || *line == 'o')
		{
			wattron(win->window, COLOR_PAIR(P1));
			mvwaddch(win->window, y_start, x_start, *line);
			wattroff(win->window, COLOR_PAIR(P1));
		}
		else if (*line == 'X' || *line == 'x')
		{
			wattron(win->window, COLOR_PAIR(P2));
			mvwaddch(win->window, y_start, x_start, *line);
			wattroff(win->window, COLOR_PAIR(P2));
		}
		else
			mvwaddch(win->window, y_start, x_start, ' ');
		++x_start;
		++line;
	
	}
	//sleep(1);
}

int				get_number(char *ptr)
{
	int		number;
	int 	i;

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

void			visual(char **line)
{
	t_win 	win;
	int		y_max;
	int		x_max;
	char 	*ptr;
	int 	i;
	char *start;
	i = -1;
	getmaxyx(stdscr, y_max, x_max);
	ptr = *line;
	ptr += 8;
	if ((win.height = get_number(ptr)) < 0)
		return ;
	if ((win.width = get_number(ptr + ft_nbrlen(win.height) + 1)) < 0)
		return ;
	if (win.height > y_max - 1 || win.width > x_max)
		return ;
	(line && *line) ? ft_memdel((void*)line) : 0;
	get_next_line(0, line);
	(line && *line) ? ft_memdel((void*)line) : 0;
	if (!initialize_window(&win, win.height + 2, win.width + 2))
		return ;
	if (!create_window(&win, x_max / 2 - 1 - win.width / 2, 1, COLOR_PAIR(WIN)))
		return ;
	while (++i < win.height - 2)
	{
		if (get_next_line(0, line) > 0)
		{
			if (!((start = ft_strchr(*line, ' ')) ? ++start : 0))
				return ;
			if ((int)ft_strlen(start) != win.width - 2)
				return ;
			update_screen(&win, i + 1, 1, start);
			(line && *line) ? ft_memdel((void*)line) : 0;
		}
	}
			wrefresh(win.window);
			sleep(1);
}

int 	main(void)
{
	char *line;

	line = NULL;
	init_visual();
	sleep(1);
	while (get_next_line(0, &line) > 0)
	{
		//mvprintw(0, 0, "line:%s", line);
		//refresh();
		//sleep(2);
		if (ft_strstr(line, "Plateau "))
		{
			visual(&line);
		}
		(line) ? ft_memdel((void*)&line) : 0;
	}
	sleep(5);
	endwin();
	return (1);
}
