/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mo0ky <mo0ky@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/26 06:38:24 by jmoucade          #+#    #+#             */
/*   Updated: 2017/11/20 13:47:04 by mo0ky            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <fcntl.h>
# include <libft.h>
# include <stdlib.h>

# define ERROR 		-1
# define END_OF_FILE 0
# define EOL 1

# define BUFF_SIZE 256

typedef struct		s_file
{
	int				fd;
	char			*data;
	int				eof;
	struct s_file	*next;
}					t_file;

int					get_next_line(const int fd, char **line);
int					gnl(int const fd, char **line);

#endif
