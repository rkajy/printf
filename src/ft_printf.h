/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: radandri <radandri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 21:37:42 by radandri          #+#    #+#             */
/*   Updated: 2025/08/15 11:45:47 by radandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stddef.h>
# include <stdarg.h>

typedef struct s_format {
	int flag_minus;
	int flag_plus;
	int flag_space;
	int flag_zero;
	int flag_hash;
	int width;
	int precision;
	int length;
} t_format;


int     ft_printf(const char *format, ...);
int print_arg(t_fornat *fmt, va_list *args);
int print_char(t_format *fmt, va_list *args);
int print_string(t_format *fmt, va_list *args);
int print_integer(t_format *fmt, va_list *args);
int print_unsigned(t_format *fmt, va_list *args);
int print_hexadecimal(t_format *fmt, va_list *args);
int print_pointer(t_format *fmt, va_list *args);
int print_percent(t_format *fmt);
int parse_format(const char **format, t_format *fmt);
int parse_flags(const char **format, t_format *fmt);

#endif // FT_PRINTF_H