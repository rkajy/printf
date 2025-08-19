/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: radandri <radandri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/09 20:26:42 by radandri          #+#    #+#             */
/*   Updated: 2025/08/18 19:25:49 by radandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>
#include <stdarg.h>

int ft_vdprintf(int fd, const char *format, va_list args)
{
    t_format fmt;
    int count = 0;
    const char *ptr = format;

    while (*ptr)
    {
        if (*ptr == '%')
        {
            ptr++;
            fmt = (t_format){0, 0, 0, 0, 0, 0, 0, 0}; 
            ptr = parse_flags(ptr, &fmt);
            if (*ptr)
                fmt.type = *ptr++;
            count += print_arg_fd(fd, &fmt, &args); 
        }
        else
        {
            write(fd, ptr, 1);
            count++;
            ptr++;
        }
    }
    return count;
}

int ft_printf(const char *format, ...)
{
    va_list args;
    int ret;

    va_start(args, format);
    ret = ft_vdprintf(1, format, args); // stdout
    va_end(args);
    return ret;
}

// int main(void)
// {
//     // Test cases
//     ft_printf("Hello, World!\n");
//     ft_printf("This is a test: %d\n", 42);
//     ft_printf("Character: %c\n", 'A');
//     ft_printf("String: %s\n", "Test string");
//     ft_printf("Percentage: %%\n");

//     return 0;
// }
