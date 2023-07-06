# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jaeyyoo <jaeyyoo@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/06 12:03:02 by jaeyyoo           #+#    #+#              #
#    Updated: 2023/07/06 17:19:05 by jaeyyoo          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Werror -Wextra 

COMMAND_DIR = ./command/
SORT_DIR = ./sort/

SRCS = $(COMMAND_DIR)command.c $(COMMAND_DIR)swap.c $(COMMAND_DIR)push.c \
	   $(COMMAND_DIR)rotate.c $(COMMAND_DIR)reverse_rotate.c \
	   $(SORT_DIR)bubble_sort.c $(SORT_DIR)sandglass.c \
	   ./main.c ./parse.c ./converter.c
OBJS = $(SRCS:%.c=%.o)

LIB = -L./libft/ -lft
NAME = push_swap

all : $(NAME)

%.o : %.c
	$(CC) $(CFLAGS) -c $^ -o $@

$(NAME) : $(OBJS)
	@make -C ./libft all
	@$(CC) $(CFLAGS) $^ -o $@ $(LIB)

clean :
	@make -C ./libft clean
	rm -rf $(OBJS)

fclean : clean
	@make -C ./libft fclean
	rm -rf $(NAME)

re :
	make fclean
	make all

.PHONY: all clean fclean re