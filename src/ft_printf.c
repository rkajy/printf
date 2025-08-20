/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/09 20:26:42 by radandri          #+#    #+#             */
/*   Updated: 2025/08/20 19:37:22 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>
#include <unistd.h>

int	ft_vdprintf(int fd, const char *format, va_list *args)
{
	t_format	fmt;
	int			count;
	const char	*ptr = format;

	count = 0;
	while (*ptr)
	{
		if (*ptr == '%')
		{
			ptr++;
			fmt = (t_format){0, 0, 0, 0, 0, 0, 0, 0};
			ptr = parse_flags(ptr, &fmt);
			if (*ptr)
				fmt.type = *ptr++;
			count += print_arg_fd(fd, &fmt, args);
		}
		else
		{
			write(fd, ptr, 1);
			count++;
			ptr++;
		}
	}
	return (count);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		ret;

	va_start(args, format);
	ret = ft_vdprintf(1, format, &args);
	va_end(args);
	return (ret);
}

// #include <stdio.h>

// int	main(void)
// {
// 	ft_printf("%c", '0');
// 	ft_printf(" %c ", '0');
// 	ft_printf(" %c", '0' - 256);
// 	ft_printf("%c ", '0' + 256);
// 	ft_printf(" %c %c %c ", '0', 0, '1');
// 	ft_printf(" %c %c %c ", ' ', ' ', ' ');
// 	ft_printf(" %c %c %c ", '1', '2', '3');
// 	ft_printf(" %c %c %c ", '2', '1', 0);
// 	printf("\n Testing with printf:\n");
// 	printf("%c", '0');
// 	printf(" %c ", '0');
// 	printf(" %c", '0' - 256);
// 	printf("%c ", '0' + 256);
// 	printf(" %c %c %c ", '0', 0, '1');
// 	printf(" %c %c %c ", ' ', ' ', ' ');
// 	printf(" %c %c %c ", '1', '2', '3');
// 	printf(" %c %c %c ", '2', '1', 0);
// 	return (0);
// }
