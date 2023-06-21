# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: laroges <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/03 07:20:37 by laroges           #+#    #+#              #
#    Updated: 2023/06/21 20:23:27 by laroges          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC =	gcc

CFLAGS = -Wall -Werror -Wextra

SRC =	ft_browse_format.c \
	ft_dash.c \
	ft_init.c \
	ft_intlen.c \
	ft_justify.c \
	ft_len_ft_printf.c \
	ft_print_char.c \
	ft_printf.c \
	ft_printx.c \
	ft_print_int.c \
	ft_print_percent.c \
	ft_precision.c \
	ft_print_ptr.c \
	ft_print_str.c \
	ft_print_uint.c \
	ft_putchar.c \
	ft_putstr.c \
	ft_search_flags.c \
	ft_sub_len_ft_printf.c \
	ft_sub_print_int.c \
	ft_sub_print_str.c \
	ft_width.c \

OBJ =	$(SRC:.c=.o)

NAME =	libftprintf.a

NAMELIBFT = libft.a

INCLUDES = ./libft/

all: $(NAME)

%.o : %.c
	$(CC) $(CFLAGS) -I $(INCLUDES) -c $< -o $(<:.c=.o)

$(NAME): $(OBJ)
	make -C libft
	cp ./libft/libft.a .
	mv libft.a $(NAME)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

clean:
	make clean -C libft
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

so:
	cc -nostartfiles -fPIC $(CFLAGS) $(SRC) $(B_SRC)
	gcc -nostartfiles -shared -o libft.so $(OBJ) $(BONUS_OBJ)

.PHONY:	all bonus clean fclean re
