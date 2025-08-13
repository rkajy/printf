# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: radandri <radandri@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/08/11 18:42:51 by radandri          #+#    #+#              #
#    Updated: 2025/08/11 21:43:22 by radandri         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = libftprintf.a
LIBFT = ../libft/libft.a

SRCS = ft_printf.c \
       ft_memmove.c \
       ft_memset.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(MAKE) -C ../libft
	ar rcs $(NAME) $(OBJS) $(LIBFT)

clean:
	rm -f $(OBJS)
	$(MAKE) -C ../libft clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C ../libft fclean

re: fclean all

.PHONY: all clean fclean re
