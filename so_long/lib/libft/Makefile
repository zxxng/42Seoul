# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jaeyyoo <jaeyyoo@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/27 19:36:16 by jaeyyoo           #+#    #+#              #
#    Updated: 2023/07/27 20:43:33 by jaeyyoo          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc

CFLAGS = -Wall -Wextra -Werror -std=c99

NAME = libft.a

SRCS = ft_memset.c ft_bzero.c ft_memcmp.c ft_split.c \
	ft_printf.c ft_putnbr.c ft_putstr.c \
	get_next_line.c get_next_line_utils.c

OBJ = $(SRCS:.c=.o)

all : $(NAME)

$(NAME) : $(OBJ)
	ar rc $@ $(OBJ)

%.o : %.c
	$(CC) $(CFLAGS) -c $^ -o $@

bonus:
	make WITH_BONUS=1

clean :
	rm -f $(OBJ) $(BOBJ)

fclean : clean
	rm -f $(NAME)

re :
	make fclean
	make all

.PHONY: all clean fclean re bonus