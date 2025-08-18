# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: radandri <radandri@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/08/11 18:42:51 by radandri          #+#    #+#              #
#    Updated: 2025/08/18 14:37:01 by radandri         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = libftprintf.a
LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a

SRCS = ft_printf.c \
       ft_parse_flags.c \
       ft_print_arg.c \
	   ft_print_utils_alphabet.c \
	   ft_print_utils_libft.c \
	   ft_print_utils_numeric.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
# build libft
	$(MAKE) -C $(LIBFT_DIR)
# create the archive libftprint.a
	ar rcs $(NAME) $(OBJS)
# extract libft.o files
	ar -x $(LIBFT)
# add them into libftprint.a archive
	ar rcs $(NAME) *.o
# clean up extracted libft.o files
	rm -f *.o

clean:
	rm -f $(OBJS)
	make -C $(LIBFT_DIR) clean
	
fclean: clean
	rm -f $(NAME)
	make -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
