/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 21:37:42 by radandri          #+#    #+#             */
/*   Updated: 2025/08/20 19:36:06 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h> // va_list, va_start, va_end
# include <stddef.h> // size_t
# include <stdlib.h> // malloc, free
# include <unistd.h> // write

typedef struct s_format
{
	int		flag_minus;
	int		flag_plus;
	int		flag_space;
	int		flag_zero;
	int		flag_hash;
	char	type;
	int		width;
	int		precision;
}			t_format;

// Function prototypes for ft_printf
int			ft_printf(const char *format, ...);
int			print_arg_fd(int fd, t_format *fmt, va_list *args);
int			print_arg(t_format *fmt, va_list *args);
int			print_char(t_format *fmt, va_list *args);
int			print_string(t_format *fmt, va_list *args);
int			print_integer(t_format *fmt, va_list *args);
int			print_unsigned(t_format *fmt, va_list *args);
int			print_hexadecimal(t_format *fmt, va_list *args);
int			print_pointer(t_format *fmt, va_list *args);
int			print_percent(t_format *fmt);
const char	*parse_flags(const char *format, t_format *fmt);

#endif // FT_PRINTF_H
