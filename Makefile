# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sithomas <sithomas@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/12 12:41:53 by sithomas          #+#    #+#              #
#    Updated: 2024/11/21 17:49:27 by sithomas         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc

CFLAGS = -Wall -Wextra -Werror -Ilibft

SRC = ft_printf.c \
	ft_putncount_nbr.c \
	ft_putncount_unsigned_nbr.c \
	ft_putncount_char.c \
	ft_putncount_nbr_hex.c \
	ft_putncount_str.c \
	ft_putncount_ptr.c

TEST = main.c

OFILES = $(SRC:.c=.o)

OTEST = $(TEST:.c=.o)

NAME = libftprintf.a

all: libft/libft.a $(NAME)

libft/libft.a:
	$(MAKE) -C libft

$(NAME): $(OFILES)
	ar rcs $(NAME) $(OFILES)

test : $(OFILES) $(OTEST)
	$(CC) $(CFLAGS) $(OFILES) $(OTEST) -o test.out

%.o : %.c libft/libft.a Makefile
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(MAKE) -C libft clean
	rm -f $(OFILES) $(OBONUS)

fclean: clean
	rm -f $(NAME)

re:	fclean all

.PHONY: all clean fclean re
