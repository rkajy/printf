/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: radandri <radandri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 21:37:42 by radandri          #+#    #+#             */
/*   Updated: 2025/08/18 19:36:11 by radandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stddef.h> // size_t
# include <stdarg.h> // va_list, va_start, va_end
# include <stdlib.h> // malloc, free
# include <unistd.h> // write

typedef struct s_format {
	int flag_minus; // Left alignment, eg ft_printf("%-d", 42) should print "42 ", ft_printf("%-d", -42) should print "-42 ", ft_printf("%-5d", 42) should print "42   ", ft_printf("%-5d", -42) should print "-42  "
	int flag_plus; // Force sign for positive numbers, eg ft_printf("%+d", 42) should print "+42", ft_printf("%+d", -42) should print "-42"
	int flag_space; // Space before positive numbers, eg ft_printf("% d", 42) should print " 42", ft_printf("% d", -42) should print "-42"
	int flag_zero; // Zero padding, eg ft_printf("%05d", 42) should print "00042", ft_printf("%05d", -42) should print "-0042"
	int flag_hash; // Alternate form for hexadecimal and octal, eg ft_printf("%#x", 255) should print "0xff"
	char type; // Format specifier (c, s, d, i, u, x, X, p, %)
	int width; // Minimum field width, eg ft_printf("%10d", 42) should print "        42", ft_printf("%-10d", 42) should print "42        ", ft_printf("%5s", "Hello") should print "Hello", ft_printf("%-5s", "Hello") should print "Hello"
	int precision; // Precision for floating-point numbers or string truncation, eg ft_printf("%.2f", 3.14159) should print "3.14", ft_printf("%.5s", "Hello") should print "Hello", 
	// ft_printf("%10s", "Hi") should print "        Hi", ft_printf("%-10s", "Hi") should print "Hi        "
	// ft_printf("%5d", 42) should print "   42", ft_printf("%-5d", 42) should print "42   ", ft_printf("%05d", 42) should print "00042"
	// ft_printf("%5.2f", 3.14159) should print " 3.14", ft_printf("%-5.2f", 3.14159) should print "3.14 "
	// ft_printf("%5.2s", "Hello") should print "He   ", ft_printf("%-5.2s", "Hello") should print "He   "
	// ft_printf("%5c", 'A') should print "    A", ft_printf("%-5c", 'A') should print "A    "
	// ft_printf("%.5d", 42) should print "00042", ft_printf("%.5d", -42) should print "-0042"
	// ft_printf(".0d", 0) should print "", ft_printf(".0d", 42) should print "42", ft_printf(".0d", -42) should print "-42"
	// ft_print("%.3s", "Hello") should print "Hel", ft_printf("%.3s", NULL) should print "(null)"
	// ft_printf("%.0s", "Hello") should print "", ft_printf("%.0s", NULL) should print ""
} t_format;

// Function prototypes for ft_printf
int     ft_printf(const char *format, ...);
int print_arg_fd(int fd, t_format *fmt, va_list *args);
int print_arg(t_format *fmt, va_list *args);
int print_char(t_format *fmt, va_list *args);
int print_string(t_format *fmt, va_list *args);
int print_integer(t_format *fmt, va_list *args);
int print_unsigned(t_format *fmt, va_list *args);
int print_hexadecimal(t_format *fmt, va_list *args);
int print_pointer(t_format *fmt, va_list *args);
int print_percent(t_format *fmt);
const char *parse_flags(const char *format, t_format *fmt);

#endif // FT_PRINTF_H