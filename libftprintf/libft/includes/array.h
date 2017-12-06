/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoucade <jmoucade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/30 00:18:14 by mo0ky             #+#    #+#             */
/*   Updated: 2017/12/05 20:42:15 by jmoucade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_H
# define ARRAY_H

# include <stdlib.h>

int			*ft_range(int min, int max);
void		ft_foreach(int *tab, int length, void (*f)(int));
int			ft_count_if(char **tab, int (*f)(char*));
char		**ft_get_double_tab(int height, int width);
void		ft_print_double_tab(char **tab);
void		ft_delete_double_tab(char **tab);
char		***ft_get_triple_tab(int line, int columm, int len);
void		ft_print_triple_tab(char ***tab);
void		ft_delete_triple_tab(char ***tab);

#endif
