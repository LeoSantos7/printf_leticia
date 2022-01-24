/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_formatted_arg.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lesantos <lesantos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 13:10:02 by lesantos          #+#    #+#             */
/*   Updated: 2022/01/23 15:09:35 by lesantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_formatted_arg(char type, va_list ap, t_flags *flags)
{
	flags->type = type;
	if (type == '%')
		return (write(1, "%", 1));
	if (type == 'c')
		return (print_char(ap, flags));
	if (type == 's')
		return (print_string(ap, flags));
	if (type == 'd' || type == 'i')
		return (print_decimal(va_arg(ap, int), flags));
	if (type == 'u')
		return (print_decimal(va_arg(ap, unsigned int), flags));
	if (type == 'x' || type == 'X')
		return (print_hex(va_arg(ap, unsigned int), flags));
	if (type == 'p')
		return (print_pointer(va_arg(ap, unsigned long), flags));
	return (0);
}
