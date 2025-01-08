# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sithomas <sithomas@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/12 12:41:53 by sithomas          #+#    #+#              #
#    Updated: 2025/01/08 14:03:54 by sithomas         ###   ########.fr        #
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
	ft_putncount_ptr.c \

OFILES = $(SRC:.c=.o)

NAME = libftprintf.a

all: $(NAME)

$(NAME): $(OFILES)
	@ar rcs $(NAME) $(OFILES)
	@echo 'printf created'

%.o : %.c Makefile ft_printf.h
	@$(CC) $(CFLAGS) -c $< -o $@ 

clean:
	@rm -f $(OFILES)
	@echo 'printf .o files cleaned'

fclean: clean
	@rm -f $(NAME)
	@echo 'printf all cleaned'

re:	fclean all

.PHONY: all clean fclean re
