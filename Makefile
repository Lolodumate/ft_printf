# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: laroges <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/03 07:20:37 by laroges           #+#    #+#              #
#    Updated: 2023/06/17 18:53:00 by laroges          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC =	gcc

CFLAGS = -Wall -Werror -Wextra

SRC =	ft_atoi.c \
	ft_calloc.c \
	ft_isalpha.c \
	ft_isdigit.c \
	ft_isalnum.c \
	ft_isascii.c \
	ft_isprint.c \
	ft_itoa.c \
	ft_strdup.c \
	ft_memset.c \
	ft_bzero.c \
	ft_memcmp.c \
	ft_memcpy.c \
	ft_memmove.c \
	ft_putchar_fd.c \
	ft_putendl_fd.c \
	ft_putnbr_fd.c \
	ft_putstr_fd.c \
	ft_strlen.c \
	ft_strlcpy.c \
	ft_strlcat.c \
	ft_strnstr.c \
	ft_strtrim.c \
	ft_toupper.c \
	ft_tolower.c \
	ft_split.c \
	ft_strchr.c \
	ft_striteri.c \
	ft_strjoin.c \
	ft_strmapi.c \
	ft_strncmp.c \
	ft_strrchr.c \
	ft_substr.c \
	ft_memchr.c \
	ft_dash.c \
	ft_init.c \
	ft_intlen.c \
	ft_justify.c \
	ft_len_ft_printf.c \
	ft_print_char.c \
	ft_printf.c \
	ft_print_hexa.c \
	ft_print_int.c \
	ft_print_percent.c \
	ft_precision.c \
	ft_print_ptr.c \
	ft_print_str.c \
	ft_print_uint.c \
	ft_putchar.c \
	ft_putstr.c \
	ft_width.c \

B_SRC =	ft_lstnew.c \
	ft_lstadd_front.c \
	ft_lstsize.c \
	ft_lstlast.c \
	ft_lstadd_back.c \
	ft_lstdelone.c \
	ft_lstclear.c \
	ft_lstiter.c \
	ft_lstmap.c \

OBJ =	$(SRC:.c=.o)

BONUS_OBJ =	$(B_SRC:.c=.o)

NAME =	libftprintf.a

all: $(NAME)

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

bonus: $(BONUS_OBJ)
	ar rcs $(NAME) $(BONUS_OBJ)
	ranlib $(NAME) 

clean:
	rm -f $(OBJ) $(BONUS_OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

so:
	cc -nostartfiles -fPIC $(CFLAGS) $(SRC) $(B_SRC)
	gcc -nostartfiles -shared -o libft.so $(OBJ) $(BONUS_OBJ)

.PHONY:	all bonus clean fclean re
