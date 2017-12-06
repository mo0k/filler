/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mo0ky <mo0ky@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/30 00:20:24 by mo0ky             #+#    #+#             */
/*   Updated: 2017/09/24 23:05:06 by mo0ky            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRING_H
# define STRING_H

# include <stdlib.h>

size_t		ft_strlen(const char *str);
char		*ft_strdup(const char *src);
char		*ft_strcpy(char *dest, const char *src);
char		*ft_strncpy(char *dest, const char *src, size_t n);
char		*ft_strcat(char *dest, const char *src);
char		*ft_strncat(char *dest, const char *src, int nb);
size_t		ft_strlcat(char *dest, const char *src, unsigned int size);
char		*ft_strchr(const char *s, int c);
char		*ft_strrchr(const char *s, int c);
char		*ft_strstr(const char *str, const char *to_find);
char		*ft_strnstr(const char *str, const char *to_find, size_t len);
int			ft_strcmp(const char *s1, const char *s2);
int			ft_strncmp(const char *s1, const char *s2, unsigned int n);
char		*ft_strnew(size_t size);
void		ft_strdel(char **as);
void		ft_strdelnew(char **addr, char *value);
void		ft_strclr(char *s);
void		ft_striter(char *s, void (*f)(char *));
void		ft_striteri(char *s, void (*f)(unsigned int, char *));
char		*ft_strmap(char const *s, char (*f)(char));
char		*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int			ft_strequ(char const *s1, char const *s2);
int			ft_strnequ(char const *s1, char const *s2, size_t n);
char		*ft_strsub(char const *s, unsigned int start, size_t len);
char		*ft_strjoin(char const *s1, char const *s2);
char		*ft_strtrim(char const *s);
char		**ft_strsplit(char const *s, char c);
int			ft_stracat(char **dst, char *src);
int			ft_straddc(char **dst, char c);
int			ft_strpadding_right(char **str, int len_max);
int			ft_strpadding_left(char **str, int len_max);
char		*ft_str3join(char const *s1, char const *s2, char const *s3);
char		*ft_strtoupper(char *str);

#endif
