/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_formatting.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lesantos <lesantos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 09:49:20 by lesantos          #+#    #+#             */
/*   Updated: 2022/01/23 18:55:58 by lesantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_spaces(t_flags *flags, int left_side)
{
	if (left_side && !flags->minus && (flags->precision >= 0 || !flags->zero))
		return (print_char_count(' ', flags->width));
	if (!left_side && flags->minus)
		return (print_char_count(' ', flags->width));
	return (0);
}

int	print_prefix(long int n, t_flags *flags)
{
	if (flags->type == 'x' && n != 0 && flags->alternate)
		return (write(1, "0x", 2));
	if (flags->type == 'p' && n != 0)
		return (write(1, "0x", 2));
	if (flags->type == 'X' && n != 0 && flags->alternate)
		return (write(1, "0X", 2));
	if ((flags->type == 'd' || flags->type == 'i') && n < 0)
		return (write(1, "-", 1));
	if ((flags->type == 'd' || flags->type == 'i') && flags->plus)
		return (write(1, "+", 1));
	if ((flags->type == 'd' || flags->type == 'i') && flags->space)
		return (write(1, " ", 1));
	return (0);
}

int	print_zeroes(t_flags *flags)
{
	if (flags->precision > 0)
		return (print_char_count('0', flags->precision));
	if (!flags->minus && flags->zero)
		return (print_char_count('0', flags->width));
	return (0);
}
