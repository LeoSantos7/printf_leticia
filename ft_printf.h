/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lesantos <lesantos@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 15:53:33 by lesantos          #+#    #+#             */
/*   Updated: 2022/01/23 15:08:44 by lesantos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

#define PADDING_LEFT 1
#define PADDING_RIGHT 0

#define BASE_10 10
#define BASE_16 16

# if __APPLE__
#  define NULL_PTR_PRINT "0x0"
#  define NULL_PTR_LENGTH 3
# else
#  define NULL_PTR_PRINT "(nil)"
#  define NULL_PTR_LENGTH 5
# endif
# define NULL_STR_PRINT "(null)"
# define NULL_STR_LENGTH 6

typedef struct s_flags
{
	int		space;
	int		minus;
	int		plus;
	int		alternate;
	int		zero;
	int		width;
	int		precision;
	char	type;
}	t_flags;
int	ft_printf(const char *format, ...);
int	print_formatted_arg(char c, va_list ap, t_flags *flags);
int	parse_format(const char *s, t_flags *flags);
int	print_char_count(char c, int n);
int	print_char(va_list ap, t_flags *flags);
int	print_string(va_list ap, t_flags *flags);
int	print_pointer(unsigned long n, t_flags *flags);
int	count_digits(unsigned long n, unsigned int base);
int	print_decimal(long int n, t_flags *flags);
int	print_decimal_digits(long int n, t_flags *flags);
int	print_hex(unsigned long n, t_flags *flags);
int	print_hex_digits(unsigned long n, t_flags *flags);
unsigned long int ft_abs(long int n);
unsigned long get_first_digit_divisor(unsigned long int n, unsigned int base);
int	print_spaces(t_flags *flags, int left_side);
int	print_prefix(long int n, t_flags *flags);
int	print_zeroes(t_flags *flags);
#endif
