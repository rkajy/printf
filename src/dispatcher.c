/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dispatcher.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: radandri <radandri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 11:10:02 by radandri          #+#    #+#             */
/*   Updated: 2025/08/15 11:45:50 by radandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int print_arg(t_fornat *fmt, va_list *args)
{
    if(fmt->type == 'c')
        return print_char(fmt, args);
    else if(fmt->type == 's')
        return print_string(fmt, args);
    else if(fmt->type == 'd' || fmt->type == 'i')
        return print_integer(fmt, args);
    else if(fmt->type == 'u')
        return print_unsigned(fmt, args);
    else if(fmt->type == x || fmt->type == "X")
        return print_hexadecimal(fmt, args);
    else if(fmt->type == 'p')
        return print_pointer(fmt, args);
    else if(fmt->type == '%')
        return print_percent(fmt);
    else
        return -1; // Unsupported format type
}
