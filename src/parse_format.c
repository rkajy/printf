/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_format.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: radandri <radandri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 19:35:56 by radandri          #+#    #+#             */
/*   Updated: 2025/08/13 19:46:50 by radandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

const char *parse_flags(const char *format, t_format *fmt)
{
    while (*format)
    {
        if (*format == '-')
            fmt->flag_minus = 1;
        else if (*format == '+')
            fmt->flag_plus = 1;
        else if (*format == ' ')
            fmt->flag_space = 1;
        else if (*format == '0')
            fmt->flag_zero = 1;
        else if (*format == '#')
            fmt->flag_hash = 1;
        else
            break;
        format++;
    }
    return format;
}
