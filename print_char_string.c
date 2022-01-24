/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_char_string.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lesantos <lesantos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 20:27:12 by lesantos          #+#    #+#             */
/*   Updated: 2022/01/23 18:49:34 by lesantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_char(va_list ap, t_flags *flags)
{
	int	c;
	int	print;

	print = 0;
	c = va_arg(ap, int);
	if (!flags->minus && flags->width > 1)
		print += print_char_count(' ', flags->width - 1);
	print += write(1, &c, 1);
	if (flags->minus && flags->width > 1)
		print += print_char_count(' ', flags->width - 1);
	return (print);
}

static int	print_empty_arg(t_flags *flags)
{
	int	print;

	print = NULL_STR_LENGTH;
	if (flags->precision >= 0 && flags->precision < print)
		return (0);
	if (flags->width > print && !flags->minus)
		print += print_char_count(' ', flags->width - print);
	write(1, NULL_STR_PRINT, NULL_STR_LENGTH);
	if (flags->width > print && flags->minus)
		print += print_char_count(' ', flags->width - print);
	return (print);
}

int	print_string(va_list ap, t_flags *flags)
{
	int		len;
	char	*s;
	int		print;

	s = va_arg(ap, char *);
	len = 0;
	print = 0;
	if (!s)
		return (print_empty_arg(flags));
	while (s[len] && flags->precision--)
		len++;
	if (!flags->minus && flags->width > len)
		print += print_char_count(' ', flags->width - len);
	print += write(1, s, len);
	if (flags->minus && flags->width > len)
		print += print_char_count(' ', flags->width - len);
	return (print);
}
