/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_utils_alphabet.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: radandri <radandri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 13:43:38 by radandri          #+#    #+#             */
/*   Updated: 2025/08/18 23:11:05 by radandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"


/*
25:     TEST(1, print("%c", '0')); should print "0"
26:     TEST(2, print(" %c ", '0')); should print " 0 "
27:     TEST(3, print(" %c", '0' - 256)); should print " 0"
28:     TEST(4, print("%c ", '0' + 256)); should print "0 "
29:     TEST(5, print(" %c %c %c ", '0', 0, '1')); should print " 0  1 "
30:     TEST(6, print(" %c %c %c ", ' ', ' ', ' ')); should print "7spaces" instead
31:     TEST(7, print(" %c %c %c ", '1', '2', '3')); should print " 1 2 3 "
32:     TEST(8, print(" %c %c %c ", '2', '1', 0)); should print " 2 1  "
33:     TEST(9, print(" %c %c %c ", 0, '1', '2')); should print "  1 2 "

*/
int print_char(t_format *fmt, va_list *args)
{
    int i;
    int count;
    char c;

    i = 0;
    count = 0;
    c = (char)va_arg(*args, int);

        if(!fmt->flag_minus)
        {
            while(i < fmt->width - 1) //
            {
                write(1, " ", 1);
                i++;
                count++;
            }
        }

        write(1, &c, 1);
        count++;

        if (fmt->flag_minus)
        {
            i = 0;
            while (i < fmt->width - 1)
            {
                write(1, " ", 1);
                i++;
                count++;
            }
        }
    

        return count;
}

int print_string(t_format *fmt, va_list *args)
{
    (void)fmt; // Unused parameter
    (void)args; // Unused parameter
    return 0;
}
int print_percent(t_format *fmt)
{
    (void)fmt; // Unused parameter
    return 0;
}