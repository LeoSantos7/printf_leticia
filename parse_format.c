/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_format.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lesantos <lesantos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 09:54:55 by lesantos          #+#    #+#             */
/*   Updated: 2022/01/23 12:09:33 by lesantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	parse_flags(const char *s, t_flags *flags)
{
	int	i;

	i = 0;
	while (1)
	{
		if (s[i] == '-')
			flags->minus = 1;
		else if (s[i] == '+')
			flags->plus = 1;
		else if (s[i] == '#')
			flags->alternate = 1;
		else if (s[i] == '0')
			flags->zero = 1;
		else if (s[i] == ' ')
			flags->space = 1;
		else
			break ;
		i++;
	}
	return (i);
}

int	parse_width(const char *s, t_flags *flags)
{
	int	i;

	i = 0;
	while (s[i] >= '0' && s[i] <= '9')
	{
		flags->width *= 10;
		flags->width += s[i] - '0';
		i++;
	}
	return (i);
}

int	parse_precision(const char *s, t_flags *flags)
{
	int	i;

	i = 0;
	if (*s == '.')
	{
		flags->precision = 0;
		i++;
		while (s[i] >= '0' && s[i] <= '9')
		{
			flags->precision *= 10;
			flags->precision += s[i] - '0';
			i++;
		}
	}
	return (i);
}

void	init_flags(t_flags *flags)
{
	flags->zero = 0;
	flags->plus = 0;
	flags->minus = 0;
	flags->space = 0;
	flags->alternate = 0;
	flags->precision = -1;
	flags->width = 0;
}

int	parse_format(const char *s, t_flags *flags)
{
	int	r;

	init_flags(flags);
	r = 0;
	r += parse_flags(s, flags);
	r += parse_width(s + r, flags);
	r += parse_precision(s + r, flags);
	if (flags->precision >= 0)
		flags->zero = 0;
	return (r);
}
