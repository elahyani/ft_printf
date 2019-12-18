# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: elahyani <elahyani@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/12/12 21:56:38 by elahyani          #+#    #+#              #
#    Updated: 2019/12/17 00:06:59 by elahyani         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRCS =	ft_printf.c \
		conv_addr.c\
		conv_chr.c\
		conv_hexa.c\
		conv_int.c\
		conv_str.c\
		conv_uns.c\
		conv_percent.c\
		dectohexa.c \
		dectohexa_p.c\
		flag_minus.c\
		flag_prec.c\
		flag_star.c\
		flag_width.c\
		flag_zero.c\
		ft_nblen.c \
		ft_unbr.c\
		ft_putchar.c\
		ft_putnbr.c


SRC_LIB = libft/ft_memset.c libft/ft_bzero.c libft/ft_memcpy.c libft/ft_memccpy.c libft/ft_memmove.c libft/ft_memchr.c \
		libft/ft_memcmp.c libft/ft_strlen.c libft/ft_strlcpy.c libft/ft_strlcat.c libft/ft_strchr.c libft/ft_strrchr.c \
		libft/ft_strnstr.c libft/ft_strncmp.c libft/ft_atoi.c libft/ft_isalpha.c libft/ft_isdigit.c libft/ft_isalnum.c \
		libft/ft_isascii.c libft/ft_isprint.c libft/ft_toupper.c libft/ft_tolower.c libft/ft_calloc.c libft/ft_strdup.c \
		libft/ft_substr.c libft/ft_strjoin.c libft/ft_strtrim.c libft/ft_split.c libft/ft_itoa.c libft/ft_strmapi.c \
		libft/ft_putchar_fd.c libft/ft_putstr_fd.c libft/ft_putendl_fd.c libft/ft_putnbr_fd.c

OBJ_LIB = $(SRC_LIB:.c=.o)

OBJ = $(SRCS:.c=.o)

LINKERFLAG = -Wall -Wextra -Werror -c

all: $(NAME)

$(NAME): $(OBJ) $(OBJ_LIB)
	ar rc $(NAME) $(OBJ) $(OBJ_LIB)
	ranlib $(NAME)

%.o: %.c
	gcc $(LINKERFLAG) $< -o $@

clean:
	rm -f *.o
	rm -f libft/*.o

fclean: clean
		rm -f $(NAME)

re: fclean all