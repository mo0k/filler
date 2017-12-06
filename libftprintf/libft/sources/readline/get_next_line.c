/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoucade <jmoucade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/26 06:38:16 by jmoucade          #+#    #+#             */
/*   Updated: 2017/12/05 20:42:02 by jmoucade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <get_next_line.h>

static t_file	*check_fd(int fd, t_file **f)
{
	char			*buff;
	t_file			*new;

	buff = NULL;
	if (fd < 0 || read(fd, buff, 0) == -1)
		return (NULL);
	if (!*f)
	{
		if (!(new = (t_file*)malloc(sizeof(t_file))))
			return (NULL);
		new->fd = fd;
		new->data = ft_strnew(BUFF_SIZE);
		new->next = NULL;
		*f = new;
		return (new);
	}
	new = *f;
	if (!new)
		return (NULL);
	if (new->fd == fd)
		return (new);
	return (check_fd(fd, &new->next));
}

static int		buff(char *buff, char **line)
{
	int				i;
	int				begin;
	char			*sub;
	char			*tmp_line;

	i = -1;
	begin = 0;
	while (++i < BUFF_SIZE && *(buff) != '\n')
		if (*(buff++) == '\0' && *(buff))
			begin = i + 1;
	sub = ft_strsub(buff - i, begin, i - begin);
	tmp_line = *line;
	*line = ft_strjoin(tmp_line, sub);
	ft_strdel(&tmp_line);
	ft_strdel(&sub);
	if (*buff == '\n')
	{
		ft_bzero(buff - i, i + 1);
		return (1);
	}
	if (line && *line && **line == '\0')
		ft_strdel(line);
	ft_bzero(buff - i, BUFF_SIZE);
	return (0);
}

int				get_next_line(const int fd, char **line)
{
	static t_file	*f;
	t_file			*tmp;
	int				ret;

	if (!line)
		return (-1);
	*line = NULL;
	if (BUFF_SIZE < 0)
		return (-1);
	if (!(tmp = check_fd(fd, &f)))
		return (ERROR);
	if (buff(f->data, line) == 1)
		return (1);
	while ((ret = read(f->fd, f->data, BUFF_SIZE)) > 0)
	{
		if (buff(f->data, line) == 1)
			return (1);
	}
	if (ret < 0)
		return (-1);
	if (*line != NULL)
		return (1);
	return (0);
}
