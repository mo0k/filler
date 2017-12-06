/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   puts.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoucade <jmoucade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/30 00:20:05 by mo0ky             #+#    #+#             */
/*   Updated: 2017/10/01 18:22:44 by jmoucade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUTS_H
# define PUTS_H

# include <unistd.h>

void		ft_putchar(char c);
void		ft_putstr(const char *str);
void		ft_putendl(char const *s);
void		ft_putnbr(int nb);
void		ft_putchar_fd(char c, int fd);
void		ft_putstr_fd(char const *s, int fd);
void		ft_putendl_fd(char const *s, int fd);
void		ft_putnbr_fd(int n, int fd);
void		ft_putnbr_base(int nbr, char *base);
void		ft_putstrtab(char **tab);
void		ft_putcharcolor(char c, char *color);
void		ft_putstrcolor(const char *str, char *color);
void		ft_putendlcolor(char const *s, char *color);
void		ft_putnbrcolor(int nb, char *color);
void		ft_putcharcolor_fd(char c, int fd, char *color);
void		ft_putstrcolor_fd(char const *s, int fd, char *color);
void		ft_putendlcolor_fd(char const *s, int fd, char *color);
void		ft_putnbrcolor_fd(int n, int fd, char *color);

#endif
