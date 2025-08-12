/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: radandri <radandri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/09 20:20:13 by radandri          #+#    #+#             */
/*   Updated: 2025/08/11 21:37:42 by radandri         ###   ########.fr       */
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

void    *ft_memset(void *b, int c, size_t len);
void    *ft_memmove(void *dst, const void *src, size_t len);
int     ft_printf(const char *format, ...);

#endif // FT_PRINTF_H