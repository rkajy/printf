/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_arg.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: radandri <radandri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 11:10:02 by radandri          #+#    #+#             */
/*   Updated: 2025/08/17 16:06:40 by radandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int print_arg(t_format *fmt, va_list *args)
{
    if(fmt->type == 'c')
        print_char(fmt, args);
    else if(fmt->type == 's')
        print_string(fmt, args);
    else if(fmt->type == 'd' || fmt->type == 'i')
        print_integer(fmt, args);
    else if(fmt->type == 'u')
        print_unsigned(fmt, args);
    else if(fmt->type == 'x' || fmt->type == 'X')
        print_hexadecimal(fmt, args);
    else if(fmt->type == 'p')
        print_pointer(fmt, args);
    else if(fmt->type == '%')
        print_percent(fmt);
    else
        return -1; // Unsupported format type
    return 0; // Successfully printed the argument
}
