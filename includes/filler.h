/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mo0ky <mo0ky@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 21:03:14 by mo0ky             #+#    #+#             */
/*   Updated: 2017/11/23 23:59:07 by mo0ky            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include <ft_printf.h>
# include <libft.h>
# include <fcntl.h>

# define NBR_DIRECTION 9

enum 	e_direction
{
	TOP,
	BOTTOM,
	LEFT,
	RIGHT,
	CENTER,
	TOP_LEFT,
	TOP_RIGHT,
	BOTTOM_LEFT,
	BOTTOM_RIGHT
};
typedef struct 	s_coord
{
	int		x;
	int		y;
}				t_coord;

typedef struct	s_map
{
	char		**map;
	int			height;
	int			width;
}				t_map;

typedef struct	s_filler
{
	t_map		map;
	t_map		piece;
	t_list		*coords;
	t_coord		*direction;
	char		player;
}				t_filler;

int				g_fd;

void			exit_prog(t_filler *data, char **line, int exit_flag);
int				set_player(char *ptr, char *addr_char);
int				set_map(char **line, t_map *map);
int				set_piece(char **line, t_map *piece);
int				get_number(char *ptr);
void			place_piece(t_filler *data);

t_coord			*get_tab_direction(int height, int width);
void			print_coord(t_list *elem);
void			del_coord(void *elem, size_t size);

void			clear(t_filler *data);

#endif
