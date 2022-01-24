/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lesantos <lesantos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 15:49:30 by lesantos          #+#    #+#             */
/*   Updated: 2022/01/23 18:57:00 by lesantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	count_digits(unsigned long n, unsigned int base)
{
	int			count;

	count = 1;
	while (n >= base)
	{
		n /= base;
		count++;
	}
	return (count);
}

unsigned long int	ft_abs(long int n)
{
	if (n < 0)
		return ((unsigned long int) n * -1);
	return ((unsigned long int) n);
}

unsigned long	get_first_digit_divisor(unsigned long int n, unsigned int base)
{
	unsigned long int	power;

	power = 1;
	while (n >= base)
	{
		power *= base;
		n /= base;
	}
	return (power);
}

int	print_char_count(char c, int n)
{
	char	*s;
	int		i;

	if (n <= 0)
		return (0);
	i = 0;
	s = malloc(n);
	while (i < n)
		s[i++] = c;
	write(1, s, n);
	free(s);
	return (n);
}
