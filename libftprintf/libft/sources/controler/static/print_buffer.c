/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_buffer.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoucade <jmoucade@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/30 23:59:17 by mo0ky             #+#    #+#             */
/*   Updated: 2017/10/01 20:06:49 by jmoucade         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <buffer_controler.h>

void			print_buffer_static(t_buffer_static *controler)
{
	ft_putstrcolor("+--------------------------+static\n", C_YELLOW);
	ft_putstrcolor("| ", C_YELLOW);
	ft_putstrcolor("controler->buffer:", C_GREEN);
	ft_putendl(controler->buffer);
	ft_putstrcolor("| ", C_YELLOW);
	ft_putstrcolor("controler->buff_size:", C_GREEN);
	ft_putnbr((int)controler->buff_size);
	write(1, "\n", 1);
	ft_putstrcolor("| ", C_YELLOW);
	ft_putstrcolor("controler->used_size:", C_GREEN);
	ft_putnbr(controler->used_size);
	write(1, "\n", 1);
	ft_putstrcolor("| ", C_YELLOW);
	ft_putstrcolor("controler->remaining_size:", C_GREEN);
	ft_putnbr((int)controler->remaining_size);
	write(1, "\n", 1);
	ft_putstrcolor("+--------------------------+\n", C_YELLOW);
}
