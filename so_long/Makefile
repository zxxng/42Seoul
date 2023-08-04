# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jaeyyoo <jaeyyoo@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/27 19:18:17 by jaeyyoo           #+#    #+#              #
#    Updated: 2023/08/03 17:59:18 by jaeyyoo          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
DEBUG = -g3 -fsanitize=address
CFLAGS = -Wall -Wextra -Werror #$(DEBUG)
INC = -I include

NAME = so_long

RM= rm -rf

SRCS =	main.c key_event.c move.c \
		valid_checker.c window.c

OBJS = $(SRCS:.c=.o)

all : $(NAME)

$(NAME) : $(OBJS)
	@make -C ./lib/libft all
	@make -C ./lib/mlx all
	$(CC) $(CFLAGS) -o $@ $^ -L ./lib/libft -lft \
	-L ./lib/mlx -lmlx -framework OpenGL -framework AppKit

%.o : %.c
	$(CC) $(CFLAGS) -o $@ -c $^ $(INC)

clean:
	@make -C ./lib/libft clean
	@make -C ./lib/mlx clean
	$(RM) $(OBJS)

fclean: clean
	@make -C ./lib/libft fclean
	$(RM) $(NAME)

re:
	make fclean
	make all

.PHONY: all clean fclean re
