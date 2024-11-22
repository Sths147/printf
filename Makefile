# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sithomas <sithomas@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/12 12:41:53 by sithomas          #+#    #+#              #
#    Updated: 2024/11/22 17:08:31 by sithomas         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc

CFLAGS = -Wall -Wextra -Werror

SRC = ft_printf.c \
	ft_putncount_nbr.c \
	ft_putncount_unsigned_nbr.c \
	ft_putncount_char.c \
	ft_putncount_nbr_hex.c \
	ft_putncount_str.c \
	ft_putncount_ptr.c

OFILES = $(SRC:.c=.o)

NAME = libftprintf.a

all: libft/libft.a $(NAME)

libft/libft.a:
	$(MAKE) -C libft

$(NAME): $(OFILES)
	ar rcs $(NAME) $(OFILES)

%.o : %.c libft/libft.a Makefile ft_printf.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(MAKE) -C libft fclean
	rm -f $(OFILES) $(OBONUS)

fclean: clean
	rm -f $(NAME)

re:	fclean all

.PHONY: all clean fclean re
