# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jaeyyoo <jaeyyoo@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/10 14:26:51 by jaeyyoo           #+#    #+#              #
#    Updated: 2023/05/29 19:57:12 by jaeyyoo          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc

CFLAGS = -Wall -Wextra -Werror

NAME = libft.a

SRCS = ft_printf.c ft_putnbr.c ft_putstr.c ft_atoi.c

OBJ = $(SRCS:.c=.o)

all : $(NAME)

$(NAME) : $(OBJ)
	ar rc $@ $^

clean :
	rm -f $(OBJ)

fclean :
	make clean
	rm -f $(NAME)

re :
	make fclean
	make all

.PHONY : all claen fclaen re
