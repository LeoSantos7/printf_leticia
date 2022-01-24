/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lesantos <lesantos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 12:16:22 by lesantos          #+#    #+#             */
/*   Updated: 2022/01/23 18:56:21 by lesantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	adjust_precision_width(unsigned long n, t_flags *flags)
{
	int	n_digits_count;

	n_digits_count = count_digits(n, BASE_16);
	if (flags->precision > 0 && n != 0)
		flags->precision -= n_digits_count;
	if (flags->precision != 0 || n != 0)
		flags->width -= n_digits_count;
	if (flags->type == 'p' || (flags->alternate && n != 0))
		flags->width -= 2;
	if (flags->precision > 0)
		flags->width -= flags->precision;
}

int	print_hex_digits(unsigned long n, t_flags *flags)
{
	unsigned int		base;
	unsigned long int	divisor;
	int					print_count;
	char				*hex_digits;

	if (flags->precision >= 0 && n == 0)
		return (0);
	base = 16;
	divisor = get_first_digit_divisor(n, base);
	print_count = 0;
	hex_digits = "0123456789abcdef";
	if (flags->type == 'X')
		hex_digits = "0123456789ABCDEF";
	while (divisor >= base)
	{
		print_count += write(1, hex_digits + n / divisor, 1);
		n %= divisor;
		divisor /= base;
	}
	print_count += write(1, hex_digits + n, 1);
	return (print_count);
}

int	print_hex(unsigned long n, t_flags *flags)
{
	int	print_count;

	adjust_precision_width(n, flags);
	print_count = 0;
	print_count += print_spaces(flags, PADDING_LEFT);
	print_count += print_prefix(n, flags);
	print_count += print_zeroes(flags);
	print_count += print_hex_digits(n, flags);
	print_count += print_spaces(flags, PADDING_RIGHT);
	return (print_count);
}
