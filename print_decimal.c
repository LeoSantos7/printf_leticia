/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_decimal.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lesantos <lesantos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 12:12:59 by lesantos          #+#    #+#             */
/*   Updated: 2022/01/23 14:58:34 by lesantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	adjust_precision_width(long int n, t_flags *flags)
{
	int	n_digits_count;

	n_digits_count = count_digits(ft_abs(n), BASE_10);
	if (flags->precision > 0 && n != 0)
		flags->precision -= n_digits_count;
	if (flags->precision != 0 || n != 0)
		flags->width -= n_digits_count;
	flags->width -= (n < 0 || flags->plus || flags->space);
	if (flags->precision > 0)
		flags->width -= flags->precision;
}

int	print_decimal_digits(long int n, t_flags *flags)
{
	unsigned int		base;
	unsigned long int	divisor;
	int					print_count;

	if (flags->precision >= 0 && n == 0)
		return (0);
	base = 10;
	divisor = get_first_digit_divisor(n, base);
	print_count = 0;
	while (divisor >= base)
	{
		print_count += write(1, "0123456789" + n / divisor, 1);
		n %= divisor;
		divisor /= base;
	}
	print_count += write(1, "0123456789" + n, 1);
	return (print_count);
}

int	print_decimal(long int n, t_flags *flags)
{
	int	print_count;

	adjust_precision_width(n, flags);
	print_count = 0;
	print_count += print_spaces(flags, PADDING_LEFT);
	print_count += print_prefix(n, flags);
	print_count += print_zeroes(flags);
	print_count += print_decimal_digits(ft_abs(n), flags);
	print_count += print_spaces(flags, PADDING_RIGHT);
	return (print_count);
}
