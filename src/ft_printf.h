/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: radandri <radandri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/09 20:20:13 by radandri          #+#    #+#             */
/*   Updated: 2025/08/10 15:09:33 by radandri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#ifndef PRINTF_H
# define PRINTF_H

# include <stddef.h>

void	*ft_memset(void *b, int c, size_t len);
void	*ft_memmove(void *dst, const void *src, size_t len);
int ft_printf(const char *str);

#endif