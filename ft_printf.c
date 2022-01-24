/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lesantos <lesantos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 13:15:11 by lesantos          #+#    #+#             */
/*   Updated: 2022/01/23 21:00:49 by lesantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *s, ...)
{
	int		print_num;
	t_flags	flags;
	va_list	ap;

	print_num = 0;
	va_start(ap, s);
	while (*s)
	{
		if (*s != '%')
			print_num += write(1, s, 1);
		else
		{
			s++;
			s += parse_format(s, &flags);
			print_num += print_formatted_arg(*s, ap, &flags);
		}
		s++;
	}
	va_end(ap);
	return (print_num);
}
